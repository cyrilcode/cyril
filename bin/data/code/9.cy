
palette $f
50 red
25 orange
25 yellow
end
sphereDetail 2
DECAY: 0.01
do 10 times
rotate FRAME / 10

push
i: i + 0.1
x: noise(i)
y: noise(i,0.1)

move 1 + x * 0.5,1 + y * 0.5
rotate 90,0,-1,0
particle 0.04,-0.0001,0.0005,0
color lerp($f, HEALTH - 0.001), (HEALTH * 100) + 100
sphere 0.1 
end
pop
end


