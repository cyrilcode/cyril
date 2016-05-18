
#ifndef _FFT
#define _FFT

#ifndef M_PI
#define	M_PI		3.14159265358979323846  /* pi */
#endif


class fft {
	
	public:
		
	fft();
	~fft();	
	
	/* Calculate the power spectrum */
	void powerSpectrum(int start, int half, float *data, int windowSize,float *magnitude,float *phase, float *power, float *avg_power);
	/* ... the inverse */
	void inversePowerSpectrum(int start, int half, int windowSize, float *finalOut,float *magnitude,float *phase);	
	

};


#endif	
