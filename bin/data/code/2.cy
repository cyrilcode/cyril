palette $p
 10 yellow
 10 red
end
do 10 times
if KICK 
 i: i + 0.1
end
x: (noise(i) * 10) - 5
move x, 0 
color lerp($p, (x + 5) / 10)
box 1,10,0
end
