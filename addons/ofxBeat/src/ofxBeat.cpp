//
//  ofxBeat.cpp
//  Cyril
//
//  Created by Darren Mothersele on 20/11/2013.
//
//

#include "ofxBeat.h"

ofxBeat::ofxBeat() : buffer_size(1024), fft_size(512) {
  bandTimes[KICK_BAND] = 0;
  bandTimes[SNARE_BAND] = 0;
  bandTimes[HIHAT_BAND] = 0;
  beatSizes[KICK_BAND] = 0;
  beatSizes[SNARE_BAND] = 0;
  beatSizes[HIHAT_BAND] = 0;
  
  int fft_size=512;
  int buffer_size = 1024;
  for(int i = 0; i < fft_size; i++)
    fftSmoothed[i] = 0;
  
  for(int i = 0; i < FFT_SUBBANDS; i++)
  {
    for(int l = 0; l < ENERGY_HISTORY; l++){
      energyHistory[i][l] = 0;
    }
    fftSubbands[i] = 0;
    averageEnergy[i] = 0;
    fftVariance[i] = 0;
    beatValueArray[i] = 0;
  }
  
  audio_input = new float[buffer_size];
  magnitude = new float[fft_size];
  phase = new float[fft_size];
  power = new float[fft_size];
  magnitude_average = new float[fft_size];
  magnitude_average_snapshot = new float[fft_size];
  
  for (int i = 0; i < fft_size; i++) {
    magnitude[i] = 0;
    phase[i] = 0;
    power[i] = 0;
    magnitude_average_snapshot[i] = 0;
    magnitude_average[i] = 0;
  }
  
  historyPos = 0;
  fftInit = true;
  beatValue = 1.08;
  enableBeatDetect();
}


void ofxBeat::updateFFT() {
  if(fftInit) {
    in_fft = magnitude;
    for (int i = 0; i < fft_size; i++) {
      if (fftSmoothed[i] < in_fft[i]) {
        fftSmoothed[i] = in_fft[i];
      }
      fftSmoothed[i] *= 0.90f;
    }
    
    if(bDetectBeat) {
      for(int i = 0; i < FFT_SUBBANDS; i++) {
        fftSubbands[i] = 0;
        
        for(int b = 0; b < fft_size/FFT_SUBBANDS; b++) {
          fftSubbands[i] +=  in_fft[i*(fft_size/FFT_SUBBANDS)+b];
        }
        fftSubbands[i] = fftSubbands[i]*(float)FFT_SUBBANDS/(float)fft_size;
        
        for(int b=0; b < fft_size/FFT_SUBBANDS; b++) {
          fftVariance[i] += pow(in_fft[i*(fft_size/FFT_SUBBANDS)+b] - fftSubbands[i], 2);
        }
        fftVariance[i] = fftVariance[i]*(float)FFT_SUBBANDS/(float)fft_size;
        
        
        beatValueArray[i] = (-0.0025714*fftVariance[i])+1.35;
      }
      
      
      for(int i = 0; i < FFT_SUBBANDS; i++) {
        averageEnergy[i] = 0;
        for(int h = 0; h < ENERGY_HISTORY; h++) {
          
          averageEnergy[i] += energyHistory[i][h];
        }
        
        averageEnergy[i] /= ENERGY_HISTORY;
      }
      
      
      for(int i = 0; i < FFT_SUBBANDS; i++) {
        
        energyHistory[i][historyPos] = fftSubbands[i];
      }
      
      historyPos = (historyPos+1) % ENERGY_HISTORY;
      
    }
  }
}


float ofxBeat::getMagnitude() {
  return * magnitude;
}
float ofxBeat::getBand(int i) {
  return fftSubbands[i];
}

float ofxBeat::kick() {
  return beats[KICK_BAND];
}
float ofxBeat::snare() {
  return beats[SNARE_BAND];
}
float ofxBeat::hihat() {
  return beats[HIHAT_BAND];
}

void ofxBeat::updateBand(bool a, int b, int t) {
  if (a) {
    beats[b] = 1;
    beatSizes[b] = t - bandTimes[b];
    bandTimes[b] = t;
  }
  else {
    int span = t - bandTimes[b];
    if (span < beatSizes[b] && beatSizes[b] > 0) {
      beats[b] = ofMap(span, 0, beatSizes[b], 1, 0);
    }
    else {
      beats[b] = 0;
    }
  }
}

int ofxBeat::getBufferSize() {
  return buffer_size;
}

void ofxBeat::update(int _t) {
  updateFFT();
  updateBand(isKick(), KICK_BAND, _t);
  updateBand(isSnare(), SNARE_BAND, _t);
  updateBand(isHat(), HIHAT_BAND, _t);
}

void ofxBeat::audioReceived(float* input, int bufferSize, int nChannels) {
  memcpy(audio_input, input, sizeof(float) * bufferSize);
  float avg_power = 0.0f;
  myfft.powerSpectrum(0, (int)fft_size, audio_input, buffer_size, magnitude, phase, power, &avg_power);
  
  for (int i = 0; i < fft_size; i++) {
    magnitude[i] = powf(magnitude[i], 0.5);
  }
  
  for (int i = 0; i < fft_size; i++) {
    float x = 0.085;
    magnitude_average[i] = (magnitude[i] * x) + (magnitude_average[i] * (1 - x));
  }
}

bool ofxBeat::isBeat(int subband)
{
  return fftSubbands[subband] > averageEnergy[subband]*beatValueArray[subband];
}

bool ofxBeat::isKick()
{
  return isBeat(0);
}

bool ofxBeat::isSnare()
{
  int low = 1;
  int hi = FFT_SUBBANDS/3;
  int thresh = (hi-low)/3;
  return isBeatRange(low, hi, thresh);
}

bool ofxBeat::isHat()
{
  int low = FFT_SUBBANDS/2;
  int hi = FFT_SUBBANDS-1;
  int thresh = (hi-low)/3;
  return isBeatRange(low, hi, thresh);
}

bool ofxBeat::isBeatRange(int low, int high, int threshold)
{
  int num = 0;
  for(int i = low; i < high+1; i++) {
    if(isBeat(i)) {
      num++;
    }
  }
  return num > threshold;
}

