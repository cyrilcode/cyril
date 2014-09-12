//move (wave(1000) * 10) - 5
palette $p2
 50 red
 50 yellow
end

j: 0.5 * wave(1000)
i: 0 - j

tile 12,8
 f: f + 0.1
 color lerp($p2, noise(f))
 rotate wave(500) * 360,0,1,0
 shape 
  vert i,i
  vert i,j
  vert j,j
  vert j,i
 end
end
