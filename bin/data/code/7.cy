//rotate FRAME / 2,0,1,0
//scale 0.2
//move -16
// for i: 0 to 32 step 1
// box 1,fft(i)*10,1
// move 1,0
//end
DECAY: 0.01
rotate wave(1000) * 36,0,0,1
do 8 times
 rotate 45
 f: 3
 blink 1,10
  particle 0.05 * fft(f),0,0,0
   color hotPink, HEALTH * 255
   box 1, HEALTH * 10, 1
  end
 end
end






