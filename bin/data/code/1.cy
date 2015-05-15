light 0,-10,10

//rotate
//stroke
fill
DECAY: 0.1
ballDetail 0.1
color hotPink,255
i: i + 0.01
for x: -20 to 25 step 4
for y: -10 to 14 step 4
push
 move x,y,-1
 rotate 270,0,1,0
 rotate (1 - noise(i)) * 360
 particle 0,noise(x,y,i) * 0.5,noise(y,x,i) * 0.3,0
//  color hsb(100,255,255),HEALTH
  rotate
  box 0.2, 1, 2
 end
pop
end
end


//fxB 2
