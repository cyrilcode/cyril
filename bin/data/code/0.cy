ballDetail 0.1
fill 
color pink,200
DECAY: 0.03
rotate FRAME / 10,0,0,1
do 16 times
particle 0.1,0,0,0.01 * wave(1000)
 color HEALTH * 255,100,0,200
 ball 0.5 * (1 - HEALTH)
end
rotate 22.5
end


