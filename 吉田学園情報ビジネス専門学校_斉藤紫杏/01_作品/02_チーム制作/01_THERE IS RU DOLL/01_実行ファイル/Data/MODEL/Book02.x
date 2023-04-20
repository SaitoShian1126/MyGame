xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 334;
 -21.83091;19.53884;26.31573;,
 23.11520;19.53884;26.31573;,
 23.11520;21.84341;26.31573;,
 -21.83091;21.84341;26.31573;,
 -23.11520;17.80293;26.31573;,
 -23.11520;16.32447;26.31573;,
 23.11520;19.53884;-26.31573;,
 -21.83091;19.53884;-26.31573;,
 -21.83091;21.84341;-26.31573;,
 23.11520;21.84341;-26.31573;,
 -23.11520;16.32447;-26.31573;,
 -23.11520;17.80293;-26.31573;,
 23.11519;1.64098;26.31573;,
 -21.83091;1.64098;26.31573;,
 -21.83091;-0.69977;26.31573;,
 23.11520;-0.69977;26.31573;,
 -23.11520;5.31985;26.31573;,
 -23.11520;3.34072;26.31573;,
 23.11520;1.64098;-26.31573;,
 23.11520;-0.69977;-26.31573;,
 -21.83091;-0.69977;-26.31573;,
 -21.83091;1.64098;-26.31573;,
 -23.11520;3.34072;-26.31573;,
 -23.11520;5.31985;-26.31573;,
 -21.83091;19.53884;24.76839;,
 22.02914;19.53884;25.54207;,
 22.02913;1.64098;25.54207;,
 -21.83091;1.64098;24.76839;,
 -21.83091;1.64098;-24.76839;,
 22.02914;1.64098;-25.54207;,
 22.02914;19.53884;-25.54207;,
 -21.83091;19.53884;-24.76839;,
 -20.57784;15.92779;24.76839;,
 21.14031;15.92779;25.54207;,
 -21.83091;15.92779;26.31573;,
 -23.46591;14.10418;26.31573;,
 21.14031;15.92779;-25.54207;,
 -21.18250;15.92779;-24.76839;,
 -21.83091;15.92779;-26.31573;,
 -23.46591;14.10418;-26.31573;,
 21.14031;4.25959;25.54207;,
 -20.57784;4.25959;24.76839;,
 -21.83091;4.25959;26.31573;,
 21.14031;4.25959;-25.54207;,
 -21.18250;4.25959;-24.76839;,
 -23.46592;6.92993;26.31573;,
 -21.83091;4.25959;-26.31573;,
 -23.46592;6.92993;-26.31573;,
 -21.83091;21.84341;20.07281;,
 -23.11519;17.80293;20.07281;,
 -23.11520;17.80293;26.31573;,
 -21.83091;21.84341;26.31573;,
 23.11520;21.84341;26.31573;,
 23.11520;21.84341;20.07281;,
 -23.11519;17.80293;20.07281;,
 -23.11520;16.32447;20.07281;,
 -23.11520;16.32447;26.31573;,
 23.11520;21.84341;20.07281;,
 23.11520;19.53884;26.31573;,
 23.11520;19.53884;20.07281;,
 -23.46591;14.10418;20.07281;,
 -23.46591;14.10418;26.31573;,
 -23.46592;6.92993;20.07281;,
 -23.46592;6.92993;26.31573;,
 22.02914;19.53884;25.54207;,
 21.14031;15.92779;25.54207;,
 21.14031;15.92779;19.48268;,
 21.14031;15.92779;18.09646;,
 22.02914;19.53884;18.09646;,
 -23.11520;5.31985;20.07281;,
 -23.11520;5.31985;26.31573;,
 21.14031;4.25959;25.54207;,
 21.14031;4.25959;19.48268;,
 21.14031;4.25959;18.09646;,
 -23.11520;3.34072;20.07281;,
 -23.11520;3.34072;26.31573;,
 22.02913;1.64098;25.54207;,
 23.11519;1.64098;20.07281;,
 22.02913;1.64098;18.09646;,
 -23.11520;3.34072;20.07281;,
 -21.83091;-0.69977;20.07281;,
 -21.83091;-0.69977;26.31573;,
 23.11520;-0.69977;20.07281;,
 23.11520;-0.69977;26.31573;,
 23.11519;1.64098;26.31573;,
 23.11520;-0.69977;20.07281;,
 -21.83091;21.84341;-19.39892;,
 -23.11520;17.80293;-19.39892;,
 -23.11519;17.80293;20.07281;,
 -21.83091;21.84341;20.07281;,
 23.11520;21.84341;20.07281;,
 23.11520;21.84341;-19.39892;,
 -23.11520;17.80293;-19.39892;,
 -23.11520;16.32447;-19.39892;,
 -23.11520;16.32447;20.07281;,
 -23.11519;17.80293;20.07281;,
 23.11520;21.84341;-19.39892;,
 23.11520;21.84341;20.07281;,
 23.11520;19.53884;20.07281;,
 23.11520;19.53884;-19.39892;,
 23.11520;19.53884;-20.30627;,
 23.11520;21.84341;-20.30627;,
 -23.46591;14.10418;-19.39892;,
 -23.46591;14.10418;20.07281;,
 22.02914;19.53884;-18.82859;,
 22.02914;19.53884;-19.70928;,
 -23.46592;6.92993;-19.39892;,
 -23.46592;6.92993;20.07281;,
 21.14031;15.92779;-18.82859;,
 21.14031;15.92779;-19.70928;,
 -23.11520;5.31985;-19.39892;,
 -23.11520;5.31985;20.07281;,
 21.14031;4.25959;-18.82859;,
 21.14031;4.25959;-19.70928;,
 -23.11520;3.34072;-19.39892;,
 -23.11520;3.34072;20.07281;,
 22.02914;1.64098;-18.82859;,
 22.02914;1.64098;-19.70928;,
 -23.11520;3.34072;-19.39892;,
 -21.83091;-0.69977;-19.39892;,
 -21.83091;-0.69977;20.07281;,
 -23.11520;3.34072;20.07281;,
 23.11519;1.64098;20.07281;,
 23.11520;1.64098;-19.39892;,
 23.11520;1.64098;-20.30627;,
 23.11520;-0.69977;-19.39892;,
 23.11520;-0.69977;20.07281;,
 23.11520;-0.69977;20.07281;,
 23.11520;-0.69977;-19.39892;,
 23.11520;-0.69977;-20.30627;,
 -21.83091;21.84341;-23.67033;,
 -21.83091;21.84341;-26.31573;,
 -23.11520;17.80293;-26.31573;,
 -23.11520;17.80293;-23.67033;,
 23.11520;21.84341;-23.67033;,
 23.11520;21.84341;-26.31573;,
 -23.11520;17.80293;-23.67033;,
 -23.11520;17.80293;-26.31573;,
 -23.11520;16.32447;-26.31573;,
 -23.11520;16.32447;-23.67033;,
 23.11520;21.84341;-23.67033;,
 23.11520;19.53884;-23.67033;,
 23.11520;19.53884;-26.31573;,
 23.11520;21.84341;-26.31573;,
 -23.46591;14.10418;-26.31573;,
 -23.46591;14.10418;-23.67033;,
 22.02914;19.53884;-22.97442;,
 22.02914;19.53884;-25.54207;,
 -23.46592;6.92993;-26.31573;,
 -23.46592;6.92993;-23.67033;,
 21.14031;15.92779;-22.97442;,
 21.14031;15.92779;-25.54207;,
 -23.11520;5.31985;-26.31573;,
 -23.11520;5.31985;-23.67033;,
 21.14031;4.25959;-22.97442;,
 21.14031;4.25959;-25.54207;,
 -23.11520;3.34072;-26.31573;,
 -23.11520;3.34072;-23.67033;,
 22.02914;1.64098;-22.97442;,
 22.02914;1.64098;-25.54207;,
 -23.11520;3.34072;-23.67033;,
 -23.11520;3.34072;-26.31573;,
 -21.83091;-0.69977;-26.31573;,
 -21.83091;-0.69977;-23.67033;,
 23.11520;1.64098;-23.67033;,
 23.11520;1.64098;-26.31573;,
 23.11520;-0.69977;-26.31573;,
 23.11520;-0.69977;-23.67033;,
 23.11520;-0.69977;-23.67033;,
 23.11520;-0.69977;-26.31573;,
 -21.83091;21.84341;-22.62888;,
 -23.11520;17.80293;-22.62888;,
 -23.11520;17.80293;-20.30627;,
 -21.83091;21.84341;-20.30627;,
 23.11520;21.84341;-20.30627;,
 23.11520;21.84341;-22.62888;,
 -23.11520;17.80293;-22.62888;,
 -23.11520;16.32447;-22.62888;,
 -23.11520;16.32447;-20.30627;,
 -23.11520;17.80293;-20.30627;,
 23.11520;21.84341;-22.62888;,
 23.11520;19.53884;-22.62888;,
 -23.46591;14.10418;-22.62888;,
 -23.46591;14.10418;-20.30627;,
 22.02914;19.53884;-21.96359;,
 -23.46592;6.92993;-22.62888;,
 -23.46592;6.92993;-20.30627;,
 21.14031;15.92779;-21.96359;,
 -23.11520;5.31985;-22.62888;,
 -23.11520;5.31985;-20.30627;,
 21.14031;4.25959;-21.96359;,
 -23.11520;3.34072;-22.62888;,
 -23.11520;3.34072;-20.30627;,
 22.02914;1.64098;-21.96359;,
 -23.11520;3.34072;-22.62888;,
 -21.83091;-0.69977;-22.62888;,
 -21.83091;-0.69977;-20.30627;,
 -23.11520;3.34072;-20.30627;,
 23.11520;1.64098;-22.62888;,
 23.11520;-0.69977;-22.62888;,
 23.11520;-0.69977;-20.30627;,
 23.11520;-0.69977;-22.62888;,
 -22.95224;18.21954;-20.30627;,
 -22.95224;18.21954;-19.39892;,
 -23.21401;16.32447;-20.30627;,
 -22.95224;18.21954;-20.30627;,
 -22.95224;18.21954;-19.39892;,
 -23.21401;16.32447;-19.39892;,
 -23.44663;14.10418;-20.30627;,
 -23.44663;14.10418;-19.39892;,
 -23.44663;6.92993;-20.30627;,
 -23.44663;6.92993;-19.39892;,
 -23.21401;5.31985;-20.30627;,
 -23.21401;5.31985;-19.39892;,
 -22.95224;2.92411;-20.30627;,
 -22.95224;2.92411;-19.39892;,
 -22.95224;2.92411;-19.39892;,
 -22.95224;2.92411;-20.30627;,
 -22.95224;18.21954;-23.67033;,
 -22.95224;18.21954;-22.62888;,
 -23.21401;16.32447;-23.67033;,
 -22.95224;18.21954;-23.67033;,
 -22.95224;18.21954;-22.62888;,
 -23.21401;16.32447;-22.62888;,
 -23.44663;14.10418;-23.67033;,
 -23.44663;14.10418;-22.62888;,
 -23.44663;6.92993;-23.67033;,
 -23.44663;6.92993;-22.62888;,
 -23.21401;5.31985;-23.67033;,
 -23.21401;5.31985;-22.62888;,
 -22.95224;2.92411;-23.67033;,
 -22.95224;2.92411;-22.62888;,
 -22.95224;2.92411;-22.62888;,
 -22.95224;2.92411;-23.67033;,
 -22.95224;18.21954;-20.30627;,
 -22.95224;18.21954;-19.39892;,
 -22.95224;2.92411;-20.30627;,
 -22.95224;2.92411;-19.39892;,
 -22.95224;18.21954;-23.67033;,
 -22.95224;18.21954;-22.62888;,
 -22.95224;2.92411;-23.67033;,
 -22.95224;2.92411;-22.62888;,
 -20.05815;22.28028;26.31151;,
 -20.05815;22.22252;-14.45244;,
 -20.05815;21.98985;-14.45244;,
 -20.05815;22.05228;26.26513;,
 -18.44689;22.28028;26.31151;,
 -18.44689;22.05228;26.26513;,
 -18.44689;21.98985;-14.45244;,
 -18.44689;22.22252;-14.45244;,
 -20.05815;21.54663;26.96078;,
 -20.05815;21.33641;26.86111;,
 -18.44689;21.54663;26.96078;,
 -18.44689;21.33641;26.86111;,
 -20.05815;19.63272;27.15676;,
 -20.05815;19.56566;26.93397;,
 -18.44689;19.63272;27.15676;,
 -18.44689;19.56566;26.93397;,
 -18.37337;16.21227;26.76233;,
 -18.37636;16.22225;26.99476;,
 -19.57894;12.63922;26.69255;,
 -19.58115;12.62905;26.46012;,
 -19.98284;16.28467;26.73854;,
 -20.95373;13.47264;26.43633;,
 -20.95151;13.48282;26.66875;,
 -19.98583;16.29465;26.97097;,
 -22.01075;11.09884;23.97676;,
 -22.00948;11.10466;24.10971;,
 -20.95151;13.48282;26.66875;,
 -20.95373;13.47264;26.43633;,
 -21.22437;10.62212;24.12333;,
 -21.22564;10.61630;23.99039;,
 -19.58115;12.62905;26.46012;,
 -19.57894;12.63922;26.69255;,
 -19.81633;22.22252;-14.91799;,
 -19.81633;21.98985;-14.91799;,
 -20.05815;21.98985;-14.45244;,
 -20.05815;22.22252;-14.45244;,
 -19.81633;22.22252;-14.91799;,
 -20.05815;22.22252;-14.45244;,
 -20.05815;22.28028;26.31151;,
 -19.81633;22.28028;26.31151;,
 -19.81633;21.98985;-14.91799;,
 -19.81633;22.05228;26.26513;,
 -20.05815;22.05228;26.26513;,
 -20.05815;21.98985;-14.45244;,
 -20.05815;21.54663;26.96078;,
 -19.81633;21.54663;26.96078;,
 -19.81633;21.33640;26.86111;,
 -20.05815;21.33641;26.86111;,
 -20.05815;19.63272;27.15676;,
 -19.81633;19.63272;27.15676;,
 -19.81633;19.56566;26.93397;,
 -20.05815;19.56566;26.93397;,
 -19.98583;16.29465;26.97097;,
 -19.74427;16.28378;26.97454;,
 -19.74128;16.27380;26.74211;,
 -19.98284;16.28467;26.73854;,
 -20.74550;13.35621;26.67232;,
 -20.74773;13.34603;26.43990;,
 -20.74550;13.35621;26.67232;,
 -21.89165;11.03224;24.11175;,
 -20.74773;13.34603;26.43990;,
 -21.89292;11.02642;23.97881;,
 -18.58856;22.22252;-14.91799;,
 -18.44689;22.22252;-14.45244;,
 -18.44689;21.98985;-14.45244;,
 -18.58856;21.98985;-14.91799;,
 -18.58856;22.22252;-14.91799;,
 -18.58856;22.28028;26.31151;,
 -18.44689;22.28028;26.31151;,
 -18.44689;22.22252;-14.45244;,
 -18.58856;21.98985;-14.91799;,
 -18.44689;21.98985;-14.45244;,
 -18.44689;22.05228;26.26513;,
 -18.58856;22.05228;26.26513;,
 -18.58856;21.54663;26.96078;,
 -18.44689;21.54663;26.96078;,
 -18.44689;21.33641;26.86111;,
 -18.58856;21.33641;26.86111;,
 -18.58856;19.63272;27.15676;,
 -18.44689;19.63272;27.15676;,
 -18.44689;19.56566;26.93397;,
 -18.58856;19.56566;26.93397;,
 -18.51788;16.22862;26.99267;,
 -18.37636;16.22225;26.99476;,
 -18.37337;16.21227;26.76233;,
 -18.51489;16.21864;26.76024;,
 -19.69962;12.71340;26.69046;,
 -19.70184;12.70323;26.45803;,
 -19.69962;12.71340;26.69046;,
 -21.29340;10.66455;24.12213;,
 -19.70184;12.70323;26.45803;,
 -21.29467;10.65873;23.98919;;
 
 211;
 4;0,1,2,3;,
 4;0,3,4,5;,
 4;6,7,8,9;,
 4;10,11,8,7;,
 4;12,13,14,15;,
 4;13,16,17,14;,
 4;18,19,20,21;,
 4;21,20,22,23;,
 4;24,25,1,0;,
 4;26,27,13,12;,
 4;28,29,18,21;,
 4;30,31,7,6;,
 4;32,33,25,24;,
 4;32,24,0,34;,
 4;34,0,5,35;,
 4;36,37,31,30;,
 4;37,38,7,31;,
 4;39,10,7,38;,
 4;40,33,32,41;,
 4;40,41,27,26;,
 4;41,32,34,42;,
 4;41,42,13,27;,
 4;43,29,28,44;,
 4;43,44,37,36;,
 4;42,34,35,45;,
 4;42,45,16,13;,
 4;44,28,21,46;,
 4;44,46,38,37;,
 4;46,21,23,47;,
 4;46,47,39,38;,
 4;48,49,50,51;,
 4;48,51,52,53;,
 4;54,55,56,50;,
 4;57,52,58,59;,
 4;55,60,61,56;,
 4;60,62,63,61;,
 4;59,64,65,66;,
 4;59,66,67,68;,
 4;62,69,70,63;,
 4;66,65,71,72;,
 4;66,72,73,67;,
 4;69,74,75,70;,
 4;72,71,76,77;,
 4;72,77,78,73;,
 4;79,80,81,75;,
 4;80,82,83,81;,
 4;77,84,83,85;,
 4;86,87,88,89;,
 4;86,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;96,99,100,101;,
 4;93,102,103,94;,
 4;99,98,68,104;,
 4;99,104,105,100;,
 4;102,106,107,103;,
 4;104,68,67,108;,
 4;104,108,109,105;,
 4;106,110,111,107;,
 4;108,67,73,112;,
 4;108,112,113,109;,
 4;110,114,115,111;,
 4;112,73,78,116;,
 4;112,116,117,113;,
 4;118,119,120,121;,
 4;116,78,122,123;,
 4;116,123,124,117;,
 4;119,125,126,120;,
 4;123,122,127,128;,
 4;123,128,129,124;,
 4;130,131,132,133;,
 4;130,134,135,131;,
 4;136,137,138,139;,
 4;140,141,142,143;,
 4;139,138,144,145;,
 4;141,146,147,142;,
 4;145,144,148,149;,
 4;146,150,151,147;,
 4;149,148,152,153;,
 4;150,154,155,151;,
 4;153,152,156,157;,
 4;154,158,159,155;,
 4;160,161,162,163;,
 4;158,164,165,159;,
 4;163,162,166,167;,
 4;164,168,169,165;,
 4;170,171,172,173;,
 4;170,173,174,175;,
 4;176,177,178,179;,
 4;180,101,100,181;,
 4;180,181,141,140;,
 4;177,182,183,178;,
 4;181,100,105,184;,
 4;181,184,146,141;,
 4;182,185,186,183;,
 4;184,105,109,187;,
 4;184,187,150,146;,
 4;185,188,189,186;,
 4;187,109,113,190;,
 4;187,190,154,150;,
 4;188,191,192,189;,
 4;190,113,117,193;,
 4;190,193,158,154;,
 4;194,195,196,197;,
 4;193,117,124,198;,
 4;193,198,164,158;,
 4;195,199,200,196;,
 4;198,124,129,201;,
 4;198,201,168,164;,
 4;86,173,202,203;,
 4;86,91,174,173;,
 4;204,205,179,178;,
 4;206,207,93,92;,
 4;206,205,204,207;,
 4;208,204,178,183;,
 4;207,209,102,93;,
 4;207,204,208,209;,
 4;210,208,183,186;,
 4;209,211,106,102;,
 4;209,208,210,211;,
 4;212,210,186,189;,
 4;211,213,110,106;,
 4;211,210,212,213;,
 4;214,212,189,192;,
 4;213,215,114,110;,
 4;213,212,214,215;,
 4;216,217,196,119;,
 4;119,196,200,125;,
 4;170,130,218,219;,
 4;170,175,134,130;,
 4;220,221,136,139;,
 4;222,223,177,176;,
 4;222,221,220,223;,
 4;224,220,139,145;,
 4;223,225,182,177;,
 4;223,220,224,225;,
 4;226,224,145,149;,
 4;225,227,185,182;,
 4;225,224,226,227;,
 4;228,226,149,153;,
 4;227,229,188,185;,
 4;227,226,228,229;,
 4;230,228,153,157;,
 4;229,231,191,188;,
 4;229,228,230,231;,
 4;232,233,163,195;,
 4;195,163,167,199;,
 3;234,173,172;,
 3;86,235,87;,
 3;196,236,197;,
 3;237,119,118;,
 3;238,130,133;,
 3;170,239,171;,
 3;163,240,160;,
 3;241,195,194;,
 3;77,76,84;,
 3;59,58,64;,
 4;242,243,244,245;,
 4;246,247,248,249;,
 4;250,242,245,251;,
 4;252,253,247,246;,
 4;254,250,251,255;,
 4;256,257,253,252;,
 4;258,257,256,259;,
 4;258,259,260,261;,
 4;262,263,264,265;,
 4;262,265,254,255;,
 4;266,267,268,269;,
 4;270,271,272,273;,
 4;274,275,276,277;,
 4;278,279,280,281;,
 4;282,283,284,285;,
 4;281,280,286,287;,
 4;283,288,289,284;,
 4;287,286,290,291;,
 4;288,292,293,289;,
 4;291,290,294,295;,
 4;292,296,297,293;,
 4;295,294,264,298;,
 4;296,299,263,297;,
 4;300,268,267,301;,
 4;302,303,266,269;,
 4;301,267,266,303;,
 4;304,305,306,307;,
 4;304,307,275,274;,
 4;308,278,281,309;,
 4;308,309,310,311;,
 4;312,313,314,315;,
 4;312,315,283,282;,
 4;309,281,287,316;,
 4;309,316,317,310;,
 4;315,314,318,319;,
 4;315,319,288,283;,
 4;316,287,291,320;,
 4;316,320,321,317;,
 4;319,318,322,323;,
 4;319,323,292,288;,
 4;320,291,295,324;,
 4;320,324,325,321;,
 4;323,322,326,327;,
 4;323,327,296,292;,
 4;324,295,298,328;,
 4;324,328,260,325;,
 4;327,326,261,329;,
 4;327,329,299,296;,
 4;330,300,301,331;,
 4;330,331,270,273;,
 4;332,272,271,333;,
 4;332,333,303,302;,
 4;331,301,303,333;,
 4;331,333,271,270;;
 
 MeshMaterialList {
  4;
  211;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  2,
  1,
  2,
  2,
  1,
  1,
  2,
  2,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  1,
  2,
  1,
  1,
  2,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  0,
  2,
  1,
  1,
  2,
  1,
  1,
  2,
  1,
  1,
  2,
  2,
  0,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  1,
  2,
  1,
  2,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  2,
  0,
  0,
  2,
  1,
  1,
  2,
  1,
  1,
  2,
  1,
  1,
  2,
  0,
  0,
  2,
  2,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.680000;0.616250;0.249900;1.000000;;
   10.000000;
   0.530000;0.530000;0.530000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.649600;0.615200;0.574400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.037600;0.269600;0.091200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.627200;0.197600;0.235200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  162;
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;0.000000;,
  0.271116;-0.000285;0.962547;,
  -0.018316;-0.000389;0.999832;,
  0.871393;0.070806;0.485449;,
  -0.018117;0.000265;-0.999836;,
  0.955341;0.042044;-0.292499;,
  -0.018316;0.000536;0.999832;,
  0.492395;-0.054955;0.868635;,
  -0.018117;-0.000365;-0.999836;,
  0.870497;-0.095616;0.482796;,
  0.954734;-0.057502;-0.291851;,
  -0.953016;0.302920;-0.000000;,
  -0.988184;0.153273;-0.000000;,
  -0.996934;0.078253;-0.000000;,
  0.984287;-0.173182;-0.034465;,
  -0.996934;0.078252;0.000000;,
  0.953168;-0.279225;-0.116210;,
  -0.994255;-0.107033;0.000000;,
  0.988314;-0.140729;-0.058570;,
  -0.994255;-0.107033;0.000000;,
  0.980500;0.188483;-0.055622;,
  -0.988184;-0.153271;0.000000;,
  0.922174;0.370960;-0.109471;,
  -0.953016;-0.302921;0.000000;,
  0.973128;0.228044;-0.031890;,
  0.973129;0.228043;-0.031890;,
  -0.954171;0.299263;0.000000;,
  -0.988184;0.153272;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.996934;0.078251;0.000000;,
  -0.996934;0.078252;0.000000;,
  -0.994255;-0.107033;0.000000;,
  0.992728;-0.120379;-0.000000;,
  -0.994255;-0.107033;0.000000;,
  0.986645;0.162884;0.000000;,
  0.946938;0.321417;0.000000;,
  -0.954171;-0.299263;0.000000;,
  -0.954171;0.299263;0.000000;,
  -0.988184;0.153273;0.000000;,
  -0.996934;0.078253;0.000000;,
  -0.996934;0.078252;0.000000;,
  0.986645;0.162883;0.000000;,
  0.946938;0.321416;0.000000;,
  -0.954171;0.299263;0.000000;,
  -0.988184;0.153272;0.000000;,
  -0.996934;0.078251;0.000000;,
  -0.994255;-0.107033;0.000000;,
  -0.994255;-0.107033;0.000000;,
  -0.988184;-0.153271;0.000000;,
  -0.954171;-0.299263;0.000000;,
  -0.954171;0.299263;0.000000;,
  0.992728;-0.120379;-0.000000;,
  -0.976186;0.216936;0.000000;,
  0.000000;0.000000;0.000000;,
  -0.018090;-0.000778;0.999836;,
  0.935502;0.139161;0.324762;,
  -0.017957;0.000530;-0.999839;,
  0.977216;0.083597;-0.195091;,
  -0.018090;0.001073;0.999836;,
  0.929623;-0.187472;0.317264;,
  -0.017957;-0.000730;-0.999838;,
  0.974460;-0.114239;-0.193330;,
  -0.988184;0.153273;-0.000001;,
  -0.953016;0.302920;-0.000001;,
  -0.996934;0.078253;-0.000000;,
  0.927276;-0.361889;0.095894;,
  0.981651;-0.184327;0.048843;,
  0.969361;0.240811;0.048477;,
  0.879320;0.466865;0.093982;,
  1.000000;0.000004;0.000000;,
  1.000000;0.000003;0.000000;,
  0.971018;-0.239008;-0.000000;,
  1.000000;0.000001;0.000000;,
  -0.953016;0.302921;0.000000;,
  0.971018;-0.239008;-0.000000;,
  0.986645;0.162884;0.000000;,
  0.946938;0.321417;0.000000;,
  -0.953016;-0.302921;0.000000;,
  0.971018;-0.239008;-0.000000;,
  -0.992709;0.120532;0.000000;,
  -0.998638;0.052171;0.000000;,
  -0.997428;-0.071680;0.000000;,
  -0.992053;-0.125824;0.000000;,
  -0.979171;-0.203037;0.000000;,
  -0.998638;0.052171;0.000000;,
  -0.997428;-0.071680;0.000000;,
  -0.979171;-0.203037;0.000000;,
  -0.971448;0.000000;-0.237250;,
  0.989112;0.000000;-0.147165;,
  0.869950;-0.492789;0.018614;,
  -0.928379;0.371420;-0.012632;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.999938;-0.011067;-0.001320;,
  0.999943;0.010572;0.001407;,
  0.988387;-0.151673;0.009274;,
  -0.987885;0.154905;-0.009343;,
  0.761376;-0.647967;0.021105;,
  -0.909797;0.414946;-0.009484;,
  -0.887425;0.000000;-0.460953;,
  -0.000370;0.912080;0.410013;,
  0.000400;-0.905810;-0.423684;,
  0.000000;0.401587;0.915821;,
  -0.000003;-0.359461;-0.933160;,
  -0.004284;0.024370;0.999694;,
  0.004317;0.008008;-0.999959;,
  -0.025810;-0.069052;0.997279;,
  0.025831;0.070932;-0.997147;,
  -0.223622;-0.361044;0.905340;,
  0.219190;0.353627;-0.909343;,
  -0.484161;-0.776375;0.403521;,
  0.371075;0.583360;-0.722492;,
  0.956685;0.000000;-0.291126;,
  0.000631;0.912080;0.410013;,
  -0.000687;-0.905810;-0.423683;,
  0.000001;-0.359462;-0.933160;,
  -0.004243;0.026162;0.999649;,
  0.004277;0.006166;-0.999972;,
  -0.024350;-0.062821;0.997728;,
  0.024375;0.064659;-0.997610;,
  -0.222490;-0.356904;0.907258;,
  0.218036;0.349485;-0.911219;,
  -0.484183;-0.776362;0.403521;,
  0.371075;0.583355;-0.722496;,
  -0.000674;0.999999;-0.001405;,
  -0.001349;0.999998;-0.001409;,
  -0.000740;0.912080;0.410011;,
  0.000730;-0.999999;0.001520;,
  0.000798;-0.905811;-0.423682;,
  0.001459;-0.999998;0.001525;,
  -0.000008;-0.359461;-0.933160;,
  -0.004318;0.023438;0.999716;,
  0.004352;0.008964;-0.999950;,
  -0.026193;-0.072496;0.997025;,
  0.026215;0.074398;-0.996884;,
  -0.223800;-0.363413;0.904347;,
  0.219387;0.355995;-0.908371;,
  -0.484157;-0.776378;0.403521;,
  0.371083;0.583356;-0.722491;,
  -0.523687;-0.850863;0.042250;,
  -0.523685;-0.850864;0.042251;,
  0.000000;0.000000;-1.000000;,
  0.001151;0.999998;-0.001405;,
  0.001263;0.912080;0.410011;,
  0.002302;0.999996;-0.001409;,
  -0.001245;-0.999998;0.001520;,
  -0.002491;-0.999996;0.001525;,
  -0.001376;-0.905811;-0.423681;,
  0.000000;-0.359463;-0.933159;,
  -0.004238;0.027024;0.999626;,
  0.004272;0.005281;-0.999977;,
  -0.023274;-0.060034;0.997925;,
  0.023302;0.061853;-0.997813;,
  -0.221537;-0.355135;0.908185;,
  0.217077;0.347714;-0.912125;,
  -0.484199;-0.776352;0.403521;,
  0.371084;0.583347;-0.722497;,
  -0.523697;-0.850856;0.042250;,
  -0.523712;-0.850847;0.042249;;
  211;
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;4,5,57,57;,
  4;58,58,58,6;,
  4;1,1,1,1;,
  4;7,7,59,59;,
  4;8,8,60,60;,
  4;0,0,0,0;,
  4;9,5,4,10;,
  4;9,10,61,61;,
  4;10,4,6,12;,
  4;10,12,62,62;,
  4;11,63,63,11;,
  4;11,11,7,7;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;13,64,64,13;,
  4;13,13,8,8;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;14,15,65,66;,
  4;3,3,3,3;,
  4;15,16,67,65;,
  4;31,31,31,17;,
  4;16,18,18,67;,
  4;18,20,49,18;,
  4;17,68,69,17;,
  4;17,17,21,19;,
  4;20,22,50,49;,
  4;17,69,70,28;,
  4;17,28,23,21;,
  4;22,24,24,50;,
  4;28,70,71,27;,
  4;28,27,25,23;,
  4;24,26,26,24;,
  4;2,2,2,2;,
  4;27,72,72,73;,
  4;40,41,15,14;,
  4;3,3,3,3;,
  4;41,42,16,15;,
  4;31,31,17,31;,
  4;31,31,31,31;,
  4;42,43,18,16;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;43,34,20,18;,
  4;74,19,21,35;,
  4;74,35,35,74;,
  4;34,36,22,20;,
  4;35,21,23,44;,
  4;35,44,37,35;,
  4;36,24,24,22;,
  4;44,23,25,45;,
  4;44,45,38,37;,
  4;24,39,26,24;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;75,27,73,75;,
  4;75,75,31,31;,
  4;46,76,47,47;,
  4;3,3,3,3;,
  4;47,47,48,48;,
  4;31,31,31,31;,
  4;48,48,18,18;,
  4;2,2,2,2;,
  4;18,18,49,49;,
  4;74,35,35,77;,
  4;49,49,50,50;,
  4;35,37,78,35;,
  4;50,50,51,51;,
  4;37,38,79,78;,
  4;51,51,80,52;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;31,31,31,31;,
  4;53,30,30,29;,
  4;3,3,3,3;,
  4;30,32,32,30;,
  4;31,31,31,31;,
  4;31,31,31,31;,
  4;32,33,33,32;,
  4;2,2,2,2;,
  4;2,2,2,2;,
  4;33,34,34,33;,
  4;81,74,35,54;,
  4;81,54,35,74;,
  4;34,36,36,34;,
  4;54,35,37,37;,
  4;54,37,37,35;,
  4;36,24,24,36;,
  4;37,37,38,38;,
  4;37,38,38,37;,
  4;24,52,39,24;,
  4;3,3,3,3;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;31,31,31,31;,
  4;31,31,31,31;,
  4;40,29,55,55;,
  4;3,3,3,3;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;55,55,82,82;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;82,82,83,83;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;83,83,84,84;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;84,84,85,85;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;85,85,86,86;,
  4;86,86,39,39;,
  4;2,2,2,2;,
  4;53,46,55,55;,
  4;3,3,3,3;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;55,55,82,82;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;82,82,87,87;,
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;87,87,88,88;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;88,88,85,85;,
  4;56,56,56,56;,
  4;56,56,56,56;,
  4;85,85,89,89;,
  4;89,89,52,52;,
  4;2,2,2,2;,
  3;1,1,1;,
  3;0,0,0;,
  3;1,1,1;,
  3;0,0,0;,
  3;1,1,1;,
  3;0,0,0;,
  3;1,1,1;,
  3;0,0,0;,
  3;3,3,3;,
  3;2,2,2;,
  4;94,90,90,94;,
  4;95,95,91,91;,
  4;94,94,94,94;,
  4;95,95,95,95;,
  4;96,94,94,96;,
  4;97,97,95,95;,
  4;98,97,97,98;,
  4;98,98,92,92;,
  4;99,93,93,99;,
  4;99,99,96,96;,
  4;101,101,93,93;,
  4;100,100,92,92;,
  4;102,102,90,90;,
  4;127,128,129,103;,
  4;130,104,131,132;,
  4;103,129,105,105;,
  4;104,106,133,131;,
  4;105,105,134,107;,
  4;106,108,135,133;,
  4;107,134,136,109;,
  4;108,110,137,135;,
  4;109,136,138,111;,
  4;110,112,139,137;,
  4;111,138,140,113;,
  4;112,114,141,139;,
  4;113,140,142,143;,
  4;115,91,91,115;,
  4;144,144,144,144;,
  4;145,127,103,116;,
  4;145,116,146,147;,
  4;148,149,150,117;,
  4;148,117,104,130;,
  4;116,103,105,105;,
  4;116,105,105,146;,
  4;117,150,151,118;,
  4;117,118,106,104;,
  4;105,105,107,119;,
  4;105,119,152,105;,
  4;118,151,153,120;,
  4;118,120,108,106;,
  4;119,107,109,121;,
  4;119,121,154,152;,
  4;120,153,155,122;,
  4;120,122,110,108;,
  4;121,109,111,123;,
  4;121,123,156,154;,
  4;122,155,157,124;,
  4;122,124,112,110;,
  4;123,111,113,125;,
  4;123,125,158,156;,
  4;124,157,159,126;,
  4;124,126,114,112;,
  4;125,113,143,160;,
  4;125,160,161,158;;
 }
 MeshTextureCoords {
  334;
  0.972220;0.102230;,
  0.000000;0.102230;,
  0.000000;0.000000;,
  0.972220;0.000000;,
  1.000000;0.000000;,
  1.000000;0.102230;,
  1.000000;0.102230;,
  0.027780;0.102230;,
  0.027780;0.000000;,
  1.000000;0.000000;,
  0.000000;0.102230;,
  0.000000;0.000000;,
  0.000000;0.863150;,
  0.972220;0.863150;,
  0.972220;1.000000;,
  0.000000;1.000000;,
  1.000000;0.863150;,
  1.000000;1.000000;,
  1.000000;0.863150;,
  1.000000;1.000000;,
  0.027780;1.000000;,
  0.027780;0.863150;,
  0.000000;1.000000;,
  0.000000;0.863150;,
  0.972220;0.102230;,
  0.000000;0.102230;,
  0.000000;0.863150;,
  0.972220;0.863150;,
  0.027780;0.863150;,
  1.000000;0.863150;,
  1.000000;0.102230;,
  0.027780;0.102230;,
  0.972220;0.255750;,
  0.000000;0.255750;,
  0.972220;0.255750;,
  1.000000;0.255750;,
  1.000000;0.255750;,
  0.027780;0.255750;,
  0.027780;0.255750;,
  0.000000;0.255750;,
  0.000000;0.751820;,
  0.972220;0.751820;,
  0.972220;0.751820;,
  1.000000;0.751820;,
  0.027780;0.751820;,
  1.000000;0.751820;,
  0.027780;0.751820;,
  0.000000;0.751820;,
  0.027780;0.118620;,
  0.000000;0.118620;,
  0.000000;0.000000;,
  0.027780;0.000000;,
  1.000000;0.000000;,
  1.000000;0.118620;,
  0.118620;0.000000;,
  0.118620;0.102230;,
  0.000000;0.102230;,
  0.881380;0.000000;,
  1.000000;0.102230;,
  0.881380;0.102230;,
  0.118620;0.255750;,
  0.000000;0.255750;,
  0.118620;0.751820;,
  0.000000;0.751820;,
  1.000000;0.102230;,
  1.000000;0.255750;,
  0.881380;0.255750;,
  0.854250;0.255750;,
  0.854250;0.102230;,
  0.118620;0.863150;,
  0.000000;0.863150;,
  1.000000;0.751820;,
  0.881380;0.751820;,
  0.854250;0.751820;,
  0.118620;1.000000;,
  0.000000;1.000000;,
  1.000000;0.863150;,
  0.881380;0.863150;,
  0.854250;0.863150;,
  0.000000;0.881380;,
  0.027780;0.881380;,
  0.027780;1.000000;,
  1.000000;0.881380;,
  1.000000;1.000000;,
  1.000000;0.863150;,
  0.881380;1.000000;,
  0.027780;0.868580;,
  0.000000;0.868580;,
  0.000000;0.145750;,
  0.027780;0.145750;,
  1.000000;0.145750;,
  1.000000;0.868580;,
  0.868580;0.000000;,
  0.868580;0.102230;,
  0.145750;0.102230;,
  0.145750;0.000000;,
  0.131420;0.000000;,
  0.854250;0.000000;,
  0.854250;0.102230;,
  0.131420;0.102230;,
  0.114180;0.102230;,
  0.114180;0.000000;,
  0.868580;0.255750;,
  0.145750;0.255750;,
  0.131420;0.102230;,
  0.114180;0.102230;,
  0.868580;0.751820;,
  0.145750;0.751820;,
  0.131420;0.255750;,
  0.114180;0.255750;,
  0.868580;0.863150;,
  0.145750;0.863150;,
  0.131420;0.751820;,
  0.114180;0.751820;,
  0.868580;1.000000;,
  0.145750;1.000000;,
  0.131420;0.863150;,
  0.114180;0.863150;,
  0.000000;0.131420;,
  0.027780;0.131420;,
  0.027780;0.854250;,
  0.000000;0.854250;,
  0.854250;0.863150;,
  0.131420;0.863150;,
  0.114180;0.863150;,
  1.000000;0.131420;,
  1.000000;0.854250;,
  0.854250;1.000000;,
  0.131420;1.000000;,
  0.114180;1.000000;,
  0.027780;0.949740;,
  0.027780;1.000000;,
  0.000000;1.000000;,
  0.000000;0.949740;,
  1.000000;0.949740;,
  1.000000;1.000000;,
  0.949740;0.000000;,
  1.000000;0.000000;,
  1.000000;0.102230;,
  0.949740;0.102230;,
  0.050260;0.000000;,
  0.050260;0.102230;,
  0.000000;0.102230;,
  0.000000;0.000000;,
  1.000000;0.255750;,
  0.949740;0.255750;,
  0.050260;0.102230;,
  0.000000;0.102230;,
  1.000000;0.751820;,
  0.949740;0.751820;,
  0.050260;0.255750;,
  0.000000;0.255750;,
  1.000000;0.863150;,
  0.949740;0.863150;,
  0.050260;0.751820;,
  0.000000;0.751820;,
  1.000000;1.000000;,
  0.949740;1.000000;,
  0.050260;0.863150;,
  0.000000;0.863150;,
  0.000000;0.050260;,
  0.000000;0.000000;,
  0.027780;0.000000;,
  0.027780;0.050260;,
  0.050260;0.863150;,
  0.000000;0.863150;,
  1.000000;0.000000;,
  1.000000;0.050260;,
  0.050260;1.000000;,
  0.000000;1.000000;,
  0.027780;0.929950;,
  0.000000;0.929950;,
  0.000000;0.885820;,
  0.027780;0.885820;,
  1.000000;0.885820;,
  1.000000;0.929950;,
  0.929950;0.000000;,
  0.929950;0.102230;,
  0.885820;0.102230;,
  0.885820;0.000000;,
  0.070050;0.000000;,
  0.070050;0.102230;,
  0.929950;0.255750;,
  0.885820;0.255750;,
  0.070050;0.102230;,
  0.929950;0.751820;,
  0.885820;0.751820;,
  0.070050;0.255750;,
  0.929950;0.863150;,
  0.885820;0.863150;,
  0.070050;0.751820;,
  0.929950;1.000000;,
  0.885820;1.000000;,
  0.070050;0.863150;,
  0.000000;0.070050;,
  0.027780;0.070050;,
  0.027780;0.114180;,
  0.000000;0.114180;,
  0.070050;0.863150;,
  1.000000;0.070050;,
  1.000000;0.114180;,
  0.070050;1.000000;,
  0.000000;0.885820;,
  0.000000;0.868580;,
  0.885820;0.102230;,
  0.885820;0.000000;,
  0.868580;0.000000;,
  0.868580;0.102230;,
  0.885820;0.255750;,
  0.868580;0.255750;,
  0.885820;0.751820;,
  0.868580;0.751820;,
  0.885820;0.863150;,
  0.868580;0.863150;,
  0.885820;1.000000;,
  0.868580;1.000000;,
  0.000000;0.131420;,
  0.000000;0.114180;,
  0.000000;0.949740;,
  0.000000;0.929950;,
  0.949740;0.102230;,
  0.949740;0.000000;,
  0.929950;0.000000;,
  0.929950;0.102230;,
  0.949740;0.255750;,
  0.929950;0.255750;,
  0.949740;0.751820;,
  0.929950;0.751820;,
  0.949740;0.863150;,
  0.929950;0.863150;,
  0.949740;1.000000;,
  0.929950;1.000000;,
  0.000000;0.070050;,
  0.000000;0.050260;,
  0.013890;0.885820;,
  0.013890;0.868580;,
  0.013890;0.114180;,
  0.013890;0.131420;,
  0.013890;0.949740;,
  0.013890;0.929950;,
  0.013890;0.050260;,
  0.013890;0.070050;,
  0.149520;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.149520;1.000000;,
  0.850480;0.000000;,
  0.850480;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.130610;0.000000;,
  0.130610;1.000000;,
  0.869390;0.000000;,
  0.869390;1.000000;,
  0.101620;0.000000;,
  0.101620;1.000000;,
  0.898380;0.000000;,
  0.898380;1.000000;,
  0.935380;1.000000;,
  0.935380;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.064620;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.064620;0.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.150080;0.000000;,
  0.150080;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.150080;1.000000;,
  0.000000;1.000000;,
  0.000000;0.149520;,
  0.150080;0.149520;,
  0.150080;0.000000;,
  0.150080;0.850480;,
  0.000000;0.850480;,
  0.000000;0.000000;,
  0.000000;0.130610;,
  0.150080;0.130610;,
  0.150080;0.869390;,
  0.000000;0.869390;,
  0.000000;0.101620;,
  0.150080;0.101620;,
  0.150080;0.898380;,
  0.000000;0.898380;,
  0.000000;0.064620;,
  0.150080;0.064620;,
  0.150080;0.935380;,
  0.000000;0.935380;,
  0.150080;0.000000;,
  0.150080;1.000000;,
  0.849920;0.000000;,
  0.849920;0.000000;,
  0.849920;1.000000;,
  0.849920;1.000000;,
  0.912070;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.912070;1.000000;,
  0.912070;1.000000;,
  0.912070;0.149520;,
  1.000000;0.149520;,
  1.000000;1.000000;,
  0.912070;0.000000;,
  1.000000;0.000000;,
  1.000000;0.850480;,
  0.912070;0.850480;,
  0.912070;0.130610;,
  1.000000;0.130610;,
  1.000000;0.869390;,
  0.912070;0.869390;,
  0.912070;0.101620;,
  1.000000;0.101620;,
  1.000000;0.898380;,
  0.912070;0.898380;,
  0.912070;0.064620;,
  1.000000;0.064620;,
  1.000000;0.935380;,
  0.912070;0.935380;,
  0.912070;0.000000;,
  0.912070;1.000000;,
  0.087930;0.000000;,
  0.087930;0.000000;,
  0.087930;1.000000;,
  0.087930;1.000000;;
 }
}
