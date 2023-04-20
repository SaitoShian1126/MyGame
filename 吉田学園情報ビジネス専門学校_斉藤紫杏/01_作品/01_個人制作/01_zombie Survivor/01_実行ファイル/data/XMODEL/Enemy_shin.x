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
 248;
 0.85217;-6.38521;-1.13092;,
 0.99466;-4.17233;-1.32002;,
 1.08982;-4.17233;-1.29992;,
 0.93370;-6.38521;-1.11370;,
 1.17050;-4.17233;-1.24269;,
 1.00282;-6.38521;-1.06467;,
 1.22440;-4.17233;-1.15704;,
 1.04900;-6.38521;-0.99129;,
 1.24333;-4.17233;-1.05601;,
 1.06522;-6.38521;-0.90473;,
 0.99466;-4.17233;1.32002;,
 0.85217;-6.38521;1.13092;,
 0.93370;-6.38521;1.11370;,
 1.08982;-4.17233;1.29992;,
 1.00282;-6.38521;1.06467;,
 1.17050;-4.17233;1.24269;,
 1.04900;-6.38521;0.99129;,
 1.22440;-4.17233;1.15704;,
 1.06522;-6.38521;0.90473;,
 1.24333;-4.17233;1.05601;,
 -0.99466;-4.17233;-1.32002;,
 -0.85217;-6.38521;-1.13092;,
 -0.93370;-6.38521;-1.11370;,
 -1.08982;-4.17233;-1.29992;,
 -1.00282;-6.38521;-1.06467;,
 -1.17050;-4.17233;-1.24269;,
 -1.04900;-6.38521;-0.99129;,
 -1.22440;-4.17233;-1.15704;,
 -1.06522;-6.38521;-0.90473;,
 -1.24333;-4.17233;-1.05601;,
 -0.85217;-6.38521;1.13092;,
 -0.99466;-4.17233;1.32002;,
 -1.08982;-4.17233;1.29992;,
 -0.93370;-6.38521;1.11370;,
 -1.17050;-4.17233;1.24269;,
 -1.00282;-6.38521;1.06467;,
 -1.22440;-4.17233;1.15704;,
 -1.04900;-6.38521;0.99129;,
 -1.24333;-4.17233;1.05601;,
 -1.06522;-6.38521;0.90473;,
 0.99466;-0.01957;-1.05601;,
 1.08982;-0.07299;-1.05601;,
 0.99466;-0.07299;-1.15704;,
 1.17050;-0.22510;-1.05601;,
 1.11900;-0.22510;-1.18801;,
 0.99466;-0.22510;-1.24269;,
 1.22440;-0.45275;-1.05601;,
 1.19362;-0.45275;-1.17797;,
 1.10953;-0.45275;-1.26724;,
 0.99466;-0.45275;-1.29992;,
 -0.99466;-0.07299;-1.15704;,
 -1.08982;-0.07299;-1.05601;,
 -0.99466;-0.01957;-1.05601;,
 -1.11900;-0.22510;-1.18801;,
 -1.17050;-0.22510;-1.05601;,
 -0.99466;-0.22510;-1.24269;,
 -1.19362;-0.45275;-1.17797;,
 -1.22440;-0.45275;-1.05601;,
 -1.10953;-0.45275;-1.26724;,
 -0.99466;-0.45275;-1.29992;,
 0.85217;-6.94064;-0.99129;,
 0.93370;-6.94064;-0.90473;,
 0.85217;-6.98640;-0.90473;,
 0.95870;-6.81031;-1.01783;,
 1.00282;-6.81031;-0.90473;,
 0.85217;-6.81031;-1.06467;,
 1.02263;-6.61527;-1.00922;,
 1.04900;-6.61527;-0.90473;,
 0.95059;-6.61527;-1.08570;,
 0.85217;-6.61527;-1.11370;,
 0.99466;-0.07299;1.15704;,
 1.08982;-0.07299;1.05601;,
 0.99466;-0.01957;1.05601;,
 1.11900;-0.22510;1.18801;,
 1.17050;-0.22510;1.05601;,
 0.99466;-0.22510;1.24269;,
 1.19362;-0.45275;1.17797;,
 1.22440;-0.45275;1.05601;,
 1.10953;-0.45275;1.26724;,
 0.99466;-0.45275;1.29992;,
 -0.85217;-6.98640;-0.90473;,
 -0.93370;-6.94064;-0.90473;,
 -0.85217;-6.94064;-0.99129;,
 -1.00282;-6.81031;-0.90473;,
 -0.95870;-6.81031;-1.01783;,
 -0.85217;-6.81031;-1.06467;,
 -1.04900;-6.61527;-0.90473;,
 -1.02263;-6.61527;-1.00922;,
 -0.95059;-6.61527;-1.08570;,
 -0.85217;-6.61527;-1.11370;,
 0.85217;-6.98640;0.90473;,
 0.93370;-6.94064;0.90473;,
 0.85217;-6.94064;0.99129;,
 1.00282;-6.81031;0.90473;,
 0.95870;-6.81031;1.01783;,
 0.85217;-6.81031;1.06467;,
 1.04900;-6.61527;0.90473;,
 1.02263;-6.61527;1.00922;,
 0.95059;-6.61527;1.08570;,
 0.85217;-6.61527;1.11370;,
 -0.99466;-0.01957;1.05601;,
 -1.08982;-0.07299;1.05601;,
 -0.99466;-0.07299;1.15704;,
 -1.17050;-0.22510;1.05601;,
 -1.11900;-0.22510;1.18801;,
 -0.99466;-0.22510;1.24269;,
 -1.22440;-0.45275;1.05601;,
 -1.19362;-0.45275;1.17797;,
 -1.10953;-0.45275;1.26724;,
 -0.99466;-0.45275;1.29992;,
 -0.85217;-6.94064;0.99129;,
 -0.93370;-6.94064;0.90473;,
 -0.85217;-6.98640;0.90473;,
 -0.95870;-6.81031;1.01783;,
 -1.00282;-6.81031;0.90473;,
 -0.85217;-6.81031;1.06467;,
 -1.02263;-6.61527;1.00922;,
 -1.04900;-6.61527;0.90473;,
 -0.95059;-6.61527;1.08570;,
 -0.85217;-6.61527;1.11370;,
 1.40090;-1.41496;-1.24966;,
 1.40866;-1.41496;-1.20824;,
 1.37830;-1.41496;-1.33919;,
 1.35620;-1.41496;-1.37431;,
 1.29447;-1.41496;-1.43985;,
 1.26139;-1.41496;-1.46332;,
 1.17707;-1.41496;-1.48730;,
 1.13805;-1.41496;-1.49554;,
 -1.40866;-1.41496;-1.20824;,
 -1.40090;-1.41496;-1.24966;,
 -1.37830;-1.41496;-1.33919;,
 -1.35620;-1.41496;-1.37431;,
 -1.29447;-1.41496;-1.43985;,
 -1.26139;-1.41496;-1.46332;,
 -1.17707;-1.41496;-1.48730;,
 -1.13805;-1.41496;-1.49554;,
 1.40866;-1.41496;1.20824;,
 1.40090;-1.41496;1.24966;,
 1.37830;-1.41496;1.33919;,
 1.35620;-1.41496;1.37431;,
 1.29447;-1.41496;1.43985;,
 1.26139;-1.41496;1.46332;,
 1.17707;-1.41496;1.48730;,
 1.13805;-1.41496;1.49554;,
 -1.40090;-1.41496;1.24966;,
 -1.40866;-1.41496;1.20824;,
 -1.37830;-1.41496;1.33919;,
 -1.35620;-1.41496;1.37431;,
 -1.29447;-1.41496;1.43985;,
 -1.26139;-1.41496;1.46332;,
 -1.17707;-1.41496;1.48730;,
 -1.13805;-1.41496;1.49554;,
 1.41125;-1.92366;-1.20824;,
 1.40090;-1.92366;-1.26348;,
 1.38251;-1.92366;-1.33633;,
 1.35304;-1.92366;-1.38316;,
 1.30281;-1.92366;-1.43649;,
 1.25870;-1.92366;-1.46778;,
 1.19008;-1.92366;-1.48730;,
 1.13805;-1.92366;-1.49829;,
 -1.40090;-1.92366;-1.26348;,
 -1.41125;-1.92366;-1.20824;,
 -1.38251;-1.92366;-1.33633;,
 -1.35304;-1.92366;-1.38316;,
 -1.30281;-1.92366;-1.43649;,
 -1.25870;-1.92366;-1.46778;,
 -1.19008;-1.92366;-1.48730;,
 -1.13805;-1.92366;-1.49829;,
 1.40090;-1.92366;1.26348;,
 1.41125;-1.92366;1.20824;,
 1.38251;-1.92366;1.33633;,
 1.35304;-1.92366;1.38316;,
 1.30281;-1.92366;1.43649;,
 1.25870;-1.92366;1.46778;,
 1.19008;-1.92366;1.48730;,
 1.13805;-1.92366;1.49829;,
 -1.41125;-1.92366;1.20824;,
 -1.40090;-1.92366;1.26348;,
 -1.38251;-1.92366;1.33633;,
 -1.35304;-1.92366;1.38316;,
 -1.30281;-1.92366;1.43649;,
 -1.25870;-1.92366;1.46778;,
 -1.19008;-1.92366;1.48730;,
 -1.13805;-1.92366;1.49829;,
 1.25579;-6.38521;-0.01133;,
 1.46577;-4.17233;-0.01133;,
 -1.46577;-4.17233;-0.01133;,
 -1.25579;-6.38521;-0.01133;,
 1.17262;-0.01957;-0.01133;,
 1.28480;-0.07299;-0.01133;,
 1.37991;-0.22510;-0.01133;,
 1.44346;-0.45275;-0.01133;,
 1.00463;-6.98640;-0.01133;,
 1.10075;-6.94064;-0.01133;,
 1.18223;-6.81031;-0.01133;,
 1.23668;-6.61527;-0.01133;,
 -1.17262;-0.01957;-0.01133;,
 -1.28480;-0.07299;-0.01133;,
 -1.37991;-0.22510;-0.01133;,
 -1.44346;-0.45275;-0.01133;,
 -1.00463;-6.98640;-0.01133;,
 -1.10075;-6.94064;-0.01133;,
 -1.18223;-6.81031;-0.01133;,
 -1.23668;-6.61527;-0.01133;,
 1.66068;-1.41496;-0.01133;,
 -1.66068;-1.41496;-0.01133;,
 1.66373;-1.92366;-0.01133;,
 -1.66373;-1.92366;-0.01133;,
 0.01409;-4.17233;-1.50278;,
 0.01409;-6.38521;-1.28750;,
 -0.85217;-6.38521;-1.13092;,
 -0.99466;-4.17233;-1.32002;,
 0.01409;-6.38521;1.28750;,
 0.01409;-4.17233;1.50278;,
 0.01409;-0.01957;-1.20223;,
 0.01409;-0.07299;-1.31724;,
 -0.99466;-0.07299;-1.15704;,
 -0.99466;-0.01957;-1.05601;,
 0.01409;-0.22510;-1.41475;,
 -0.99466;-0.22510;-1.24269;,
 0.01409;-0.45275;-1.47990;,
 -0.99466;-0.45275;-1.29992;,
 0.01409;-6.94064;-1.12854;,
 0.01409;-6.98640;-1.03000;,
 -0.85217;-6.98640;-0.90473;,
 -0.85217;-6.94064;-0.99129;,
 0.01409;-6.81031;-1.21208;,
 -0.85217;-6.81031;-1.06467;,
 0.01409;-6.61527;-1.26790;,
 -0.85217;-6.61527;-1.11370;,
 0.01409;-0.07299;1.31724;,
 0.01409;-0.01957;1.20223;,
 0.01409;-0.22510;1.41475;,
 0.01409;-0.45275;1.47990;,
 0.01409;-6.98640;1.03000;,
 0.01409;-6.94064;1.12854;,
 0.01409;-6.81031;1.21208;,
 0.01409;-6.61527;1.26790;,
 0.01409;-1.41496;-1.70262;,
 -1.13805;-1.41496;-1.49554;,
 0.01409;-1.41496;1.70262;,
 -1.13805;-1.92366;-1.49829;,
 0.01409;-1.92366;-1.70575;,
 0.01409;-1.92366;1.70575;,
 -1.17262;-0.01957;-0.01133;,
 0.01409;-0.01957;-0.01133;,
 0.01409;-6.98640;-0.01133;,
 -1.00463;-6.98640;-0.01133;;
 
 296;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;10,11,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;17,16,18,19;,
 4;20,21,22,23;,
 4;23,22,24,25;,
 4;25,24,26,27;,
 4;27,26,28,29;,
 4;30,31,32,33;,
 4;33,32,34,35;,
 4;35,34,36,37;,
 4;37,36,38,39;,
 3;40,41,42;,
 3;41,43,44;,
 3;44,42,41;,
 3;42,44,45;,
 3;43,46,47;,
 3;47,44,43;,
 3;44,47,48;,
 3;48,45,44;,
 3;45,48,49;,
 3;50,51,52;,
 3;53,54,51;,
 3;51,50,53;,
 3;55,53,50;,
 3;56,57,54;,
 3;54,53,56;,
 3;58,56,53;,
 3;53,55,58;,
 3;59,58,55;,
 3;60,61,62;,
 3;63,64,61;,
 3;61,60,63;,
 3;65,63,60;,
 3;66,67,64;,
 3;64,63,66;,
 3;68,66,63;,
 3;63,65,68;,
 3;69,68,65;,
 3;7,9,67;,
 3;67,66,7;,
 3;5,7,66;,
 3;66,68,5;,
 3;3,5,68;,
 3;68,69,3;,
 3;0,3,69;,
 3;70,71,72;,
 3;73,74,71;,
 3;71,70,73;,
 3;75,73,70;,
 3;76,77,74;,
 3;74,73,76;,
 3;78,76,73;,
 3;73,75,78;,
 3;79,78,75;,
 3;80,81,82;,
 3;81,83,84;,
 3;84,82,81;,
 3;82,84,85;,
 3;83,86,87;,
 3;87,84,83;,
 3;84,87,88;,
 3;88,85,84;,
 3;85,88,89;,
 3;86,28,26;,
 3;26,87,86;,
 3;87,26,24;,
 3;24,88,87;,
 3;88,24,22;,
 3;22,89,88;,
 3;89,22,21;,
 3;90,91,92;,
 3;91,93,94;,
 3;94,92,91;,
 3;92,94,95;,
 3;93,96,97;,
 3;97,94,93;,
 3;94,97,98;,
 3;98,95,94;,
 3;95,98,99;,
 3;96,18,16;,
 3;16,97,96;,
 3;97,16,14;,
 3;14,98,97;,
 3;98,14,12;,
 3;12,99,98;,
 3;99,12,11;,
 3;100,101,102;,
 3;101,103,104;,
 3;104,102,101;,
 3;102,104,105;,
 3;103,106,107;,
 3;107,104,103;,
 3;104,107,108;,
 3;108,105,104;,
 3;105,108,109;,
 3;110,111,112;,
 3;113,114,111;,
 3;111,110,113;,
 3;115,113,110;,
 3;116,117,114;,
 3;114,113,116;,
 3;118,116,113;,
 3;113,115,118;,
 3;119,118,115;,
 3;37,39,117;,
 3;117,116,37;,
 3;35,37,116;,
 3;116,118,35;,
 3;33,35,118;,
 3;118,119,33;,
 3;30,33,119;,
 3;120,46,121;,
 4;120,122,47,46;,
 3;123,47,122;,
 4;123,124,48,47;,
 3;125,48,124;,
 4;125,126,49,48;,
 3;127,49,126;,
 3;128,57,129;,
 4;130,129,57,56;,
 3;130,56,131;,
 4;132,131,56,58;,
 3;132,58,133;,
 4;134,133,58,59;,
 3;134,59,135;,
 3;136,77,137;,
 4;138,137,77,76;,
 3;138,76,139;,
 4;140,139,76,78;,
 3;140,78,141;,
 4;142,141,78,79;,
 3;142,79,143;,
 3;144,106,145;,
 4;144,146,107,106;,
 3;147,107,146;,
 4;147,148,108,107;,
 3;149,108,148;,
 4;149,150,109,108;,
 3;151,109,150;,
 4;152,8,6,153;,
 4;152,153,120,121;,
 3;153,6,154;,
 4;153,154,122,120;,
 4;154,6,4,155;,
 4;154,155,123,122;,
 3;155,4,156;,
 4;155,156,124,123;,
 4;156,4,2,157;,
 4;156,157,125,124;,
 3;157,2,158;,
 4;157,158,126,125;,
 4;158,2,1,159;,
 4;158,159,127,126;,
 4;160,27,29,161;,
 4;160,161,128,129;,
 3;162,27,160;,
 4;162,160,129,130;,
 4;163,25,27,162;,
 4;163,162,130,131;,
 3;164,25,163;,
 4;164,163,131,132;,
 4;165,23,25,164;,
 4;165,164,132,133;,
 3;166,23,165;,
 4;166,165,133,134;,
 4;167,20,23,166;,
 4;167,166,134,135;,
 4;168,17,19,169;,
 4;168,169,136,137;,
 3;170,17,168;,
 4;170,168,137,138;,
 4;171,15,17,170;,
 4;171,170,138,139;,
 3;172,15,171;,
 4;172,171,139,140;,
 4;173,13,15,172;,
 4;173,172,140,141;,
 3;174,13,173;,
 4;174,173,141,142;,
 4;175,10,13,174;,
 4;175,174,142,143;,
 4;176,38,36,177;,
 4;176,177,144,145;,
 3;177,36,178;,
 4;177,178,146,144;,
 4;178,36,34,179;,
 4;178,179,147,146;,
 3;179,34,180;,
 4;179,180,148,147;,
 4;180,34,32,181;,
 4;180,181,149,148;,
 3;181,32,182;,
 4;181,182,150,149;,
 4;182,32,31,183;,
 4;182,183,151,150;,
 4;184,9,8,185;,
 4;184,185,19,18;,
 4;186,29,28,187;,
 4;186,187,39,38;,
 4;188,72,71,189;,
 4;188,189,41,40;,
 4;189,71,74,190;,
 4;189,190,43,41;,
 4;190,74,77,191;,
 4;190,191,46,43;,
 4;192,62,61,193;,
 4;192,193,91,90;,
 4;193,61,64,194;,
 4;193,194,93,91;,
 4;194,64,67,195;,
 4;194,195,96,93;,
 4;195,67,9,184;,
 4;195,184,18,96;,
 4;196,52,51,197;,
 4;196,197,101,100;,
 4;197,51,54,198;,
 4;197,198,103,101;,
 4;198,54,57,199;,
 4;198,199,106,103;,
 4;200,112,111,201;,
 4;200,201,81,80;,
 4;201,111,114,202;,
 4;201,202,83,81;,
 4;202,114,117,203;,
 4;202,203,86,83;,
 4;203,117,39,187;,
 4;203,187,28,86;,
 4;204,121,46,191;,
 4;204,191,77,136;,
 4;205,145,106,199;,
 4;205,199,57,128;,
 4;185,8,152,206;,
 4;185,206,169,19;,
 4;206,152,121,204;,
 4;206,204,136,169;,
 4;186,38,176,207;,
 4;186,207,161,29;,
 4;207,176,145,205;,
 4;207,205,128,161;,
 4;208,1,0,209;,
 4;208,209,210,211;,
 4;212,11,10,213;,
 4;212,213,31,30;,
 4;214,40,42,215;,
 4;214,215,216,217;,
 4;215,42,45,218;,
 4;215,218,219,216;,
 4;218,45,49,220;,
 4;218,220,221,219;,
 4;222,60,62,223;,
 4;222,223,224,225;,
 4;226,65,60,222;,
 4;226,222,225,227;,
 4;228,69,65,226;,
 4;228,226,227,229;,
 4;209,0,69,228;,
 4;209,228,229,210;,
 4;230,70,72,231;,
 4;230,231,100,102;,
 4;232,75,70,230;,
 4;232,230,102,105;,
 4;233,79,75,232;,
 4;233,232,105,109;,
 4;234,90,92,235;,
 4;234,235,110,112;,
 4;235,92,95,236;,
 4;235,236,115,110;,
 4;236,95,99,237;,
 4;236,237,119,115;,
 4;237,99,11,212;,
 4;237,212,30,119;,
 4;238,239,221,220;,
 4;238,220,49,127;,
 4;233,109,151,240;,
 4;233,240,143,79;,
 4;208,211,241,242;,
 4;208,242,159,1;,
 4;242,241,239,238;,
 4;242,238,127,159;,
 4;213,10,175,243;,
 4;213,243,183,31;,
 4;243,175,143,240;,
 4;243,240,151,183;,
 4;214,217,244,245;,
 4;214,245,188,40;,
 4;245,244,100,231;,
 4;245,231,72,188;,
 4;234,112,200,246;,
 4;234,246,192,90;,
 4;246,247,224,223;,
 4;246,223,62,192;;
 
 MeshMaterialList {
  12;
  296;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  10,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  10,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  10,
  1,
  1,
  1,
  1,
  1,
  10,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  10,
  1,
  10,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Documents\\Visual Studio 2015\\Projects\\3D�l����\\data\\TEXTURE\\���ʕ�.jpeg";
   }
  }
  Material {
   0.179200;0.156800;0.091200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.746400;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.778400;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.012800;0.000000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.787200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.373600;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.000000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.251200;0.392000;0.232000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.339200;0.339200;0.339200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.690400;0.467200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  234;
  -0.254108;0.935176;0.246727;,
  0.254587;0.935056;0.246688;,
  -0.254072;0.935072;-0.247159;,
  0.254551;0.934952;-0.247120;,
  -0.191476;-0.092700;-0.977110;,
  0.193957;-0.092747;-0.976616;,
  -0.191300;-0.085820;-0.977773;,
  0.194060;-0.085816;-0.977229;,
  -0.253987;-0.935096;-0.247157;,
  0.254546;-0.934956;-0.247112;,
  -0.254029;-0.935217;0.246653;,
  0.254588;-0.935077;0.246608;,
  -0.191300;-0.085820;0.977773;,
  0.194060;-0.085816;0.977229;,
  -0.191476;-0.092700;0.977110;,
  0.193957;-0.092747;0.976616;,
  0.977140;-0.088874;0.193131;,
  0.977778;-0.081969;0.192953;,
  0.976712;-0.088924;-0.195262;,
  0.977307;-0.081969;-0.195325;,
  -0.977778;-0.081969;0.192953;,
  -0.977140;-0.088874;0.193131;,
  -0.977307;-0.081969;-0.195325;,
  -0.976712;-0.088924;-0.195262;,
  -0.336048;0.683557;-0.647936;,
  0.337185;0.683278;-0.647640;,
  -0.266356;0.354136;-0.896461;,
  0.268038;0.353964;-0.896027;,
  -0.214530;0.234042;-0.948262;,
  0.216335;0.233997;-0.947863;,
  -0.335938;-0.683597;-0.647952;,
  0.337265;-0.683271;-0.647606;,
  -0.266200;-0.354131;-0.896509;,
  0.268163;-0.353930;-0.896003;,
  -0.218199;-0.148450;-0.964548;,
  0.220413;-0.148369;-0.964056;,
  -0.336048;0.683557;0.647936;,
  0.337185;0.683278;0.647640;,
  -0.266356;0.354136;0.896461;,
  0.268038;0.353964;0.896027;,
  -0.214530;0.234042;0.948262;,
  0.216335;0.233997;0.947863;,
  -0.335938;-0.683597;0.647952;,
  0.337265;-0.683271;0.647606;,
  -0.266200;-0.354131;0.896509;,
  0.268163;-0.353930;0.896003;,
  -0.218199;-0.148450;0.964548;,
  0.220413;-0.148369;0.964056;,
  0.666630;0.671956;0.322613;,
  0.666372;0.671727;-0.323621;,
  0.905014;0.339922;0.255738;,
  0.904652;0.339784;-0.257200;,
  0.951983;0.223664;0.209052;,
  0.951648;0.223630;-0.210610;,
  0.666645;-0.671988;0.322515;,
  0.666344;-0.671722;-0.323692;,
  0.905055;-0.339917;0.255601;,
  0.904632;-0.339755;-0.257309;,
  0.966917;-0.141409;0.212308;,
  0.966506;-0.141343;-0.214217;,
  -0.666630;0.671956;0.322613;,
  -0.666372;0.671727;-0.323621;,
  -0.905014;0.339922;0.255738;,
  -0.904652;0.339784;-0.257200;,
  -0.951983;0.223664;0.209052;,
  -0.951648;0.223630;-0.210610;,
  -0.666645;-0.671988;0.322515;,
  -0.666344;-0.671722;-0.323692;,
  -0.905055;-0.339917;0.255601;,
  -0.904632;-0.339755;-0.257309;,
  -0.966917;-0.141409;0.212308;,
  -0.966506;-0.141343;-0.214217;,
  0.374177;-0.087902;-0.923182;,
  0.373618;-0.100072;-0.922169;,
  0.723929;-0.087221;-0.684339;,
  0.722620;-0.105967;-0.683075;,
  0.936770;-0.084083;-0.339695;,
  0.935808;-0.095875;-0.339222;,
  0.374177;-0.087902;0.923182;,
  0.373618;-0.100072;0.922169;,
  0.723929;-0.087221;0.684339;,
  0.722620;-0.105967;0.683075;,
  0.936770;-0.084083;0.339695;,
  0.935808;-0.095875;0.339222;,
  -0.374177;-0.087902;-0.923182;,
  -0.373618;-0.100072;-0.922169;,
  -0.723929;-0.087221;-0.684339;,
  -0.722620;-0.105967;-0.683075;,
  -0.936770;-0.084083;-0.339695;,
  -0.935808;-0.095875;-0.339222;,
  -0.374177;-0.087902;0.923182;,
  -0.373618;-0.100072;0.922169;,
  -0.723929;-0.087221;0.684339;,
  -0.722620;-0.105967;0.683075;,
  -0.936770;-0.084083;0.339695;,
  -0.935808;-0.095875;0.339222;,
  0.664435;0.398757;-0.632076;,
  0.856037;0.242941;-0.456268;,
  0.494594;0.250208;-0.832330;,
  -0.664435;0.398757;-0.632076;,
  -0.856037;0.242941;-0.456268;,
  -0.494594;0.250208;-0.832330;,
  0.664439;-0.398741;-0.632081;,
  0.870276;-0.163332;-0.464696;,
  0.504126;-0.168699;-0.846993;,
  0.664435;0.398757;0.632076;,
  0.856037;0.242941;0.456268;,
  0.494594;0.250208;0.832330;,
  -0.664439;-0.398741;-0.632081;,
  -0.870276;-0.163332;-0.464696;,
  -0.504126;-0.168699;-0.846993;,
  0.664439;-0.398741;0.632081;,
  0.870276;-0.163332;0.464696;,
  0.504126;-0.168699;0.846993;,
  -0.664435;0.398757;0.632076;,
  -0.856037;0.242941;0.456268;,
  -0.494594;0.250208;0.832330;,
  -0.664439;-0.398741;0.632081;,
  -0.870276;-0.163332;0.464696;,
  -0.504126;-0.168699;0.846993;,
  -0.190403;0.114794;-0.974971;,
  0.192602;0.114810;-0.974537;,
  -0.190403;0.114794;0.974971;,
  0.192602;0.114810;0.974537;,
  0.975203;0.110116;0.191974;,
  0.974827;0.110129;-0.193864;,
  -0.975203;0.110116;0.191974;,
  -0.974827;0.110129;-0.193864;,
  -0.238554;0.118003;-0.963933;,
  0.238554;0.118003;-0.963933;,
  -0.238554;0.118003;0.963933;,
  0.238554;0.118003;0.963933;,
  0.970564;0.112066;0.213182;,
  0.970564;0.112066;-0.213182;,
  -0.970564;0.112066;0.213182;,
  -0.970564;0.112066;-0.213182;,
  0.428732;0.125939;-0.894611;,
  0.784295;0.129006;-0.606827;,
  0.912609;0.121316;-0.390419;,
  0.428732;0.125939;0.894611;,
  0.784295;0.129006;0.606827;,
  0.912609;0.121316;0.390419;,
  -0.428732;0.125939;-0.894611;,
  -0.784295;0.129006;-0.606827;,
  -0.912609;0.121316;-0.390419;,
  -0.428732;0.125939;0.894611;,
  -0.784295;0.129006;0.606827;,
  -0.912609;0.121316;0.390419;,
  0.650875;0.130421;-0.747899;,
  -0.650875;0.130421;-0.747899;,
  0.650875;0.130421;0.747899;,
  -0.650875;0.130421;0.747899;,
  -0.191877;-0.042081;-0.980516;,
  0.194099;-0.042111;-0.980078;,
  -0.191877;-0.042081;0.980516;,
  0.194099;-0.042111;0.980078;,
  0.980287;-0.040372;0.193410;,
  0.979907;-0.040404;-0.195319;,
  -0.980287;-0.040372;0.193410;,
  -0.979907;-0.040404;-0.195319;,
  0.431800;-0.046898;-0.900749;,
  0.789947;-0.048152;-0.611281;,
  0.975915;-0.040376;-0.214384;,
  0.431800;-0.046898;0.900749;,
  0.789947;-0.048152;0.611281;,
  0.975915;-0.040376;0.214384;,
  -0.431800;-0.046898;-0.900749;,
  -0.789947;-0.048152;-0.611281;,
  -0.975915;-0.040376;-0.214384;,
  -0.431800;-0.046898;0.900749;,
  -0.789947;-0.048152;0.611281;,
  -0.975915;-0.040376;0.214384;,
  0.918393;-0.045148;-0.393086;,
  0.655719;-0.048728;-0.753431;,
  0.240047;-0.042589;-0.969827;,
  -0.918393;-0.045148;-0.393086;,
  -0.655719;-0.048728;-0.753431;,
  -0.240047;-0.042589;-0.969827;,
  0.918393;-0.045148;0.393086;,
  0.655719;-0.048728;0.753431;,
  0.240047;-0.042589;0.969827;,
  -0.918393;-0.045148;0.393086;,
  -0.655719;-0.048728;0.753431;,
  -0.240047;-0.042589;0.969827;,
  -0.236332;0.971672;-0.000444;,
  0.236332;0.971672;-0.000444;,
  -0.236286;-0.971684;-0.000518;,
  0.236286;-0.971684;-0.000518;,
  0.995822;-0.091289;-0.002173;,
  0.996335;-0.085509;-0.002418;,
  -0.996335;-0.085509;-0.002418;,
  -0.995822;-0.091289;-0.002173;,
  0.689841;0.723960;-0.001349;,
  0.925610;0.378475;-0.001897;,
  0.972073;0.234672;-0.001992;,
  0.689825;-0.723974;-0.001575;,
  0.925618;-0.378454;-0.002214;,
  0.986482;-0.163851;-0.002445;,
  -0.689841;0.723960;-0.001349;,
  -0.925610;0.378475;-0.001897;,
  -0.972073;0.234672;-0.001992;,
  -0.689825;-0.723974;-0.001575;,
  -0.925618;-0.378454;-0.002214;,
  -0.986482;-0.163851;-0.002445;,
  0.993560;0.113291;-0.001926;,
  -0.993560;0.113291;-0.001926;,
  0.999144;-0.041332;-0.001946;,
  -0.999144;-0.041332;-0.001946;,
  0.000494;0.973659;0.228007;,
  0.000494;0.973659;-0.228007;,
  0.002528;-0.093532;-0.995613;,
  0.002813;-0.088295;-0.996090;,
  0.000577;-0.973669;-0.227966;,
  0.000577;-0.973669;0.227966;,
  0.002813;-0.088295;0.996090;,
  0.002528;-0.093532;0.995613;,
  0.001534;0.735870;-0.677121;,
  0.002190;0.391505;-0.920173;,
  0.002312;0.242295;-0.970200;,
  0.001791;-0.735886;-0.677104;,
  0.002556;-0.391487;-0.920180;,
  0.002840;-0.170426;-0.985366;,
  0.001534;0.735870;0.677121;,
  0.002190;0.391505;0.920173;,
  0.002312;0.242295;0.970200;,
  0.001791;-0.735886;0.677104;,
  0.002556;-0.391487;0.920180;,
  0.002840;-0.170426;0.985366;,
  0.002240;0.116149;-0.993229;,
  0.002240;0.116149;0.993229;,
  0.002264;-0.042279;-0.999103;,
  0.002264;-0.042279;0.999103;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  296;
  4;7,5,73,72;,
  4;72,73,75,74;,
  4;74,75,77,76;,
  4;76,77,18,19;,
  4;15,13,78,79;,
  4;79,78,80,81;,
  4;81,80,82,83;,
  4;83,82,17,16;,
  4;4,6,84,85;,
  4;85,84,86,87;,
  4;87,86,88,89;,
  4;89,88,22,23;,
  4;12,14,91,90;,
  4;90,91,93,92;,
  4;92,93,95,94;,
  4;94,95,21,20;,
  3;3,49,25;,
  3;49,51,96;,
  3;96,25,49;,
  3;25,96,27;,
  3;51,53,97;,
  3;97,96,51;,
  3;96,97,98;,
  3;98,27,96;,
  3;27,98,29;,
  3;24,61,2;,
  3;99,63,61;,
  3;61,24,99;,
  3;26,99,24;,
  3;100,65,63;,
  3;63,99,100;,
  3;101,100,99;,
  3;99,26,101;,
  3;28,101,26;,
  3;31,55,9;,
  3;102,57,55;,
  3;55,31,102;,
  3;33,102,31;,
  3;103,59,57;,
  3;57,102,103;,
  3;104,103,102;,
  3;102,33,104;,
  3;35,104,33;,
  3;76,19,59;,
  3;59,103,76;,
  3;74,76,103;,
  3;103,104,74;,
  3;72,74,104;,
  3;104,35,72;,
  3;7,72,35;,
  3;37,48,1;,
  3;105,50,48;,
  3;48,37,105;,
  3;39,105,37;,
  3;106,52,50;,
  3;50,105,106;,
  3;107,106,105;,
  3;105,39,107;,
  3;41,107,39;,
  3;8,67,30;,
  3;67,69,108;,
  3;108,30,67;,
  3;30,108,32;,
  3;69,71,109;,
  3;109,108,69;,
  3;108,109,110;,
  3;110,32,108;,
  3;32,110,34;,
  3;71,22,88;,
  3;88,109,71;,
  3;109,88,86;,
  3;86,110,109;,
  3;110,86,84;,
  3;84,34,110;,
  3;34,84,6;,
  3;11,54,43;,
  3;54,56,111;,
  3;111,43,54;,
  3;43,111,45;,
  3;56,58,112;,
  3;112,111,56;,
  3;111,112,113;,
  3;113,45,111;,
  3;45,113,47;,
  3;58,17,82;,
  3;82,112,58;,
  3;112,82,80;,
  3;80,113,112;,
  3;113,80,78;,
  3;78,47,113;,
  3;47,78,13;,
  3;0,60,36;,
  3;60,62,114;,
  3;114,36,60;,
  3;36,114,38;,
  3;62,64,115;,
  3;115,114,62;,
  3;114,115,116;,
  3;116,38,114;,
  3;38,116,40;,
  3;42,66,10;,
  3;117,68,66;,
  3;66,42,117;,
  3;44,117,42;,
  3;118,70,68;,
  3;68,117,118;,
  3;119,118,117;,
  3;117,44,119;,
  3;46,119,44;,
  3;94,20,70;,
  3;70,118,94;,
  3;92,94,118;,
  3;118,119,92;,
  3;90,92,119;,
  3;119,46,90;,
  3;12,90,46;,
  3;133,53,125;,
  4;133,138,97,53;,
  3;137,97,138;,
  4;137,148,98,97;,
  3;136,98,148;,
  4;136,129,29,98;,
  3;121,29,129;,
  3;127,65,135;,
  4;144,135,65,100;,
  3;144,100,143;,
  4;149,143,100,101;,
  3;149,101,142;,
  4;128,142,101,28;,
  3;128,28,120;,
  3;124,52,132;,
  4;141,132,52,106;,
  3;141,106,140;,
  4;150,140,106,107;,
  3;150,107,139;,
  4;131,139,107,41;,
  3;131,41,123;,
  3;134,64,126;,
  4;134,147,115,64;,
  3;146,115,147;,
  4;146,151,116,115;,
  3;145,116,151;,
  4;145,130,40,116;,
  3;122,40,130;,
  4;157,18,77,162;,
  4;157,162,133,125;,
  3;162,77,172;,
  4;162,172,138,133;,
  4;172,77,75,161;,
  4;172,161,137,138;,
  3;161,75,173;,
  4;161,173,148,137;,
  4;173,75,73,160;,
  4;173,160,136,148;,
  3;160,73,174;,
  4;160,174,129,136;,
  4;174,73,5,153;,
  4;174,153,121,129;,
  4;168,89,23,159;,
  4;168,159,127,135;,
  3;175,89,168;,
  4;175,168,135,144;,
  4;167,87,89,175;,
  4;167,175,144,143;,
  3;176,87,167;,
  4;176,167,143,149;,
  4;166,85,87,176;,
  4;166,176,149,142;,
  3;177,85,166;,
  4;177,166,142,128;,
  4;152,4,85,177;,
  4;152,177,128,120;,
  4;165,83,16,156;,
  4;165,156,124,132;,
  3;178,83,165;,
  4;178,165,132,141;,
  4;164,81,83,178;,
  4;164,178,141,140;,
  3;179,81,164;,
  4;179,164,140,150;,
  4;163,79,81,179;,
  4;163,179,150,139;,
  3;180,79,163;,
  4;180,163,139,131;,
  4;155,15,79,180;,
  4;155,180,131,123;,
  4;158,21,95,171;,
  4;158,171,134,126;,
  3;171,95,181;,
  4;171,181,147,134;,
  4;181,95,93,170;,
  4;181,170,146,147;,
  3;170,93,182;,
  4;170,182,151,146;,
  4;182,93,91,169;,
  4;182,169,145,151;,
  3;169,91,183;,
  4;169,183,130,145;,
  4;183,91,14,154;,
  4;183,154,122,130;,
  4;189,19,18,188;,
  4;189,188,16,17;,
  4;191,23,22,190;,
  4;191,190,20,21;,
  4;185,1,48,192;,
  4;185,192,49,3;,
  4;192,48,50,193;,
  4;192,193,51,49;,
  4;193,50,52,194;,
  4;193,194,53,51;,
  4;187,9,55,195;,
  4;187,195,54,11;,
  4;195,55,57,196;,
  4;195,196,56,54;,
  4;196,57,59,197;,
  4;196,197,58,56;,
  4;197,59,19,189;,
  4;197,189,17,58;,
  4;184,2,61,198;,
  4;184,198,60,0;,
  4;198,61,63,199;,
  4;198,199,62,60;,
  4;199,63,65,200;,
  4;199,200,64,62;,
  4;186,10,66,201;,
  4;186,201,67,8;,
  4;201,66,68,202;,
  4;201,202,69,67;,
  4;202,68,70,203;,
  4;202,203,71,69;,
  4;203,70,20,190;,
  4;203,190,22,71;,
  4;204,125,53,194;,
  4;204,194,52,124;,
  4;205,126,64,200;,
  4;205,200,65,127;,
  4;188,18,157,206;,
  4;188,206,156,16;,
  4;206,157,125,204;,
  4;206,204,124,156;,
  4;191,21,158,207;,
  4;191,207,159,23;,
  4;207,158,126,205;,
  4;207,205,127,159;,
  4;210,5,7,211;,
  4;210,211,6,4;,
  4;214,13,15,215;,
  4;214,215,14,12;,
  4;209,3,25,216;,
  4;209,216,24,2;,
  4;216,25,27,217;,
  4;216,217,26,24;,
  4;217,27,29,218;,
  4;217,218,28,26;,
  4;219,31,9,212;,
  4;219,212,8,30;,
  4;220,33,31,219;,
  4;220,219,30,32;,
  4;221,35,33,220;,
  4;221,220,32,34;,
  4;211,7,35,221;,
  4;211,221,34,6;,
  4;222,37,1,208;,
  4;222,208,0,36;,
  4;223,39,37,222;,
  4;223,222,36,38;,
  4;224,41,39,223;,
  4;224,223,38,40;,
  4;213,11,43,225;,
  4;213,225,42,10;,
  4;225,43,45,226;,
  4;225,226,44,42;,
  4;226,45,47,227;,
  4;226,227,46,44;,
  4;227,47,13,214;,
  4;227,214,12,46;,
  4;228,120,28,218;,
  4;228,218,29,121;,
  4;224,40,122,229;,
  4;224,229,123,41;,
  4;210,4,152,230;,
  4;210,230,153,5;,
  4;230,152,120,228;,
  4;230,228,121,153;,
  4;215,15,155,231;,
  4;215,231,154,14;,
  4;231,155,123,229;,
  4;231,229,122,154;,
  4;209,2,184,232;,
  4;209,232,185,3;,
  4;232,184,0,208;,
  4;232,208,1,185;,
  4;213,10,186,233;,
  4;213,233,187,11;,
  4;233,186,8,212;,
  4;233,212,9,187;;
 }
 MeshTextureCoords {
  248;
  0.102774;0.819260;,
  0.102774;0.708616;,
  0.111043;0.708616;,
  0.111044;0.819260;,
  0.120240;0.708616;,
  0.120240;0.819260;,
  0.129501;0.708616;,
  0.129501;0.819260;,
  0.137937;0.708616;,
  0.137938;0.819260;,
  0.397226;0.708616;,
  0.397226;0.819260;,
  0.388956;0.819260;,
  0.388957;0.708616;,
  0.379760;0.819260;,
  0.379760;0.708616;,
  0.370499;0.819260;,
  0.370499;0.708616;,
  0.362062;0.819260;,
  0.362063;0.708616;,
  0.897226;0.708616;,
  0.897226;0.819260;,
  0.888956;0.819260;,
  0.888957;0.708616;,
  0.879760;0.819260;,
  0.879760;0.708616;,
  0.870499;0.819260;,
  0.870499;0.708616;,
  0.862062;0.819260;,
  0.862063;0.708616;,
  0.602774;0.819260;,
  0.602774;0.708616;,
  0.611043;0.708616;,
  0.611044;0.819260;,
  0.620240;0.708616;,
  0.620240;0.819260;,
  0.629501;0.708616;,
  0.629501;0.819260;,
  0.637937;0.708616;,
  0.637938;0.819260;,
  0.120240;0.500979;,
  0.127507;0.503649;,
  0.113012;0.503649;,
  0.133177;0.511255;,
  0.120241;0.511255;,
  0.107428;0.511255;,
  0.136731;0.522637;,
  0.126050;0.522637;,
  0.114455;0.522637;,
  0.103950;0.522637;,
  0.886988;0.503649;,
  0.872493;0.503649;,
  0.879760;0.500979;,
  0.879759;0.511255;,
  0.866823;0.511255;,
  0.892572;0.511255;,
  0.873950;0.522637;,
  0.863269;0.522637;,
  0.885545;0.522637;,
  0.896050;0.522637;,
  0.113012;0.847032;,
  0.127508;0.847032;,
  0.120240;0.849320;,
  0.120240;0.840515;,
  0.133177;0.840515;,
  0.107428;0.840515;,
  0.126050;0.830764;,
  0.136731;0.830764;,
  0.114455;0.830764;,
  0.103950;0.830764;,
  0.386988;0.503649;,
  0.372493;0.503649;,
  0.379760;0.500979;,
  0.379759;0.511255;,
  0.366823;0.511255;,
  0.392572;0.511255;,
  0.373950;0.522637;,
  0.363269;0.522637;,
  0.385545;0.522637;,
  0.396050;0.522637;,
  0.879760;0.849320;,
  0.872492;0.847032;,
  0.886988;0.847032;,
  0.866823;0.840515;,
  0.879760;0.840515;,
  0.892572;0.840515;,
  0.863269;0.830764;,
  0.873950;0.830764;,
  0.885545;0.830764;,
  0.896050;0.830764;,
  0.379760;0.849320;,
  0.372492;0.847032;,
  0.386988;0.847032;,
  0.366823;0.840515;,
  0.379760;0.840515;,
  0.392572;0.840515;,
  0.363269;0.830764;,
  0.373950;0.830764;,
  0.385545;0.830764;,
  0.396050;0.830764;,
  0.620240;0.500979;,
  0.627507;0.503649;,
  0.613012;0.503649;,
  0.633177;0.511255;,
  0.620241;0.511255;,
  0.607428;0.511255;,
  0.636731;0.522637;,
  0.626050;0.522637;,
  0.614455;0.522637;,
  0.603950;0.522637;,
  0.613012;0.847032;,
  0.627508;0.847032;,
  0.620240;0.849320;,
  0.620240;0.840515;,
  0.633177;0.840515;,
  0.607428;0.840515;,
  0.626050;0.830764;,
  0.636731;0.830764;,
  0.614455;0.830764;,
  0.603950;0.830764;,
  0.134071;0.570748;,
  0.137165;0.570748;,
  0.127290;0.570748;,
  0.123944;0.570748;,
  0.116546;0.570748;,
  0.113226;0.570748;,
  0.106552;0.570748;,
  0.103527;0.570748;,
  0.862835;0.570748;,
  0.865929;0.570748;,
  0.872710;0.570748;,
  0.876056;0.570748;,
  0.883454;0.570748;,
  0.886774;0.570748;,
  0.893448;0.570748;,
  0.896473;0.570748;,
  0.362835;0.570748;,
  0.365929;0.570748;,
  0.372710;0.570748;,
  0.376056;0.570748;,
  0.383454;0.570748;,
  0.386774;0.570748;,
  0.393448;0.570748;,
  0.396473;0.570748;,
  0.634071;0.570748;,
  0.637165;0.570748;,
  0.627290;0.570748;,
  0.623944;0.570748;,
  0.616546;0.570748;,
  0.613226;0.570748;,
  0.606552;0.570748;,
  0.603527;0.570748;,
  0.137310;0.596183;,
  0.133201;0.596183;,
  0.127703;0.596183;,
  0.123248;0.596183;,
  0.117239;0.596183;,
  0.112819;0.596183;,
  0.107404;0.596183;,
  0.103386;0.596183;,
  0.866799;0.596183;,
  0.862690;0.596183;,
  0.872297;0.596183;,
  0.876752;0.596183;,
  0.882761;0.596183;,
  0.887181;0.596183;,
  0.892596;0.596183;,
  0.896614;0.596183;,
  0.366799;0.596183;,
  0.362690;0.596183;,
  0.372297;0.596183;,
  0.376752;0.596183;,
  0.382761;0.596183;,
  0.387181;0.596183;,
  0.392596;0.596183;,
  0.396614;0.596183;,
  0.637310;0.596183;,
  0.633201;0.596183;,
  0.627703;0.596183;,
  0.623248;0.596183;,
  0.617239;0.596183;,
  0.612819;0.596183;,
  0.607404;0.596183;,
  0.603386;0.596183;,
  0.248564;0.819260;,
  0.248770;0.708616;,
  0.751230;0.708616;,
  0.751436;0.819260;,
  0.248462;0.500979;,
  0.248597;0.503649;,
  0.248693;0.511255;,
  0.248751;0.522637;,
  0.248205;0.849320;,
  0.248362;0.847032;,
  0.248475;0.840515;,
  0.248542;0.830764;,
  0.751538;0.500979;,
  0.751403;0.503649;,
  0.751307;0.511255;,
  0.751249;0.522637;,
  0.751795;0.849320;,
  0.751638;0.847032;,
  0.751525;0.840515;,
  0.751458;0.830764;,
  0.248914;0.570748;,
  0.751086;0.570748;,
  0.248916;0.596183;,
  0.751084;0.596183;,
  0.001492;0.708616;,
  0.001742;0.819260;,
  -0.102774;0.819260;,
  -0.102774;0.708616;,
  0.498258;0.819260;,
  0.498508;0.708616;,
  0.001865;0.500979;,
  0.001702;0.503649;,
  -0.113012;0.503649;,
  -0.120240;0.500979;,
  0.001585;0.511255;,
  -0.107428;0.511255;,
  0.001515;0.522637;,
  -0.103950;0.522637;,
  0.001987;0.847032;,
  0.002177;0.849320;,
  -0.120240;0.849320;,
  -0.113012;0.847032;,
  0.001850;0.840515;,
  -0.107428;0.840515;,
  0.001769;0.830764;,
  -0.103950;0.830764;,
  0.498298;0.503649;,
  0.498135;0.500979;,
  0.498415;0.511255;,
  0.498485;0.522637;,
  0.497823;0.849320;,
  0.498013;0.847032;,
  0.498150;0.840515;,
  0.498231;0.830764;,
  0.001317;0.570748;,
  -0.103527;0.570748;,
  0.498683;0.570748;,
  -0.103386;0.596183;,
  0.001315;0.596183;,
  0.498685;0.596183;,
  -0.248462;0.500979;,
  0.142213;0.500979;,
  0.142213;0.849320;,
  -0.248205;0.849320;;
 }
}
