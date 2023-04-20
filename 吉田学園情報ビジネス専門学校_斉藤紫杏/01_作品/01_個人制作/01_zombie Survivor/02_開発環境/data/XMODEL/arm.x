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
 224;
 0.77314;-0.10082;-0.92758;,
 0.85187;-0.14964;-0.92758;,
 0.77314;-0.14964;-1.01632;,
 0.91862;-0.28871;-0.92758;,
 0.87601;-0.28871;-1.04352;,
 0.77314;-0.28871;-1.09155;,
 0.96322;-0.49679;-0.92758;,
 0.93775;-0.49679;-1.03470;,
 0.86818;-0.49679;-1.11312;,
 0.77314;-0.49679;-1.14182;,
 1.08678;-1.38728;-1.02488;,
 1.06948;-1.38728;-1.12293;,
 1.02020;-1.38728;-1.20605;,
 0.94645;-1.38728;-1.26159;,
 0.85946;-1.38728;-1.28109;,
 -0.87272;-0.14964;-1.01632;,
 -0.95145;-0.14964;-0.92758;,
 -0.87272;-0.10082;-0.92758;,
 -0.97559;-0.28871;-1.04352;,
 -1.01820;-0.28871;-0.92758;,
 -0.87272;-0.28871;-1.09155;,
 -1.03733;-0.49679;-1.03470;,
 -1.06279;-0.49679;-0.92758;,
 -0.96776;-0.49679;-1.11312;,
 -0.87272;-0.49679;-1.14182;,
 -1.16905;-1.38728;-1.12293;,
 -1.18636;-1.38728;-1.02488;,
 -1.11978;-1.38728;-1.20605;,
 -1.04603;-1.38728;-1.26159;,
 -0.95904;-1.38728;-1.28109;,
 0.62767;-6.41850;-0.83667;,
 0.69249;-6.41850;-0.76362;,
 0.62767;-6.45868;-0.76362;,
 0.71236;-6.30402;-0.85906;,
 0.74744;-6.30402;-0.76362;,
 0.62767;-6.30402;-0.89860;,
 0.76319;-6.13270;-0.85180;,
 0.78415;-6.13270;-0.76362;,
 0.70591;-6.13270;-0.91636;,
 0.62767;-6.13270;-0.93998;,
 0.78415;-5.93062;-0.83667;,
 0.79705;-5.93062;-0.76362;,
 0.74744;-5.93062;-0.89860;,
 0.69249;-5.93062;-0.93998;,
 0.62767;-5.93062;-0.95451;,
 0.77314;-0.14964;1.01632;,
 0.85187;-0.14964;0.92758;,
 0.77314;-0.10082;0.92758;,
 0.87601;-0.28871;1.04352;,
 0.91862;-0.28871;0.92758;,
 0.77314;-0.28871;1.09155;,
 0.93775;-0.49679;1.03470;,
 0.96322;-0.49679;0.92758;,
 0.86818;-0.49679;1.11312;,
 0.77314;-0.49679;1.14182;,
 1.06948;-1.38728;1.12293;,
 1.08678;-1.38728;1.02488;,
 1.02020;-1.38728;1.20605;,
 0.94645;-1.38728;1.26159;,
 0.85946;-1.38728;1.28109;,
 -0.72725;-6.45868;-0.76362;,
 -0.79207;-6.41850;-0.76362;,
 -0.72725;-6.41850;-0.83667;,
 -0.84702;-6.30402;-0.76362;,
 -0.81194;-6.30402;-0.85906;,
 -0.72725;-6.30402;-0.89860;,
 -0.88373;-6.13270;-0.76362;,
 -0.86277;-6.13270;-0.85180;,
 -0.80549;-6.13270;-0.91636;,
 -0.72725;-6.13270;-0.93998;,
 -0.89663;-5.93062;-0.76362;,
 -0.88373;-5.93062;-0.83667;,
 -0.84702;-5.93062;-0.89860;,
 -0.79207;-5.93062;-0.93998;,
 -0.72725;-5.93062;-0.95451;,
 0.62767;-6.45868;0.76362;,
 0.69249;-6.41850;0.76362;,
 0.62767;-6.41850;0.83667;,
 0.74744;-6.30402;0.76362;,
 0.71236;-6.30402;0.85906;,
 0.62767;-6.30402;0.89860;,
 0.78415;-6.13270;0.76362;,
 0.76319;-6.13270;0.85180;,
 0.70591;-6.13270;0.91636;,
 0.62767;-6.13270;0.93998;,
 0.79705;-5.93062;0.76362;,
 0.78415;-5.93062;0.83667;,
 0.74744;-5.93062;0.89860;,
 0.69249;-5.93062;0.93998;,
 0.62767;-5.93062;0.95451;,
 -0.87272;-0.10082;0.92758;,
 -0.95145;-0.14964;0.92758;,
 -0.87272;-0.14964;1.01632;,
 -1.01820;-0.28871;0.92758;,
 -0.97559;-0.28871;1.04352;,
 -0.87272;-0.28871;1.09155;,
 -1.06279;-0.49679;0.92758;,
 -1.03733;-0.49679;1.03470;,
 -0.96776;-0.49679;1.11312;,
 -0.87272;-0.49679;1.14182;,
 -1.18636;-1.38728;1.02488;,
 -1.16905;-1.38728;1.12293;,
 -1.11978;-1.38728;1.20605;,
 -1.04603;-1.38728;1.26159;,
 -0.95904;-1.38728;1.28109;,
 -0.72725;-6.41850;0.83667;,
 -0.79207;-6.41850;0.76362;,
 -0.72725;-6.45868;0.76362;,
 -0.81194;-6.30402;0.85906;,
 -0.84702;-6.30402;0.76362;,
 -0.72725;-6.30402;0.89860;,
 -0.86277;-6.13270;0.85180;,
 -0.88373;-6.13270;0.76362;,
 -0.80549;-6.13270;0.91636;,
 -0.72725;-6.13270;0.93998;,
 -0.88373;-5.93062;0.83667;,
 -0.89663;-5.93062;0.76362;,
 -0.84702;-5.93062;0.89860;,
 -0.79207;-5.93062;0.93998;,
 -0.72725;-5.93062;0.95451;,
 0.77314;-3.93684;-1.15947;,
 0.85187;-3.93684;-1.14182;,
 0.91862;-3.93684;-1.09155;,
 0.96322;-3.93684;-1.01632;,
 0.97888;-3.93684;-0.92758;,
 0.77314;-3.93684;1.15947;,
 0.85187;-3.93684;1.14182;,
 0.91862;-3.93684;1.09155;,
 0.96322;-3.93684;1.01632;,
 0.97888;-3.93684;0.92758;,
 -0.87272;-3.93684;-1.15947;,
 -0.95145;-3.93684;-1.14182;,
 -1.01820;-3.93684;-1.09155;,
 -1.06279;-3.93684;-1.01632;,
 -1.07846;-3.93684;-0.92758;,
 -0.87272;-3.93684;1.15947;,
 -0.95145;-3.93684;1.14182;,
 -1.01820;-3.93684;1.09155;,
 -1.06279;-3.93684;1.01632;,
 -1.07846;-3.93684;0.92758;,
 0.85946;-2.07234;-1.28109;,
 0.94645;-2.07234;-1.26159;,
 1.02020;-2.07234;-1.20605;,
 1.06948;-2.07234;-1.12293;,
 1.08678;-2.07234;-1.02488;,
 0.94645;-2.07234;1.26159;,
 0.85946;-2.07234;1.28109;,
 1.02020;-2.07234;1.20605;,
 1.06948;-2.07234;1.12293;,
 1.08678;-2.07234;1.02488;,
 -1.04603;-2.07234;-1.26159;,
 -0.95904;-2.07234;-1.28109;,
 -1.11978;-2.07234;-1.20605;,
 -1.16905;-2.07234;-1.12293;,
 -1.18636;-2.07234;-1.02488;,
 -0.95904;-2.07234;1.28109;,
 -1.04603;-2.07234;1.26159;,
 -1.11978;-2.07234;1.20605;,
 -1.16905;-2.07234;1.12293;,
 -1.18636;-2.07234;1.02488;,
 1.01150;-0.10082;-0.01515;,
 1.11303;-0.14964;-0.01515;,
 1.19911;-0.28871;-0.01515;,
 1.25663;-0.49679;-0.01515;,
 1.41598;-1.38728;-0.01515;,
 0.82390;-6.45868;-0.01515;,
 0.90748;-6.41850;-0.01515;,
 0.97835;-6.30402;-0.01515;,
 1.02570;-6.13270;-0.01515;,
 1.04232;-5.93062;-0.01515;,
 -1.11108;-0.10082;-0.01515;,
 -1.21261;-0.14964;-0.01515;,
 -1.29869;-0.28871;-0.01515;,
 -1.35620;-0.49679;-0.01515;,
 -1.51556;-1.38728;-0.01515;,
 -0.92348;-6.45868;-0.01515;,
 -1.00706;-6.41850;-0.01515;,
 -1.07793;-6.30402;-0.01515;,
 -1.12527;-6.13270;-0.01515;,
 -1.14190;-5.93062;-0.01515;,
 1.27683;-3.93684;-0.01515;,
 -1.37641;-3.93684;-0.01515;,
 1.41598;-2.07234;-0.01515;,
 -1.51556;-2.07234;-0.01515;,
 0.02438;-0.10082;-1.11557;,
 0.02438;-0.14964;-1.22229;,
 -0.87272;-0.14964;-1.01632;,
 -0.87272;-0.10082;-0.92758;,
 0.02438;-0.28871;-1.31277;,
 -0.87272;-0.28871;-1.09155;,
 0.02438;-0.49679;-1.37323;,
 -0.87272;-0.49679;-1.14182;,
 0.02438;-1.38728;-1.54072;,
 -0.95904;-1.38728;-1.28109;,
 0.02438;-6.41850;-1.00623;,
 0.02438;-6.45868;-0.91837;,
 -0.72725;-6.45868;-0.76362;,
 -0.72725;-6.41850;-0.83667;,
 0.02438;-6.30402;-1.08071;,
 -0.72725;-6.30402;-0.89860;,
 0.02438;-6.13270;-1.13049;,
 -0.72725;-6.13270;-0.93998;,
 0.02438;-5.93062;-1.14796;,
 -0.72725;-5.93062;-0.95451;,
 0.02438;-0.14964;1.22229;,
 0.02438;-0.10082;1.11557;,
 0.02438;-0.28871;1.31277;,
 0.02438;-0.49679;1.37323;,
 0.02438;-1.38728;1.54072;,
 0.02438;-6.45868;0.91837;,
 0.02438;-6.41850;1.00623;,
 0.02438;-6.30402;1.08071;,
 0.02438;-6.13270;1.13049;,
 0.02438;-5.93062;1.14796;,
 -0.87272;-3.93684;-1.15947;,
 0.02438;-3.93684;-1.39445;,
 0.02438;-3.93684;1.39445;,
 0.02438;-2.07234;-1.54072;,
 -0.95904;-2.07234;-1.28109;,
 0.02438;-2.07234;1.54072;,
 -1.11108;-0.10082;-0.01515;,
 0.02438;-0.10082;-0.01515;,
 0.02438;-6.45868;-0.01515;,
 -0.92348;-6.45868;-0.01515;;
 
 272;
 3;0,1,2;,
 3;1,3,4;,
 3;4,2,1;,
 3;2,4,5;,
 3;3,6,7;,
 3;7,4,3;,
 3;4,7,8;,
 3;8,5,4;,
 3;5,8,9;,
 3;6,10,11;,
 3;11,7,6;,
 3;7,11,12;,
 3;12,8,7;,
 3;8,12,13;,
 3;13,9,8;,
 3;9,13,14;,
 3;15,16,17;,
 3;18,19,16;,
 3;16,15,18;,
 3;20,18,15;,
 3;21,22,19;,
 3;19,18,21;,
 3;23,21,18;,
 3;18,20,23;,
 3;24,23,20;,
 3;25,26,22;,
 3;22,21,25;,
 3;27,25,21;,
 3;21,23,27;,
 3;28,27,23;,
 3;23,24,28;,
 3;29,28,24;,
 3;30,31,32;,
 3;33,34,31;,
 3;31,30,33;,
 3;35,33,30;,
 3;36,37,34;,
 3;34,33,36;,
 3;38,36,33;,
 3;33,35,38;,
 3;39,38,35;,
 3;40,41,37;,
 3;37,36,40;,
 3;42,40,36;,
 3;36,38,42;,
 3;43,42,38;,
 3;38,39,43;,
 3;44,43,39;,
 3;45,46,47;,
 3;48,49,46;,
 3;46,45,48;,
 3;50,48,45;,
 3;51,52,49;,
 3;49,48,51;,
 3;53,51,48;,
 3;48,50,53;,
 3;54,53,50;,
 3;55,56,52;,
 3;52,51,55;,
 3;57,55,51;,
 3;51,53,57;,
 3;58,57,53;,
 3;53,54,58;,
 3;59,58,54;,
 3;60,61,62;,
 3;61,63,64;,
 3;64,62,61;,
 3;62,64,65;,
 3;63,66,67;,
 3;67,64,63;,
 3;64,67,68;,
 3;68,65,64;,
 3;65,68,69;,
 3;66,70,71;,
 3;71,67,66;,
 3;67,71,72;,
 3;72,68,67;,
 3;68,72,73;,
 3;73,69,68;,
 3;69,73,74;,
 3;75,76,77;,
 3;76,78,79;,
 3;79,77,76;,
 3;77,79,80;,
 3;78,81,82;,
 3;82,79,78;,
 3;79,82,83;,
 3;83,80,79;,
 3;80,83,84;,
 3;81,85,86;,
 3;86,82,81;,
 3;82,86,87;,
 3;87,83,82;,
 3;83,87,88;,
 3;88,84,83;,
 3;84,88,89;,
 3;90,91,92;,
 3;91,93,94;,
 3;94,92,91;,
 3;92,94,95;,
 3;93,96,97;,
 3;97,94,93;,
 3;94,97,98;,
 3;98,95,94;,
 3;95,98,99;,
 3;96,100,101;,
 3;101,97,96;,
 3;97,101,102;,
 3;102,98,97;,
 3;98,102,103;,
 3;103,99,98;,
 3;99,103,104;,
 3;105,106,107;,
 3;108,109,106;,
 3;106,105,108;,
 3;110,108,105;,
 3;111,112,109;,
 3;109,108,111;,
 3;113,111,108;,
 3;108,110,113;,
 3;114,113,110;,
 3;115,116,112;,
 3;112,111,115;,
 3;117,115,111;,
 3;111,113,117;,
 3;118,117,113;,
 3;113,114,118;,
 3;119,118,114;,
 4;120,121,43,44;,
 4;121,122,42,43;,
 4;122,123,40,42;,
 4;123,124,41,40;,
 4;125,89,88,126;,
 4;126,88,87,127;,
 4;127,87,86,128;,
 4;128,86,85,129;,
 4;130,74,73,131;,
 4;131,73,72,132;,
 4;132,72,71,133;,
 4;133,71,70,134;,
 4;135,136,118,119;,
 4;136,137,117,118;,
 4;137,138,115,117;,
 4;138,139,116,115;,
 4;140,14,13,141;,
 4;140,141,121,120;,
 4;141,13,12,142;,
 4;141,142,122,121;,
 4;142,12,11,143;,
 4;142,143,123,122;,
 4;143,11,10,144;,
 4;143,144,124,123;,
 4;145,58,59,146;,
 4;145,146,125,126;,
 4;147,57,58,145;,
 4;147,145,126,127;,
 4;148,55,57,147;,
 4;148,147,127,128;,
 4;149,56,55,148;,
 4;149,148,128,129;,
 4;150,28,29,151;,
 4;150,151,130,131;,
 4;152,27,28,150;,
 4;152,150,131,132;,
 4;153,25,27,152;,
 4;153,152,132,133;,
 4;154,26,25,153;,
 4;154,153,133,134;,
 4;155,104,103,156;,
 4;155,156,136,135;,
 4;156,103,102,157;,
 4;156,157,137,136;,
 4;157,102,101,158;,
 4;157,158,138,137;,
 4;158,101,100,159;,
 4;158,159,139,138;,
 4;160,47,46,161;,
 4;160,161,1,0;,
 4;161,46,49,162;,
 4;161,162,3,1;,
 4;162,49,52,163;,
 4;162,163,6,3;,
 4;163,52,56,164;,
 4;163,164,10,6;,
 4;165,32,31,166;,
 4;165,166,76,75;,
 4;166,31,34,167;,
 4;166,167,78,76;,
 4;167,34,37,168;,
 4;167,168,81,78;,
 4;168,37,41,169;,
 4;168,169,85,81;,
 4;170,17,16,171;,
 4;170,171,91,90;,
 4;171,16,19,172;,
 4;171,172,93,91;,
 4;172,19,22,173;,
 4;172,173,96,93;,
 4;173,22,26,174;,
 4;173,174,100,96;,
 4;175,107,106,176;,
 4;175,176,61,60;,
 4;176,106,109,177;,
 4;176,177,63,61;,
 4;177,109,112,178;,
 4;177,178,66,63;,
 4;178,112,116,179;,
 4;178,179,70,66;,
 4;169,41,124,180;,
 4;169,180,129,85;,
 4;181,134,70,179;,
 4;181,179,116,139;,
 4;164,56,149,182;,
 4;164,182,144,10;,
 4;182,149,129,180;,
 4;182,180,124,144;,
 4;174,26,154,183;,
 4;174,183,159,100;,
 4;183,154,134,181;,
 4;183,181,139,159;,
 4;184,0,2,185;,
 4;184,185,186,187;,
 4;185,2,5,188;,
 4;185,188,189,186;,
 4;188,5,9,190;,
 4;188,190,191,189;,
 4;190,9,14,192;,
 4;190,192,193,191;,
 4;194,30,32,195;,
 4;194,195,196,197;,
 4;198,35,30,194;,
 4;198,194,197,199;,
 4;200,39,35,198;,
 4;200,198,199,201;,
 4;202,44,39,200;,
 4;202,200,201,203;,
 4;204,45,47,205;,
 4;204,205,90,92;,
 4;206,50,45,204;,
 4;206,204,92,95;,
 4;207,54,50,206;,
 4;207,206,95,99;,
 4;208,59,54,207;,
 4;208,207,99,104;,
 4;209,75,77,210;,
 4;209,210,105,107;,
 4;210,77,80,211;,
 4;210,211,110,105;,
 4;211,80,84,212;,
 4;211,212,114,110;,
 4;212,84,89,213;,
 4;212,213,119,114;,
 4;202,203,214,215;,
 4;202,215,120,44;,
 4;216,135,119,213;,
 4;216,213,89,125;,
 4;192,14,140,217;,
 4;192,217,218,193;,
 4;217,140,120,215;,
 4;217,215,214,218;,
 4;208,104,155,219;,
 4;208,219,146,59;,
 4;219,155,135,216;,
 4;219,216,125,146;,
 4;184,187,220,221;,
 4;184,221,160,0;,
 4;221,220,90,205;,
 4;221,205,47,160;,
 4;209,107,175,222;,
 4;209,222,165,75;,
 4;222,223,196,195;,
 4;222,195,32,165;;
 
 MeshMaterialList {
  10;
  272;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Documents\\Visual Studio 2015\\Projects\\3D�l����\\data\\TEXTURE\\���ʕ�.jpeg";
   }
  }
  Material {
   0.178824;0.156863;0.090980;1.000000;;
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
 }
 MeshNormals {
  210;
  -0.275832;0.925030;0.261220;,
  0.280602;0.923729;0.260745;,
  -0.275723;0.924769;-0.262258;,
  0.280492;0.923469;-0.261782;,
  -0.235453;0.087218;-0.967964;,
  0.256829;0.087242;-0.962511;,
  -0.233031;-0.095025;-0.967815;,
  0.259838;-0.094847;-0.960983;,
  -0.275222;-0.924887;-0.262369;,
  0.281036;-0.923302;-0.261788;,
  -0.275354;-0.925204;0.261109;,
  0.281169;-0.923617;0.260529;,
  -0.233031;-0.095025;0.967815;,
  0.259838;-0.094847;0.960983;,
  -0.235453;0.087218;0.967964;,
  0.256829;0.087242;0.962511;,
  0.968208;0.080308;0.236903;,
  0.967777;-0.086973;0.236313;,
  0.967155;0.080334;-0.241160;,
  0.966464;-0.086950;-0.241636;,
  -0.967773;-0.086979;0.236324;,
  -0.968196;0.080315;0.236951;,
  -0.966460;-0.086956;-0.241648;,
  -0.967142;0.080341;-0.241208;,
  -0.372934;0.665418;-0.646637;,
  0.383895;0.662435;-0.643276;,
  -0.304289;0.341971;-0.889081;,
  0.320274;0.340048;-0.884190;,
  -0.253586;0.201059;-0.946187;,
  0.270888;0.200438;-0.941512;,
  -0.371918;-0.665718;-0.646913;,
  0.385279;-0.662080;-0.642814;,
  -0.302842;-0.342123;-0.889516;,
  0.322323;-0.339778;-0.883549;,
  -0.254346;-0.143298;-0.956438;,
  0.276159;-0.142312;-0.950517;,
  -0.372934;0.665418;0.646637;,
  0.383895;0.662435;0.643276;,
  -0.304289;0.341971;0.889081;,
  0.320274;0.340048;0.884190;,
  -0.253586;0.201059;0.946187;,
  0.270888;0.200438;0.941512;,
  -0.371918;-0.665718;0.646913;,
  0.385279;-0.662080;0.642814;,
  -0.302842;-0.342123;0.889516;,
  0.322323;-0.339778;0.883549;,
  -0.254346;-0.143298;0.956438;,
  0.276159;-0.142312;0.950517;,
  0.683933;0.642568;0.345458;,
  0.683264;0.642033;-0.347769;,
  0.906068;0.315064;0.282444;,
  0.905164;0.314732;-0.285695;,
  0.952908;0.183580;0.241381;,
  0.952040;0.183493;-0.244847;,
  0.683948;-0.642678;0.345223;,
  0.683136;-0.642028;-0.348030;,
  0.906166;-0.315086;0.282108;,
  0.905067;-0.314683;-0.286057;,
  0.961264;-0.130077;0.243007;,
  0.960176;-0.129905;-0.247359;,
  -0.683933;0.642568;0.345458;,
  -0.683264;0.642033;-0.347769;,
  -0.906079;0.315048;0.282429;,
  -0.905174;0.314717;-0.285680;,
  -0.952914;0.183566;0.241366;,
  -0.952046;0.183479;-0.244833;,
  -0.683949;-0.642678;0.345223;,
  -0.683136;-0.642028;-0.348030;,
  -0.906168;-0.315081;0.282107;,
  -0.905069;-0.314678;-0.286056;,
  -0.961264;-0.130077;0.243005;,
  -0.960177;-0.129905;-0.247357;,
  0.391857;-0.093656;-0.915247;,
  0.391356;0.109760;-0.913670;,
  0.742545;-0.091319;-0.663542;,
  0.740940;0.112383;-0.662102;,
  0.942469;-0.085803;-0.323095;,
  0.941156;0.100408;-0.322712;,
  0.391857;-0.093656;0.915247;,
  0.391356;0.109760;0.913670;,
  0.742545;-0.091319;0.663542;,
  0.740940;0.112383;0.662102;,
  0.942469;-0.085803;0.323095;,
  0.941156;0.100408;0.322712;,
  -0.391857;-0.093656;-0.915247;,
  -0.391356;0.109760;-0.913670;,
  -0.742551;-0.091318;-0.663535;,
  -0.740963;0.112382;-0.662075;,
  -0.942468;-0.085802;-0.323096;,
  -0.941161;0.100405;-0.322699;,
  -0.391857;-0.093656;0.915247;,
  -0.391356;0.109760;0.913670;,
  -0.742551;-0.091318;0.663535;,
  -0.740963;0.112382;0.662075;,
  -0.942468;-0.085802;0.323096;,
  -0.941161;0.100405;0.322699;,
  0.686930;0.376112;-0.621825;,
  0.874366;0.201343;-0.441526;,
  0.519170;0.213968;-0.827454;,
  -0.686930;0.376112;-0.621825;,
  -0.874388;0.201333;-0.441488;,
  -0.519170;0.213968;-0.827454;,
  0.686906;-0.376110;-0.621853;,
  0.882374;-0.150046;-0.445984;,
  0.524880;-0.160119;-0.835980;,
  0.686930;0.376112;0.621825;,
  0.874366;0.201343;0.441526;,
  0.519170;0.213968;0.827454;,
  -0.686906;-0.376110;-0.621853;,
  -0.882374;-0.150046;-0.445984;,
  -0.524880;-0.160119;-0.835980;,
  0.686906;-0.376110;0.621853;,
  0.882374;-0.150046;0.445984;,
  0.524880;-0.160119;0.835980;,
  -0.686930;0.376112;0.621825;,
  -0.874388;0.201333;0.441488;,
  -0.519170;0.213968;0.827454;,
  -0.686906;-0.376110;0.621853;,
  -0.882374;-0.150046;0.445984;,
  -0.524880;-0.160119;0.835980;,
  -0.234739;-0.095597;-0.967346;,
  0.258539;-0.095754;-0.961243;,
  -0.234739;-0.095597;0.967346;,
  0.258539;-0.095754;0.961243;,
  0.967486;-0.088102;0.237083;,
  0.966310;-0.088149;-0.241817;,
  -0.967477;-0.088103;0.237121;,
  -0.966300;-0.088150;-0.241855;,
  0.417306;-0.101926;-0.903032;,
  0.740983;-0.104407;-0.663358;,
  0.933576;-0.093954;-0.345845;,
  0.417306;-0.101926;0.903032;,
  0.740983;-0.104407;0.663358;,
  0.933576;-0.093954;0.345845;,
  -0.417306;-0.101926;-0.903032;,
  -0.741007;-0.104406;-0.663331;,
  -0.933574;-0.093952;-0.345849;,
  -0.417306;-0.101926;0.903032;,
  -0.741007;-0.104406;0.663331;,
  -0.933574;-0.093952;0.345849;,
  -0.236642;-0.037220;-0.970884;,
  0.258164;-0.037274;-0.965382;,
  -0.236642;-0.037220;0.970884;,
  0.258164;-0.037274;0.965382;,
  0.970638;-0.034286;0.238088;,
  0.969576;-0.034307;-0.242373;,
  -0.970626;-0.034287;0.238137;,
  -0.969564;-0.034308;-0.242422;,
  0.419234;-0.039705;-0.907009;,
  0.744407;-0.040678;-0.666486;,
  0.937065;-0.036581;-0.347232;,
  0.419234;-0.039705;0.907009;,
  0.744407;-0.040678;0.666486;,
  0.937065;-0.036581;0.347232;,
  -0.419234;-0.039705;-0.907009;,
  -0.744437;-0.040677;-0.666452;,
  -0.937064;-0.036581;-0.347237;,
  -0.419234;-0.039705;0.907009;,
  -0.744437;-0.040677;0.666452;,
  -0.937064;-0.036581;0.347237;,
  -0.247150;0.968977;-0.001065;,
  0.247150;0.968977;-0.001065;,
  -0.247092;-0.968991;-0.001293;,
  0.247092;-0.968991;-0.001293;,
  0.996174;0.087283;-0.004385;,
  0.995477;-0.094843;-0.005482;,
  -0.995476;-0.094855;-0.005482;,
  -0.996173;0.087289;-0.004385;,
  0.704936;0.709265;-0.003111;,
  0.931822;0.362892;-0.004246;,
  0.978527;0.206069;-0.004469;,
  0.704875;-0.709322;-0.003779;,
  0.931819;-0.362886;-0.005158;,
  0.987713;-0.156178;-0.005618;,
  -0.704936;0.709265;-0.003111;,
  -0.931830;0.362871;-0.004246;,
  -0.978531;0.206052;-0.004469;,
  -0.704875;-0.709322;-0.003779;,
  -0.931824;-0.362873;-0.005158;,
  -0.987713;-0.156177;-0.005618;,
  0.995404;-0.095642;-0.004875;,
  -0.995404;-0.095642;-0.004875;,
  0.999297;-0.037241;-0.004414;,
  -0.999297;-0.037241;-0.004414;,
  0.004933;0.973128;0.230212;,
  0.004933;0.973128;-0.230212;,
  0.022056;0.091960;-0.995518;,
  0.027655;-0.100893;-0.994513;,
  0.006013;-0.973135;-0.230155;,
  0.006013;-0.973135;0.230155;,
  0.027655;-0.100893;0.994513;,
  0.022056;0.091960;0.995518;,
  0.015010;0.733331;-0.679706;,
  0.021094;0.388226;-0.921323;,
  0.022413;0.220160;-0.975206;,
  0.018296;-0.733346;-0.679609;,
  0.025710;-0.388182;-0.921224;,
  0.028303;-0.168753;-0.985252;,
  0.015010;0.733331;0.679706;,
  0.021094;0.388226;0.921323;,
  0.022413;0.220160;0.975206;,
  0.018296;-0.733346;0.679609;,
  0.025710;-0.388182;0.921224;,
  0.028303;-0.168753;0.985252;,
  0.024557;-0.100584;-0.994625;,
  0.024557;-0.100584;0.994625;,
  0.022211;-0.039165;-0.998986;,
  0.022211;-0.039165;0.998986;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  272;
  3;3,49,25;,
  3;49,51,96;,
  3;96,25,49;,
  3;25,96,27;,
  3;51,53,97;,
  3;97,96,51;,
  3;96,97,98;,
  3;98,27,96;,
  3;27,98,29;,
  3;53,18,77;,
  3;77,97,53;,
  3;97,77,75;,
  3;75,98,97;,
  3;98,75,73;,
  3;73,29,98;,
  3;29,73,5;,
  3;24,61,2;,
  3;99,63,61;,
  3;61,24,99;,
  3;26,99,24;,
  3;100,65,63;,
  3;63,99,100;,
  3;101,100,99;,
  3;99,26,101;,
  3;28,101,26;,
  3;89,23,65;,
  3;65,100,89;,
  3;87,89,100;,
  3;100,101,87;,
  3;85,87,101;,
  3;101,28,85;,
  3;4,85,28;,
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
  3;83,16,52;,
  3;52,106,83;,
  3;81,83,106;,
  3;106,107,81;,
  3;79,81,107;,
  3;107,41,79;,
  3;15,79,41;,
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
  3;64,21,95;,
  3;95,115,64;,
  3;115,95,93;,
  3;93,116,115;,
  3;116,93,91;,
  3;91,40,116;,
  3;40,91,14;,
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
  4;121,128,72,7;,
  4;128,129,74,72;,
  4;129,130,76,74;,
  4;130,125,19,76;,
  4;123,13,78,131;,
  4;131,78,80,132;,
  4;132,80,82,133;,
  4;133,82,17,124;,
  4;120,6,84,134;,
  4;134,84,86,135;,
  4;135,86,88,136;,
  4;136,88,22,127;,
  4;122,137,90,12;,
  4;137,138,92,90;,
  4;138,139,94,92;,
  4;139,126,20,94;,
  4;141,5,73,148;,
  4;141,148,128,121;,
  4;148,73,75,149;,
  4;148,149,129,128;,
  4;149,75,77,150;,
  4;149,150,130,129;,
  4;150,77,18,145;,
  4;150,145,125,130;,
  4;151,79,15,143;,
  4;151,143,123,131;,
  4;152,81,79,151;,
  4;152,151,131,132;,
  4;153,83,81,152;,
  4;153,152,132,133;,
  4;144,16,83,153;,
  4;144,153,133,124;,
  4;154,85,4,140;,
  4;154,140,120,134;,
  4;155,87,85,154;,
  4;155,154,134,135;,
  4;156,89,87,155;,
  4;156,155,135,136;,
  4;147,23,89,156;,
  4;147,156,136,127;,
  4;142,14,91,157;,
  4;142,157,137,122;,
  4;157,91,93,158;,
  4;157,158,138,137;,
  4;158,93,95,159;,
  4;158,159,139,138;,
  4;159,95,21,146;,
  4;159,146,126,139;,
  4;161,1,48,168;,
  4;161,168,49,3;,
  4;168,48,50,169;,
  4;168,169,51,49;,
  4;169,50,52,170;,
  4;169,170,53,51;,
  4;170,52,16,164;,
  4;170,164,18,53;,
  4;163,9,55,171;,
  4;163,171,54,11;,
  4;171,55,57,172;,
  4;171,172,56,54;,
  4;172,57,59,173;,
  4;172,173,58,56;,
  4;173,59,19,165;,
  4;173,165,17,58;,
  4;160,2,61,174;,
  4;160,174,60,0;,
  4;174,61,63,175;,
  4;174,175,62,60;,
  4;175,63,65,176;,
  4;175,176,64,62;,
  4;176,65,23,167;,
  4;176,167,21,64;,
  4;162,10,66,177;,
  4;162,177,67,8;,
  4;177,66,68,178;,
  4;177,178,69,67;,
  4;178,68,70,179;,
  4;178,179,71,69;,
  4;179,70,20,166;,
  4;179,166,22,71;,
  4;165,19,125,180;,
  4;165,180,124,17;,
  4;181,127,22,166;,
  4;181,166,20,126;,
  4;164,16,144,182;,
  4;164,182,145,18;,
  4;182,144,124,180;,
  4;182,180,125,145;,
  4;167,23,147,183;,
  4;167,183,146,21;,
  4;183,147,127,181;,
  4;183,181,126,146;,
  4;185,3,25,192;,
  4;185,192,24,2;,
  4;192,25,27,193;,
  4;192,193,26,24;,
  4;193,27,29,194;,
  4;193,194,28,26;,
  4;194,29,5,186;,
  4;194,186,4,28;,
  4;195,31,9,188;,
  4;195,188,8,30;,
  4;196,33,31,195;,
  4;196,195,30,32;,
  4;197,35,33,196;,
  4;197,196,32,34;,
  4;187,7,35,197;,
  4;187,197,34,6;,
  4;198,37,1,184;,
  4;198,184,0,36;,
  4;199,39,37,198;,
  4;199,198,36,38;,
  4;200,41,39,199;,
  4;200,199,38,40;,
  4;191,15,41,200;,
  4;191,200,40,14;,
  4;189,11,43,201;,
  4;189,201,42,10;,
  4;201,43,45,202;,
  4;201,202,44,42;,
  4;202,45,47,203;,
  4;202,203,46,44;,
  4;203,47,13,190;,
  4;203,190,12,46;,
  4;187,6,120,204;,
  4;187,204,121,7;,
  4;205,122,12,190;,
  4;205,190,13,123;,
  4;186,5,141,206;,
  4;186,206,140,4;,
  4;206,141,121,204;,
  4;206,204,120,140;,
  4;191,14,142,207;,
  4;191,207,143,15;,
  4;207,142,122,205;,
  4;207,205,123,143;,
  4;185,2,160,208;,
  4;185,208,161,3;,
  4;208,160,0,184;,
  4;208,184,1,161;,
  4;189,10,162,209;,
  4;189,209,163,11;,
  4;209,162,8,188;,
  4;209,188,9,163;;
 }
 MeshTextureCoords {
  224;
  0.110587;0.505041;,
  0.118233;0.507482;,
  0.103503;0.507482;,
  0.124228;0.514436;,
  0.111146;0.514436;,
  0.098083;0.514436;,
  0.128000;0.524840;,
  0.117183;0.524840;,
  0.105424;0.524840;,
  0.094729;0.524840;,
  0.129664;0.569364;,
  0.121121;0.569364;,
  0.111744;0.569364;,
  0.102437;0.569364;,
  0.094047;0.569364;,
  0.887075;0.507482;,
  0.872978;0.507482;,
  0.879848;0.505041;,
  0.880352;0.514436;,
  0.867593;0.514436;,
  0.892658;0.514436;,
  0.874798;0.524840;,
  0.864205;0.524840;,
  0.886100;0.524840;,
  0.896135;0.524840;,
  0.871798;0.569364;,
  0.863398;0.569364;,
  0.880901;0.569364;,
  0.889824;0.569364;,
  0.897725;0.569364;,
  0.102437;0.820925;,
  0.117232;0.820925;,
  0.109497;0.822934;,
  0.110185;0.815201;,
  0.123296;0.815201;,
  0.097039;0.815201;,
  0.116276;0.806635;,
  0.127111;0.806635;,
  0.104468;0.806635;,
  0.093703;0.806635;,
  0.119845;0.796531;,
  0.128409;0.796531;,
  0.110425;0.796531;,
  0.101054;0.796531;,
  0.092578;0.796531;,
  0.396497;0.507482;,
  0.381767;0.507482;,
  0.389413;0.505041;,
  0.388854;0.514436;,
  0.375772;0.514436;,
  0.401917;0.514436;,
  0.382816;0.524840;,
  0.372000;0.524840;,
  0.394576;0.524840;,
  0.405271;0.524840;,
  0.378879;0.569364;,
  0.370336;0.569364;,
  0.388256;0.569364;,
  0.397563;0.569364;,
  0.405953;0.569364;,
  0.878882;0.822934;,
  0.872090;0.820925;,
  0.886117;0.820925;,
  0.866766;0.815201;,
  0.879487;0.815201;,
  0.891712;0.815201;,
  0.863416;0.806635;,
  0.873982;0.806635;,
  0.885234;0.806635;,
  0.895198;0.806635;,
  0.862277;0.796531;,
  0.870648;0.796531;,
  0.879701;0.796531;,
  0.888558;0.796531;,
  0.896377;0.796531;,
  0.390503;0.822934;,
  0.382768;0.820925;,
  0.397563;0.820925;,
  0.376704;0.815201;,
  0.389815;0.815201;,
  0.402961;0.815201;,
  0.372889;0.806635;,
  0.383724;0.806635;,
  0.395532;0.806635;,
  0.406297;0.806635;,
  0.371591;0.796531;,
  0.380155;0.796531;,
  0.389575;0.796531;,
  0.398946;0.796531;,
  0.407421;0.796531;,
  0.620152;0.505041;,
  0.627022;0.507482;,
  0.612925;0.507482;,
  0.632407;0.514436;,
  0.619648;0.514436;,
  0.607342;0.514436;,
  0.635795;0.524840;,
  0.625202;0.524840;,
  0.613900;0.524840;,
  0.603865;0.524840;,
  0.636602;0.569364;,
  0.628202;0.569364;,
  0.619099;0.569364;,
  0.610176;0.569364;,
  0.602275;0.569364;,
  0.613883;0.820925;,
  0.627910;0.820925;,
  0.621118;0.822934;,
  0.620513;0.815201;,
  0.633234;0.815201;,
  0.608288;0.815201;,
  0.626018;0.806635;,
  0.636584;0.806635;,
  0.614766;0.806635;,
  0.604802;0.806635;,
  0.629352;0.796531;,
  0.637723;0.796531;,
  0.620299;0.796531;,
  0.611442;0.796531;,
  0.603623;0.796531;,
  0.093599;0.696842;,
  0.102015;0.696842;,
  0.111342;0.696842;,
  0.120732;0.696842;,
  0.129282;0.696842;,
  0.406401;0.696842;,
  0.397985;0.696842;,
  0.388658;0.696842;,
  0.379268;0.696842;,
  0.370718;0.696842;,
  0.897310;0.696842;,
  0.889434;0.696842;,
  0.880531;0.696842;,
  0.871443;0.696842;,
  0.863052;0.696842;,
  0.602690;0.696842;,
  0.610566;0.696842;,
  0.619469;0.696842;,
  0.628557;0.696842;,
  0.636948;0.696842;,
  0.094047;0.603617;,
  0.102437;0.603617;,
  0.111744;0.603617;,
  0.121121;0.603617;,
  0.129664;0.603617;,
  0.397563;0.603617;,
  0.405953;0.603617;,
  0.388256;0.603617;,
  0.378879;0.603617;,
  0.370336;0.603617;,
  0.889824;0.603617;,
  0.897725;0.603617;,
  0.880901;0.603617;,
  0.871798;0.603617;,
  0.863398;0.603617;,
  0.602275;0.603617;,
  0.610176;0.603617;,
  0.619099;0.603617;,
  0.628202;0.603617;,
  0.636602;0.603617;,
  0.247616;0.505041;,
  0.247834;0.507482;,
  0.247989;0.514436;,
  0.248081;0.524840;,
  0.248297;0.569364;,
  0.247074;0.822934;,
  0.247343;0.820925;,
  0.247536;0.815201;,
  0.247649;0.806635;,
  0.247687;0.796531;,
  0.752170;0.505041;,
  0.751988;0.507482;,
  0.751857;0.514436;,
  0.751778;0.524840;,
  0.751591;0.569364;,
  0.752611;0.822934;,
  0.752394;0.820925;,
  0.752237;0.815201;,
  0.752143;0.806635;,
  0.752111;0.796531;,
  0.248112;0.696842;,
  0.751752;0.696842;,
  0.248297;0.603617;,
  0.751591;0.603617;,
  0.003478;0.505041;,
  0.003174;0.507482;,
  -0.112925;0.507482;,
  -0.120152;0.505041;,
  0.002955;0.514436;,
  -0.107342;0.514436;,
  0.002825;0.524840;,
  -0.103865;0.524840;,
  0.002518;0.569364;,
  -0.102275;0.569364;,
  0.003855;0.820925;,
  0.004224;0.822934;,
  -0.121118;0.822934;,
  -0.113883;0.820925;,
  0.003590;0.815201;,
  -0.108288;0.815201;,
  0.003432;0.806635;,
  -0.104802;0.806635;,
  0.003380;0.796531;,
  -0.103623;0.796531;,
  0.496826;0.507482;,
  0.496522;0.505041;,
  0.497045;0.514436;,
  0.497175;0.524840;,
  0.497482;0.569364;,
  0.495776;0.822934;,
  0.496145;0.820925;,
  0.496410;0.815201;,
  0.496568;0.806635;,
  0.496620;0.796531;,
  -0.102690;0.696842;,
  0.002782;0.696842;,
  0.497218;0.696842;,
  0.002518;0.603617;,
  -0.102275;0.603617;,
  0.497482;0.603617;,
  -0.247830;0.505041;,
  0.161508;0.505041;,
  0.161508;0.822934;,
  -0.247389;0.822934;;
 }
}
