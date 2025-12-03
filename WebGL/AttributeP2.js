const vertexShaderSource= `#version 300 es 
#pragma vscode_glsllint_stage: vert

layout(location=0) in vec4 aPosition;
layout(location=1) in float aPointSize;
layout(location=2) in vec4 aColor;

out vec4 vColor;

void main() 
{
    vColor = aColor;
    gl_PointSize = aPointSize; 
    gl_Position = aPosition;
}`;

const fragmentShaderSource = `#version 300 es
#pragma vscode_glsllint_stage: frag 

precision mediump float; // must apply precision for fragment to compile floats

in vec4 vColor;

out vec4 fragColor; 

void main() 
{
    fragColor = vColor;
}`;

const gl = document.querySelector('canvas').getContext('webgl2');

const program = gl.createProgram();

const vertexShader = gl.createShader(gl.VERTEX_SHADER);
gl.shaderSource(vertexShader, vertexShaderSource);
gl.compileShader(vertexShader);
gl.attachShader(program, vertexShader);

const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
gl.shaderSource(fragmentShader, fragmentShaderSource);
gl.compileShader(fragmentShader);
gl.attachShader(program, fragmentShader);

gl.linkProgram(program);

if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
    console.log(gl.getShaderInfoLog(vertexShader));
    console.log(gl.getShaderInfoLog(fragmentShader));
}

gl.useProgram(program);

const uPositionLoc = 0;
const uPointSizeLoc = 1;
const uColorLoc = 2;

gl.vertexAttrib4f(uPositionLoc, 0, 0, 0, 1);
gl.vertexAttrib1f(uPointSizeLoc, 50);
gl.vertexAttrib4f(uColorLoc, 1,0,0,1);

gl.drawArrays(gl.POINTS, 0, 1000);

