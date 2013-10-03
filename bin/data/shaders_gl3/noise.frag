#version 150

uniform sampler2D src_tex_unit0;
uniform vec4 globalColor;

in vec2 texCoordVarying;
uniform vec2 mouse;

out vec4 fragColor;

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}


void main(){
	float xVal = gl_FragCoord.x;
	float yVal = gl_FragCoord.y;

	if( mod(xVal, 2.0) == 0.5 ){
        if( 1.0-yVal/500 > mouse[1] ) {
            fragColor = vec4(hsv2rgb(vec3(mouse[0],1.0,1.0)),1.0);
        } else {
            fragColor = vec4(hsv2rgb(vec3(1.0-mouse[0],1.0,1.0)),1.0);
        }
    } else {
        discard;
	}
}
