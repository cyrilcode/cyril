color white
fill
i: 0
move -7.5,0
do 2 times
move 5,0
if i = 1 
 rotate 175
end
//scale 0.5
if KICK 
 do 7 times
  rotate 45
  particle 0.5,0,0,wave(1000) * 0.15
   box 1 - HEALTH
  end 
 end
end
i: 1
rotate 45
end