

rotate TIME / 4

do 8 times
rotate FRAME
particle 0.01,wave(1000) * 0.05,wave(500) * 0.05,0
rotate HEALTH * 360,0,-1,0
color lerp(#ff0000,#ff00ff,HEALTH),175
do 2 times
rotate
shape
 vert 0,0
 vert 0.45,0.75
 vert -0.45,0.75
 vert 0,0
end
end
end
end


