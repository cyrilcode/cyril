color white
DECAY: 0.01
i: i + 0.09
j: j + 0.009
//blink 1,5
 x: rand(10) - 5 
 y: rand(6) - 3
 a: rand(360)
 x: (noise(i) * 10) - 5
 y: (noise(j) * 6) - 3
//end
move x, y
rotate a
color red
box 0.3
particle 0.005,0,0,wave(50) * 0.025
 fill
 color white, HEALTH * 255
 box 0.2 
end

