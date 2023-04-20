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
 220;
 0.00000;7.36097;0.00000;,
 2.11492;7.36097;-2.11492;,
 0.00000;7.36097;-2.99094;,
 0.00000;7.36097;0.00000;,
 2.99094;7.36097;0.00000;,
 0.00000;7.36097;0.00000;,
 2.11492;7.36097;2.11492;,
 0.00000;7.36097;0.00000;,
 0.00000;7.36097;2.99094;,
 0.00000;7.36097;0.00000;,
 -2.11492;7.36097;2.11492;,
 0.00000;7.36097;0.00000;,
 -2.99094;7.36097;0.00000;,
 0.00000;7.36097;0.00000;,
 -2.11492;7.36097;-2.11492;,
 0.00000;7.36097;0.00000;,
 0.00000;7.36097;-2.99094;,
 0.00000;0.09683;0.00000;,
 0.00000;0.09683;-6.67649;,
 4.72099;0.09683;-4.72099;,
 0.00000;0.09683;0.00000;,
 6.67649;0.09683;0.00000;,
 0.00000;0.09683;0.00000;,
 4.72099;0.09683;4.72099;,
 0.00000;0.09683;0.00000;,
 0.00000;0.09683;6.67649;,
 0.00000;0.09683;0.00000;,
 -4.72099;0.09683;4.72099;,
 0.00000;0.09683;0.00000;,
 -6.67649;0.09683;0.00000;,
 0.00000;0.09683;0.00000;,
 -4.72099;0.09683;-4.72099;,
 0.00000;0.09683;-6.67649;,
 -4.72099;0.09683;-4.72099;,
 0.00000;0.09683;0.00000;,
 -6.67649;0.09683;0.00000;,
 0.00000;0.79819;-6.67649;,
 4.72099;0.79819;-4.72099;,
 0.00000;0.79819;-6.67649;,
 -4.72099;0.79819;-4.72099;,
 6.67649;0.79819;0.00000;,
 -6.67649;0.79819;0.00000;,
 4.72099;0.79819;4.72099;,
 -4.72099;0.79819;4.72099;,
 0.00000;0.79819;6.67649;,
 2.66490;2.24534;0.00000;,
 1.88437;2.24534;1.88437;,
 1.88437;2.24534;-1.88437;,
 0.00000;2.24534;2.66490;,
 0.00000;2.24534;-2.66490;,
 -1.88437;2.24534;1.88437;,
 0.00000;2.24534;-2.66490;,
 -1.88437;2.24534;-1.88437;,
 -2.66490;2.24534;0.00000;,
 2.47682;2.66639;0.00000;,
 1.75138;2.66639;1.75138;,
 1.75138;2.66639;-1.75138;,
 0.00000;2.66639;2.47682;,
 0.00000;2.66639;-2.47682;,
 -1.75138;2.66639;1.75138;,
 0.00000;2.66639;-2.47682;,
 -1.75138;2.66639;-1.75138;,
 -2.47682;2.66639;0.00000;,
 2.57735;3.11643;0.00000;,
 1.82246;3.11643;1.82246;,
 1.82246;3.11643;-1.82246;,
 0.00000;3.11643;2.57735;,
 0.00000;3.11643;-2.57735;,
 -1.82246;3.11643;1.82246;,
 0.00000;3.11643;-2.57735;,
 -1.82246;3.11643;-1.82246;,
 -2.57735;3.11643;0.00000;,
 1.88177;3.60305;1.88177;,
 2.64962;3.44047;0.00000;,
 0.00000;3.44047;2.64962;,
 1.88177;3.60305;-1.88177;,
 -1.88177;3.60305;1.88177;,
 0.00000;3.44047;-2.64962;,
 -2.64962;3.44047;0.00000;,
 0.00000;3.44047;-2.64962;,
 -1.88177;3.60305;-1.88177;,
 2.50410;4.13213;0.00000;,
 1.77067;4.13213;1.77067;,
 1.88177;3.60305;1.88177;,
 2.52607;3.78506;0.00000;,
 1.88177;3.60305;-1.88177;,
 1.77067;4.13213;-1.77067;,
 0.00000;4.13213;2.50410;,
 0.00000;3.78506;2.52607;,
 0.00000;3.78506;-2.52607;,
 0.00000;4.13213;-2.50410;,
 -1.77067;4.13213;1.77067;,
 -1.88177;3.60305;1.88177;,
 0.00000;4.13213;-2.50410;,
 0.00000;3.78506;-2.52607;,
 -1.88177;3.60305;-1.88177;,
 -1.77067;4.13213;-1.77067;,
 -2.50410;4.13213;0.00000;,
 -2.52607;3.78506;0.00000;,
 1.55843;4.63242;1.55843;,
 0.00000;4.63242;2.20396;,
 2.20396;4.63242;0.00000;,
 -1.55843;4.63242;1.55843;,
 1.55843;4.63242;-1.55843;,
 -2.20396;4.63242;0.00000;,
 0.00000;4.63242;-2.20396;,
 -1.55843;4.63242;-1.55843;,
 0.00000;4.63242;-2.20396;,
 1.17772;5.02640;1.17772;,
 0.00000;5.02640;1.66555;,
 1.66555;5.02640;0.00000;,
 -1.17772;5.02640;1.17772;,
 1.17772;5.02640;-1.17772;,
 -1.66555;5.02640;0.00000;,
 0.00000;5.02640;-1.66555;,
 -1.17772;5.02640;-1.17772;,
 0.00000;5.02640;-1.66555;,
 0.00000;5.74984;1.79169;,
 -1.26692;5.74984;1.26692;,
 1.26692;5.74984;1.26692;,
 -1.79169;5.74984;0.00000;,
 1.79169;5.74984;0.00000;,
 -1.26692;5.74984;-1.26692;,
 1.26692;5.74984;-1.26692;,
 0.00000;5.74984;-1.79169;,
 0.00000;5.74984;-1.79169;,
 0.00000;6.27456;1.70341;,
 -1.20449;6.27456;1.20449;,
 1.20449;6.27456;1.20449;,
 -1.70341;6.27456;0.00000;,
 1.70341;6.27456;0.00000;,
 -1.20449;6.27456;-1.20449;,
 1.20449;6.27456;-1.20449;,
 0.00000;6.27456;-1.70341;,
 0.00000;6.27456;-1.70341;,
 1.84643;6.61870;0.00000;,
 1.30562;6.61870;1.30562;,
 1.30562;6.61870;-1.30562;,
 0.00000;6.61870;1.84643;,
 0.00000;6.61870;-1.84643;,
 -1.30562;6.61870;1.30562;,
 0.00000;6.61870;-1.84643;,
 -1.30562;6.61870;-1.30562;,
 -1.84643;6.61870;0.00000;,
 1.86217;6.97189;0.00000;,
 1.31675;6.97189;1.31675;,
 1.31675;6.97189;-1.31675;,
 0.00000;6.97189;1.86217;,
 0.00000;6.97189;-1.86217;,
 -1.31675;6.97189;1.31675;,
 0.00000;6.97189;-1.86217;,
 -1.31675;6.97189;-1.31675;,
 -1.86217;6.97189;0.00000;,
 4.51450;7.52771;-4.51450;,
 6.38446;7.52771;0.00000;,
 0.00000;7.52771;-6.38446;,
 4.51450;7.52771;4.51450;,
 0.00000;7.52771;-6.38446;,
 -4.51450;7.52771;-4.51450;,
 0.00000;7.52771;6.38446;,
 -6.38446;7.52771;0.00000;,
 -4.51450;7.52771;4.51450;,
 7.25467;8.62096;7.25467;,
 0.00000;8.62096;10.25966;,
 10.25966;8.62096;0.00000;,
 -7.25467;8.62096;7.25467;,
 7.25467;8.62096;-7.25467;,
 -10.25966;8.62096;0.00000;,
 0.00000;8.62096;-10.25966;,
 -7.25467;8.62096;-7.25467;,
 0.00000;8.62096;-10.25966;,
 8.56702;9.21417;8.56702;,
 0.00000;9.21417;12.11560;,
 12.11560;9.21417;0.00000;,
 -8.56702;9.21417;8.56702;,
 8.56702;9.21417;-8.56702;,
 -12.11560;9.21417;0.00000;,
 0.00000;9.21417;-12.11560;,
 -8.56702;9.21417;-8.56702;,
 0.00000;9.21417;-12.11560;,
 8.26225;9.43518;8.26225;,
 0.00000;9.43518;11.68459;,
 11.68459;9.43518;0.00000;,
 -8.26225;9.43518;8.26225;,
 8.26225;9.43518;-8.26225;,
 -11.68459;9.43518;0.00000;,
 0.00000;9.43518;-11.68459;,
 -8.26225;9.43518;-8.26225;,
 0.00000;9.43518;-11.68459;,
 11.41721;9.10860;0.00000;,
 8.07319;9.10860;8.07319;,
 8.07319;9.10860;-8.07319;,
 0.00000;9.10860;11.41721;,
 0.00000;9.10860;-11.41721;,
 -8.07319;9.10860;8.07319;,
 0.00000;9.10860;-11.41721;,
 -8.07319;9.10860;-8.07319;,
 -11.41721;9.10860;0.00000;,
 8.75528;8.40872;0.00000;,
 6.19093;8.40872;6.19093;,
 6.19093;8.40872;-6.19093;,
 0.00000;8.40872;8.75528;,
 0.00000;8.40872;-8.75528;,
 -6.19093;8.40872;6.19092;,
 0.00000;8.40872;-8.75528;,
 -6.19093;8.40872;-6.19093;,
 -8.75528;8.40872;0.00000;,
 1.88177;3.60305;-1.88177;,
 2.66122;3.60305;0.00000;,
 0.00000;3.60305;-2.66122;,
 1.88177;3.60305;-1.88177;,
 1.88177;3.60305;1.88177;,
 0.00000;3.60305;2.66122;,
 1.88177;3.60305;1.88177;,
 -1.88177;3.60305;1.88177;,
 -2.66122;3.60305;0.00000;,
 -1.88177;3.60305;1.88177;,
 -1.88177;3.60305;-1.88177;,
 0.00000;3.60305;-2.66122;,
 -1.88177;3.60305;-1.88177;;
 
 184;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 3;17,18,19;,
 3;20,19,21;,
 3;22,21,23;,
 3;24,23,25;,
 3;26,25,27;,
 3;28,27,29;,
 3;30,31,32;,
 3;33,34,35;,
 4;36,37,19,18;,
 4;38,32,31,39;,
 4;37,40,21,19;,
 4;39,31,29,41;,
 4;40,42,23,21;,
 4;41,29,27,43;,
 4;42,44,25,23;,
 4;43,27,25,44;,
 4;45,46,42,40;,
 4;45,40,37,47;,
 4;46,48,44,42;,
 4;47,37,36,49;,
 4;48,50,43,44;,
 4;51,38,39,52;,
 4;50,53,41,43;,
 4;52,39,41,53;,
 4;54,55,46,45;,
 4;54,45,47,56;,
 4;55,57,48,46;,
 4;56,47,49,58;,
 4;57,59,50,48;,
 4;60,51,52,61;,
 4;59,62,53,50;,
 4;61,52,53,62;,
 4;63,64,55,54;,
 4;63,54,56,65;,
 4;64,66,57,55;,
 4;65,56,58,67;,
 4;66,68,59,57;,
 4;69,60,61,70;,
 4;68,71,62,59;,
 4;70,61,62,71;,
 4;72,64,63,73;,
 4;72,74,66,64;,
 4;73,63,65,75;,
 4;74,76,68,66;,
 4;75,65,67,77;,
 4;76,78,71,68;,
 4;79,69,70,80;,
 4;78,80,70,71;,
 4;81,82,83,84;,
 4;81,84,85,86;,
 4;82,87,88,83;,
 4;86,85,89,90;,
 4;87,91,92,88;,
 4;93,94,95,96;,
 4;91,97,98,92;,
 4;96,95,98,97;,
 4;99,100,87,82;,
 4;99,82,81,101;,
 4;100,102,91,87;,
 4;101,81,86,103;,
 4;102,104,97,91;,
 4;103,86,90,105;,
 4;104,106,96,97;,
 4;107,93,96,106;,
 4;108,109,100,99;,
 4;108,99,101,110;,
 4;109,111,102,100;,
 4;110,101,103,112;,
 4;111,113,104,102;,
 4;112,103,105,114;,
 4;113,115,106,104;,
 4;116,107,106,115;,
 4;117,118,111,109;,
 4;117,109,108,119;,
 4;118,120,113,111;,
 4;119,108,110,121;,
 4;120,122,115,113;,
 4;121,110,112,123;,
 4;122,124,116,115;,
 4;123,112,114,125;,
 4;126,127,118,117;,
 4;126,117,119,128;,
 4;127,129,120,118;,
 4;128,119,121,130;,
 4;129,131,122,120;,
 4;130,121,123,132;,
 4;131,133,124,122;,
 4;132,123,125,134;,
 4;135,136,128,130;,
 4;135,130,132,137;,
 4;136,138,126,128;,
 4;137,132,134,139;,
 4;138,140,127,126;,
 4;141,133,131,142;,
 4;140,143,129,127;,
 4;142,131,129,143;,
 4;144,145,136,135;,
 4;144,135,137,146;,
 4;145,147,138,136;,
 4;146,137,139,148;,
 4;147,149,140,138;,
 4;150,141,142,151;,
 4;149,152,143,140;,
 4;151,142,143,152;,
 4;153,154,144,146;,
 4;153,146,148,155;,
 4;154,156,145,144;,
 4;157,150,151,158;,
 4;156,159,147,145;,
 4;158,151,152,160;,
 4;159,161,149,147;,
 4;160,152,149,161;,
 4;162,163,159,156;,
 4;162,156,154,164;,
 4;163,165,161,159;,
 4;164,154,153,166;,
 4;165,167,160,161;,
 4;166,153,155,168;,
 4;167,169,158,160;,
 4;170,157,158,169;,
 4;171,172,163,162;,
 4;171,162,164,173;,
 4;172,174,165,163;,
 4;173,164,166,175;,
 4;174,176,167,165;,
 4;175,166,168,177;,
 4;176,178,169,167;,
 4;179,170,169,178;,
 4;180,181,172,171;,
 4;180,171,173,182;,
 4;181,183,174,172;,
 4;182,173,175,184;,
 4;183,185,176,174;,
 4;184,175,177,186;,
 4;185,187,178,176;,
 4;188,179,178,187;,
 4;189,190,180,182;,
 4;189,182,184,191;,
 4;190,192,181,180;,
 4;191,184,186,193;,
 4;192,194,183,181;,
 4;195,188,187,196;,
 4;194,197,185,183;,
 4;196,187,185,197;,
 4;198,4,6,199;,
 4;198,199,190,189;,
 4;198,189,191,200;,
 4;198,200,1,4;,
 4;199,6,8,201;,
 4;199,201,192,190;,
 4;200,191,193,202;,
 4;200,202,2,1;,
 4;201,8,10,203;,
 4;201,203,194,192;,
 4;204,195,196,205;,
 4;204,205,14,16;,
 4;203,10,12,206;,
 4;203,206,197,194;,
 4;205,196,197,206;,
 4;205,206,12,14;,
 3;207,84,208;,
 3;207,209,89;,
 3;210,208,73;,
 3;210,77,209;,
 3;211,208,84;,
 3;211,88,212;,
 3;213,73,208;,
 3;213,212,74;,
 3;214,212,88;,
 3;214,98,215;,
 3;216,74,212;,
 3;216,215,78;,
 3;217,94,218;,
 3;217,215,98;,
 3;219,218,79;,
 3;219,78,215;;
 
 MeshMaterialList {
  1;
  184;
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
  0;;
  Material {
   0.659200;0.800000;0.787200;0.800000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  194;
  0.000000;1.000000;0.000000;,
  0.000000;0.995973;0.089657;,
  -0.063397;0.995973;0.063397;,
  -0.089657;0.995973;0.000000;,
  -0.063397;0.995973;-0.063397;,
  0.000000;0.995973;-0.089657;,
  0.063397;0.995973;-0.063397;,
  0.089657;0.995973;-0.000000;,
  0.063397;0.995973;0.063397;,
  0.000000;-1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  -0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  -0.707107;0.000000;0.707107;,
  0.000000;0.000000;1.000000;,
  0.671567;0.740943;0.000000;,
  0.474870;0.740944;0.474870;,
  0.474870;0.740944;-0.474870;,
  0.000000;0.740943;0.671567;,
  0.000000;0.740943;-0.671567;,
  -0.474870;0.740944;0.474870;,
  -0.474870;0.740944;-0.474870;,
  -0.671567;0.740943;0.000000;,
  0.994840;0.101456;0.000000;,
  0.703458;0.101456;0.703458;,
  0.703458;0.101456;-0.703458;,
  0.000000;0.101456;0.994840;,
  0.000000;0.101456;-0.994840;,
  -0.703458;0.101456;0.703458;,
  -0.703458;0.101456;-0.703458;,
  -0.994840;0.101456;0.000000;,
  0.978505;-0.206224;-0.000000;,
  0.691953;-0.205915;0.691953;,
  0.691953;-0.205915;-0.691953;,
  0.000000;-0.206224;0.978505;,
  0.000000;-0.206224;-0.978505;,
  -0.691953;-0.205915;0.691953;,
  -0.691953;-0.205915;-0.691953;,
  -0.978505;-0.206224;0.000000;,
  0.700533;0.136040;0.700533;,
  0.991107;-0.133065;-0.000000;,
  0.000000;-0.133065;0.991107;,
  0.700533;0.136040;-0.700533;,
  -0.700533;0.136040;0.700533;,
  0.000000;-0.133065;-0.991107;,
  -0.991107;-0.133065;0.000000;,
  -0.700533;0.136040;-0.700533;,
  0.958636;0.284634;-0.000000;,
  0.000000;0.284634;0.958636;,
  0.000000;0.284634;-0.958636;,
  -0.958636;0.284634;0.000000;,
  0.918010;0.396558;0.000000;,
  0.000000;0.396558;0.918010;,
  0.000000;0.396558;-0.918010;,
  -0.918010;0.396558;0.000000;,
  0.936771;0.349943;0.000000;,
  0.661725;0.352478;0.661725;,
  0.661725;0.352478;-0.661725;,
  0.000000;0.349943;0.936771;,
  0.000000;0.349943;-0.936771;,
  -0.661725;0.352478;0.661725;,
  -0.661725;0.352478;-0.661725;,
  -0.936771;0.349943;0.000000;,
  0.520842;0.676349;0.520842;,
  0.000000;0.676349;0.736581;,
  0.736581;0.676349;0.000000;,
  -0.520842;0.676349;0.520842;,
  0.520842;0.676349;-0.520842;,
  -0.736581;0.676349;0.000000;,
  0.000000;0.676349;-0.736581;,
  -0.520842;0.676349;-0.520842;,
  0.417570;0.807013;0.417570;,
  0.000000;0.807014;0.590532;,
  0.590532;0.807014;0.000000;,
  -0.417570;0.807013;0.417570;,
  0.417570;0.807013;-0.417570;,
  -0.590532;0.807014;0.000000;,
  0.000000;0.807014;-0.590532;,
  -0.417570;0.807013;-0.417570;,
  0.000000;-0.002983;0.999996;,
  -0.707104;-0.002983;0.707104;,
  0.707104;-0.002983;0.707104;,
  -0.999996;-0.002983;0.000000;,
  0.999996;-0.002983;-0.000000;,
  -0.707104;-0.002983;-0.707104;,
  0.707104;-0.002983;-0.707104;,
  0.000000;-0.002983;-0.999996;,
  0.000000;-0.114616;0.993410;,
  -0.702447;-0.114616;0.702447;,
  0.702447;-0.114616;0.702447;,
  -0.993410;-0.114616;0.000000;,
  0.993410;-0.114616;-0.000000;,
  -0.702447;-0.114616;-0.702447;,
  0.702447;-0.114616;-0.702447;,
  0.000000;-0.114616;-0.993410;,
  0.975864;-0.218378;-0.000000;,
  0.690040;-0.218378;0.690040;,
  0.690040;-0.218378;-0.690040;,
  0.000000;-0.218378;0.975864;,
  0.000000;-0.218378;-0.975864;,
  -0.690040;-0.218378;0.690040;,
  -0.690040;-0.218378;-0.690040;,
  -0.975864;-0.218378;0.000000;,
  0.999008;-0.044521;-0.000000;,
  0.706406;-0.044521;0.706406;,
  0.706406;-0.044521;-0.706406;,
  0.000000;-0.044521;0.999008;,
  0.000000;-0.044521;-0.999008;,
  -0.706406;-0.044521;0.706406;,
  -0.706406;-0.044521;-0.706406;,
  -0.999008;-0.044521;0.000000;,
  0.139399;-0.980375;-0.139399;,
  0.197140;-0.980375;-0.000000;,
  0.000000;-0.980375;-0.197140;,
  0.139399;-0.980375;0.139399;,
  -0.139399;-0.980375;-0.139399;,
  0.000000;-0.980375;0.197140;,
  -0.197140;-0.980375;0.000000;,
  -0.139399;-0.980375;0.139399;,
  0.203657;-0.957626;0.203657;,
  0.000000;-0.957626;0.288015;,
  0.288015;-0.957626;-0.000000;,
  -0.203657;-0.957626;0.203657;,
  0.203657;-0.957626;-0.203657;,
  -0.288015;-0.957626;0.000000;,
  0.000000;-0.957626;-0.288015;,
  -0.203657;-0.957626;-0.203657;,
  0.215281;-0.952527;0.215281;,
  0.000000;-0.952527;0.304454;,
  0.304454;-0.952527;-0.000000;,
  -0.215281;-0.952527;0.215281;,
  0.215281;-0.952527;-0.215281;,
  -0.304454;-0.952527;0.000000;,
  0.000000;-0.952527;-0.304454;,
  -0.215281;-0.952527;-0.215281;,
  0.322641;0.889835;0.322641;,
  0.000000;0.889835;0.456283;,
  0.456283;0.889835;0.000000;,
  -0.322641;0.889835;0.322641;,
  0.322641;0.889835;-0.322641;,
  -0.456283;0.889835;0.000000;,
  0.000000;0.889835;-0.456283;,
  -0.322641;0.889835;-0.322641;,
  -0.534477;0.845183;0.000000;,
  -0.377932;0.845183;-0.377932;,
  -0.377932;0.845183;0.377932;,
  -0.000000;0.845183;-0.534477;,
  0.000000;0.845183;0.534477;,
  0.377932;0.845183;-0.377932;,
  0.377932;0.845183;0.377932;,
  0.534477;0.845183;0.000000;,
  -0.216667;0.976246;0.000000;,
  -0.153206;0.976246;-0.153206;,
  -0.153206;0.976246;0.153206;,
  0.000000;0.976246;-0.216667;,
  0.000000;0.976246;0.216667;,
  0.153206;0.976246;-0.153206;,
  0.153206;0.976246;0.153206;,
  0.216667;0.976246;-0.000000;,
  0.239948;0.940665;0.239948;,
  0.339338;0.940665;0.000000;,
  0.239948;0.940665;-0.239948;,
  0.000000;0.940665;0.339338;,
  0.000000;0.940665;-0.339338;,
  -0.239948;0.940665;0.239948;,
  -0.239948;0.940665;-0.239948;,
  -0.339338;0.940665;0.000000;,
  -0.696596;-0.171775;0.696596;,
  0.000000;-0.171775;0.985136;,
  0.696596;-0.171775;0.696596;,
  -0.985136;-0.171775;0.000000;,
  0.985136;-0.171775;-0.000000;,
  -0.696596;-0.171775;-0.696596;,
  0.696596;-0.171775;-0.696596;,
  0.000000;-0.171775;-0.985136;,
  0.121988;-0.992531;-0.000000;,
  0.086259;-0.992531;-0.086259;,
  0.000000;-0.992531;-0.121988;,
  0.086259;-0.992531;0.086259;,
  -0.086259;-0.992531;-0.086259;,
  0.000000;-0.992531;0.121988;,
  -0.121988;-0.992531;0.000000;,
  -0.086259;-0.992531;0.086259;,
  -0.547128;0.633484;-0.547128;,
  -0.773756;0.633484;0.000000;,
  -0.547128;0.633484;0.547128;,
  0.000000;0.633484;-0.773756;,
  0.000000;0.633484;0.773756;,
  0.547128;0.633484;-0.547128;,
  0.547128;0.633484;0.547128;,
  0.773756;0.633484;0.000000;;
  184;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  3;9,9,9;,
  4;10,11,11,10;,
  4;10,10,12,12;,
  4;11,13,13,11;,
  4;12,12,14,14;,
  4;13,15,15,13;,
  4;14,14,16,16;,
  4;15,17,17,15;,
  4;16,16,17,17;,
  4;18,19,162,163;,
  4;18,163,164,20;,
  4;19,21,165,162;,
  4;20,164,166,22;,
  4;21,23,167,165;,
  4;22,166,168,24;,
  4;23,25,169,167;,
  4;24,168,169,25;,
  4;26,27,19,18;,
  4;26,18,20,28;,
  4;27,29,21,19;,
  4;28,20,22,30;,
  4;29,31,23,21;,
  4;30,22,24,32;,
  4;31,33,25,23;,
  4;32,24,25,33;,
  4;34,35,27,26;,
  4;34,26,28,36;,
  4;35,37,29,27;,
  4;36,28,30,38;,
  4;37,39,31,29;,
  4;38,30,32,40;,
  4;39,41,33,31;,
  4;40,32,33,41;,
  4;42,35,34,43;,
  4;42,44,37,35;,
  4;43,34,36,45;,
  4;44,46,39,37;,
  4;45,36,38,47;,
  4;46,48,41,39;,
  4;47,38,40,49;,
  4;48,49,40,41;,
  4;58,59,42,54;,
  4;58,54,45,60;,
  4;59,61,55,42;,
  4;60,45,56,62;,
  4;61,63,46,55;,
  4;62,56,49,64;,
  4;63,65,57,46;,
  4;64,49,57,65;,
  4;66,67,61,59;,
  4;66,59,58,68;,
  4;67,69,63,61;,
  4;68,58,60,70;,
  4;69,71,65,63;,
  4;70,60,62,72;,
  4;71,73,64,65;,
  4;72,62,64,73;,
  4;74,75,67,66;,
  4;74,66,68,76;,
  4;75,77,69,67;,
  4;76,68,70,78;,
  4;77,79,71,69;,
  4;78,70,72,80;,
  4;79,81,73,71;,
  4;80,72,73,81;,
  4;82,83,170,171;,
  4;82,171,172,84;,
  4;83,85,173,170;,
  4;84,172,174,86;,
  4;85,87,175,173;,
  4;86,174,176,88;,
  4;87,89,177,175;,
  4;88,176,177,89;,
  4;90,91,83,82;,
  4;90,82,84,92;,
  4;91,93,85,83;,
  4;92,84,86,94;,
  4;93,95,87,85;,
  4;94,86,88,96;,
  4;95,97,89,87;,
  4;96,88,89,97;,
  4;98,99,92,94;,
  4;98,94,96,100;,
  4;99,101,90,92;,
  4;100,96,97,102;,
  4;101,103,91,90;,
  4;102,97,95,104;,
  4;103,105,93,91;,
  4;104,95,93,105;,
  4;106,107,99,98;,
  4;106,98,100,108;,
  4;107,109,101,99;,
  4;108,100,102,110;,
  4;109,111,103,101;,
  4;110,102,104,112;,
  4;111,113,105,103;,
  4;112,104,105,113;,
  4;114,115,178,179;,
  4;114,179,180,116;,
  4;115,117,181,178;,
  4;116,180,182,118;,
  4;117,119,183,181;,
  4;118,182,184,120;,
  4;119,121,185,183;,
  4;120,184,185,121;,
  4;122,123,119,117;,
  4;122,117,115,124;,
  4;123,125,121,119;,
  4;124,115,114,126;,
  4;125,127,120,121;,
  4;126,114,116,128;,
  4;127,129,118,120;,
  4;128,116,118,129;,
  4;130,131,123,122;,
  4;130,122,124,132;,
  4;131,133,125,123;,
  4;132,124,126,134;,
  4;133,135,127,125;,
  4;134,126,128,136;,
  4;135,137,129,127;,
  4;136,128,129,137;,
  4;138,139,139,138;,
  4;138,138,140,140;,
  4;139,141,141,139;,
  4;140,140,142,142;,
  4;141,143,143,141;,
  4;142,142,144,144;,
  4;143,145,145,143;,
  4;144,144,145,145;,
  4;146,147,186,187;,
  4;146,187,188,148;,
  4;147,149,189,186;,
  4;148,188,190,150;,
  4;149,151,191,189;,
  4;150,190,192,152;,
  4;151,153,193,191;,
  4;152,192,193,153;,
  4;154,3,4,155;,
  4;154,155,147,146;,
  4;154,146,148,156;,
  4;154,156,2,3;,
  4;155,4,5,157;,
  4;155,157,149,147;,
  4;156,148,150,158;,
  4;156,158,1,2;,
  4;157,5,6,159;,
  4;157,159,151,149;,
  4;158,150,152,160;,
  4;158,160,8,1;,
  4;159,6,7,161;,
  4;159,161,153,151;,
  4;160,152,153,161;,
  4;160,161,7,8;,
  3;45,54,50;,
  3;45,52,56;,
  3;45,50,43;,
  3;45,47,52;,
  3;42,50,54;,
  3;42,55,51;,
  3;42,43,50;,
  3;42,51,44;,
  3;46,51,55;,
  3;46,57,53;,
  3;46,44,51;,
  3;46,53,48;,
  3;49,56,52;,
  3;49,53,57;,
  3;49,52,47;,
  3;49,48,53;;
 }
 MeshTextureCoords {
  220;
  0.062500;0.000000;,
  0.125000;0.000000;,
  0.000000;0.000000;,
  0.187500;0.000000;,
  0.250000;0.000000;,
  0.312500;0.000000;,
  0.375000;0.000000;,
  0.437500;0.000000;,
  0.500000;0.000000;,
  0.562500;0.000000;,
  0.625000;0.000000;,
  0.687500;0.000000;,
  0.750000;0.000000;,
  0.812500;0.000000;,
  0.875000;0.000000;,
  0.937500;0.000000;,
  1.000000;0.000000;,
  0.062500;1.000000;,
  0.000000;1.000000;,
  0.125000;1.000000;,
  0.187500;1.000000;,
  0.250000;1.000000;,
  0.312500;1.000000;,
  0.375000;1.000000;,
  0.437500;1.000000;,
  0.500000;1.000000;,
  0.562500;1.000000;,
  0.625000;1.000000;,
  0.687500;1.000000;,
  0.750000;1.000000;,
  0.937500;1.000000;,
  0.875000;1.000000;,
  1.000000;1.000000;,
  0.825120;1.000000;,
  0.812500;1.000000;,
  0.781510;1.000000;,
  0.000000;0.174150;,
  0.125000;0.174150;,
  1.000000;0.174150;,
  0.875000;0.174150;,
  0.250000;0.174150;,
  0.750000;0.174150;,
  0.375000;0.174150;,
  0.625000;0.174150;,
  0.500000;0.174150;,
  0.250000;0.009330;,
  0.375000;0.009330;,
  0.125000;0.009330;,
  0.500000;0.009330;,
  0.000000;0.009330;,
  0.625000;0.009330;,
  1.000000;0.009330;,
  0.875000;0.009330;,
  0.750000;0.009330;,
  0.250000;0.001600;,
  0.375000;0.001600;,
  0.125000;0.001600;,
  0.500000;0.001600;,
  0.000000;0.001600;,
  0.625000;0.001600;,
  1.000000;0.001600;,
  0.875000;0.001600;,
  0.750000;0.001600;,
  0.250000;0.000310;,
  0.375000;0.000310;,
  0.125000;0.000310;,
  0.500000;0.000310;,
  0.000000;0.000310;,
  0.625000;0.000310;,
  1.000000;0.000310;,
  0.875000;0.000310;,
  0.750000;0.000310;,
  0.375000;0.000060;,
  0.250000;0.000060;,
  0.500000;0.000060;,
  0.125000;0.000060;,
  0.625000;0.000060;,
  0.000000;0.000060;,
  0.750000;0.000060;,
  1.000000;0.000060;,
  0.875000;0.000060;,
  0.250000;0.000000;,
  0.375000;0.000000;,
  0.375000;0.000000;,
  0.250000;0.000000;,
  0.125000;0.000000;,
  0.125000;0.000000;,
  0.500000;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.625000;0.000000;,
  0.625000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.875000;0.000000;,
  0.875000;0.000000;,
  0.750000;0.000000;,
  0.750000;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.250000;0.000000;,
  0.625000;0.000000;,
  0.125000;0.000000;,
  0.750000;0.000000;,
  0.000000;0.000000;,
  0.875000;0.000000;,
  1.000000;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.250000;0.000000;,
  0.625000;0.000000;,
  0.125000;0.000000;,
  0.750000;0.000000;,
  0.000000;0.000000;,
  0.875000;0.000000;,
  1.000000;0.000000;,
  0.500000;0.000000;,
  0.625000;0.000000;,
  0.375000;0.000000;,
  0.750000;0.000000;,
  0.250000;0.000000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.500000;0.000000;,
  0.625000;0.000000;,
  0.375000;0.000000;,
  0.750000;0.000000;,
  0.250000;0.000000;,
  0.875000;0.000000;,
  0.125000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.625000;0.000000;,
  1.000000;0.000000;,
  0.875000;0.000000;,
  0.750000;0.000000;,
  0.250000;0.000000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.625000;0.000000;,
  1.000000;0.000000;,
  0.875000;0.000000;,
  0.750000;0.000000;,
  0.125000;0.000000;,
  0.250000;0.000000;,
  0.000000;0.000000;,
  0.375000;0.000000;,
  1.000000;0.000000;,
  0.875000;0.000000;,
  0.500000;0.000000;,
  0.750000;0.000000;,
  0.625000;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.250000;0.000000;,
  0.625000;0.000000;,
  0.125000;0.000000;,
  0.750000;0.000000;,
  0.000000;0.000000;,
  0.875000;0.000000;,
  1.000000;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.250000;0.000000;,
  0.625000;0.000000;,
  0.125000;0.000000;,
  0.750000;0.000000;,
  0.000000;0.000000;,
  0.875000;0.000000;,
  1.000000;0.000000;,
  0.375000;0.000000;,
  0.500000;0.000000;,
  0.250000;0.000000;,
  0.625000;0.000000;,
  0.125000;0.000000;,
  0.750000;0.000000;,
  0.000000;0.000000;,
  0.875000;0.000000;,
  1.000000;0.000000;,
  0.250000;0.000000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.625000;0.000000;,
  1.000000;0.000000;,
  0.875000;0.000000;,
  0.750000;0.000000;,
  0.250000;0.000000;,
  0.375000;0.000000;,
  0.125000;0.000000;,
  0.500000;0.000000;,
  0.000000;0.000000;,
  0.625000;0.000000;,
  1.000000;0.000000;,
  0.875000;0.000000;,
  0.750000;0.000000;,
  0.125000;0.000010;,
  0.250000;0.000020;,
  0.000000;0.000020;,
  0.125000;0.000040;,
  0.375000;0.000010;,
  0.500000;0.000020;,
  0.375000;0.000040;,
  0.625000;0.000010;,
  0.750000;0.000020;,
  0.625000;0.000040;,
  0.875000;0.000010;,
  1.000000;0.000020;,
  0.875000;0.000040;;
 }
}
