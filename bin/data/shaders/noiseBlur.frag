
uniform float iGlobalTime;
uniform vec3 iResolution;

void main( void )
{
  float r = gl_FragCoord.x / iResolution.x;
  float g = gl_FragCoord.y / iResolution.y;
  float b = 1.0;
  float a = 1.0;
  gl_FragColor = vec4(r, g, b, a);
}
