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
 116;
 35.54400;6.84600;-2.01969;,
 35.54400;6.84600;2.01966;,
 35.54400;-0.46662;2.01966;,
 35.54400;-0.46662;-2.01969;,
 -35.54400;6.84600;2.01966;,
 -35.54400;6.84600;-2.01969;,
 -35.54400;-0.46662;-2.01969;,
 -35.54400;-0.46662;2.01966;,
 -27.64266;6.84600;2.01966;,
 -35.54400;6.84600;2.01966;,
 -35.54400;-0.46662;2.01966;,
 -27.64266;-0.46662;2.01966;,
 -27.64266;6.84600;-2.01969;,
 -27.64266;-0.46662;-2.01969;,
 -35.54400;-0.46662;-2.01969;,
 -35.54400;6.84600;-2.01969;,
 -27.64266;-0.46662;2.01966;,
 -35.54400;-0.46662;-2.01969;,
 -27.64266;-0.46662;-2.01969;,
 27.50598;6.84600;2.01969;,
 27.50598;-0.46662;2.01969;,
 35.54400;-0.46662;2.01966;,
 35.54400;6.84600;2.01966;,
 27.50598;6.84600;-2.01969;,
 35.54400;6.84600;-2.01969;,
 35.54400;-0.46662;-2.01969;,
 27.50598;-0.46662;-2.01969;,
 27.50598;-0.46662;2.01969;,
 27.50598;-0.46662;-2.01969;,
 35.54400;-0.46662;-2.01969;,
 -27.64266;97.93422;2.01966;,
 -27.64266;97.93422;-2.01969;,
 -35.54400;97.93422;-2.01969;,
 -35.54400;97.93422;2.01966;,
 27.50598;97.93422;2.01969;,
 35.54400;97.93422;2.01966;,
 35.54400;97.93422;-2.01969;,
 27.50598;97.93422;-2.01969;,
 -35.54400;89.56302;-2.01969;,
 -27.64266;89.56302;-2.01969;,
 -27.64266;6.84600;-2.01969;,
 -35.54400;6.84600;-2.01969;,
 -35.54400;89.56302;2.01966;,
 -27.64266;6.84600;2.01966;,
 -27.64266;89.56302;2.01966;,
 27.50598;89.80999;2.01969;,
 27.50598;6.84600;2.01969;,
 35.54400;89.80999;2.01969;,
 27.50598;89.80999;-2.01969;,
 35.54400;6.84600;-2.01969;,
 35.54400;89.80999;-2.01969;,
 27.50598;6.84600;-2.01969;,
 27.50598;97.93422;-2.01969;,
 27.50598;89.80999;-2.01969;,
 27.50598;97.93422;2.01969;,
 27.50598;89.80999;2.01969;,
 -25.99818;8.55966;-1.15527;,
 25.86153;8.55966;-1.15527;,
 25.86153;8.55966;1.15527;,
 -25.99818;8.55966;1.15527;,
 -25.99143;87.85059;1.15527;,
 -25.99143;87.85059;-1.15527;,
 25.86828;88.09636;-1.15527;,
 25.86828;88.09636;1.15527;,
 25.86828;88.09636;1.15527;,
 25.86828;88.09636;-1.15527;,
 24.31632;86.53713;-0.73380;,
 24.31632;86.53713;0.73380;,
 24.31632;86.53713;0.73380;,
 24.31632;86.53713;-0.73380;,
 24.51846;9.90330;-2.90061;,
 -24.65421;9.90312;-2.90094;,
 -24.43881;10.11891;-0.73380;,
 24.30216;10.11918;-0.73380;,
 -24.65421;9.90312;2.90094;,
 24.51846;9.90330;2.90061;,
 24.30216;10.11918;0.73380;,
 -24.43881;10.11891;0.73380;,
 -24.64113;86.50698;2.90094;,
 -24.42468;86.29110;0.73380;,
 -24.64113;86.50698;-2.90094;,
 -24.42468;86.29110;-0.73380;,
 24.53154;86.75296;-2.90061;,
 24.53154;86.75296;2.90061;,
 24.53154;86.75296;2.90061;,
 24.53154;86.75296;-2.90061;,
 -25.75773;8.80023;-0.73380;,
 25.62108;8.80002;-0.73380;,
 25.62108;8.80002;0.73380;,
 -25.75773;8.80023;0.73380;,
 -25.75026;87.61027;0.73380;,
 -25.75026;87.61027;-0.73380;,
 25.62858;87.85578;-0.73380;,
 25.62858;87.85578;0.73380;,
 25.62858;87.85578;0.73380;,
 25.62858;87.85578;-0.73380;,
 -25.06935;86.55724;-0.35604;,
 25.06935;86.55724;-0.35604;,
 25.06935;9.96219;-0.35604;,
 -25.06935;9.96219;-0.35604;,
 25.06935;86.55724;-0.35604;,
 25.06935;86.55724;0.35604;,
 25.06935;9.96219;0.35604;,
 25.06935;9.96219;-0.35604;,
 25.06935;86.55724;0.35604;,
 -25.06935;86.55724;0.35604;,
 -25.06935;9.96219;0.35604;,
 25.06935;9.96219;0.35604;,
 -25.06935;86.55724;0.35604;,
 -25.06935;86.55724;-0.35604;,
 -25.06935;9.96219;-0.35604;,
 -25.06935;9.96219;0.35604;,
 25.06935;86.55724;-0.35604;,
 -25.06935;86.55724;-0.35604;,
 -25.06935;9.96219;-0.35604;,
 25.06935;9.96219;-0.35604;;
 
 82;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;16,7,17,18;,
 4;19,8,11,20;,
 4;19,20,21,22;,
 4;23,24,25,26;,
 4;23,26,13,12;,
 4;27,16,18,28;,
 4;27,28,29,2;,
 4;30,31,32,33;,
 4;34,35,36,37;,
 4;38,32,31,39;,
 4;38,39,40,41;,
 4;38,41,4,42;,
 4;38,42,33,32;,
 4;42,4,43,44;,
 4;42,44,30,33;,
 4;45,46,1,47;,
 4;45,47,35,34;,
 4;45,34,37,48;,
 4;47,1,49,50;,
 4;47,50,36,35;,
 4;48,37,36,50;,
 4;48,50,49,51;,
 4;52,53,39,31;,
 4;54,52,31,30;,
 4;55,54,30,44;,
 4;53,52,54,55;,
 4;56,57,51,40;,
 4;58,59,43,46;,
 4;59,60,44,43;,
 4;61,56,40,39;,
 4;62,63,45,48;,
 4;57,62,48,51;,
 4;63,58,46,45;,
 4;64,65,53,55;,
 4;60,64,55,44;,
 4;65,61,39,53;,
 4;66,67,63,62;,
 4;68,69,65,64;,
 4;70,71,72,73;,
 4;71,70,57,56;,
 4;74,75,76,77;,
 4;75,74,59,58;,
 4;78,74,77,79;,
 4;74,78,60,59;,
 4;71,80,81,72;,
 4;80,71,56,61;,
 4;82,70,73,66;,
 4;70,82,62,57;,
 4;75,83,67,76;,
 4;83,75,58,63;,
 4;84,78,79,68;,
 4;78,84,64,60;,
 4;80,85,69,81;,
 4;85,80,61,65;,
 4;86,87,73,72;,
 4;88,89,77,76;,
 4;88,87,86,89;,
 4;89,90,79,77;,
 4;91,86,72,81;,
 4;91,90,89,86;,
 4;92,93,67,66;,
 4;87,92,66,73;,
 4;93,88,76,67;,
 4;93,92,87,88;,
 4;94,95,69,68;,
 4;90,94,68,79;,
 4;95,91,81,69;,
 4;95,94,90,91;,
 3;63,67,83;,
 3;64,84,68;,
 3;62,82,66;,
 3;65,69,85;,
 4;96,97,98,99;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;108,101,112,113;,
 4;114,115,102,111;;
 
 MeshMaterialList {
  2;
  82;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.414400;0.210400;0.160000;1.000000;;
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
  72;
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.096338;0.093395;0.990957;,
  0.096341;0.093396;-0.990957;,
  -0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.096664;0.093415;0.990924;,
  -0.096665;0.093417;-0.990923;,
  0.000002;0.000000;1.000000;,
  0.000000;1.000000;0.000000;,
  0.096768;-0.093418;-0.990913;,
  0.096765;-0.093417;0.990914;,
  0.000002;0.000001;1.000000;,
  -0.928155;0.372195;0.000000;,
  -0.096239;-0.093429;0.990964;,
  -0.000004;0.995076;0.099111;,
  -0.000004;0.995076;-0.099111;,
  0.995073;-0.000177;-0.099144;,
  0.995073;-0.000177;0.099144;,
  -0.827394;0.561006;-0.026300;,
  -0.827394;0.561006;0.026300;,
  0.245474;0.237973;0.939740;,
  0.245481;0.237977;-0.939737;,
  -0.246322;0.238040;0.939501;,
  -0.246322;0.238044;-0.939500;,
  0.246513;-0.237980;-0.939466;,
  0.246506;-0.237976;0.939469;,
  -0.586946;0.792220;-0.166977;,
  -0.586946;0.792220;0.166977;,
  -0.922573;0.382063;-0.053723;,
  -0.922573;0.382063;0.053723;,
  0.000000;0.000000;1.000000;,
  0.386011;-0.922494;-0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000004;0.000000;1.000000;,
  0.000003;-0.000000;1.000000;,
  -0.000000;0.000000;1.000000;,
  0.000002;0.000002;1.000000;,
  0.000001;0.000001;1.000000;,
  -0.096240;-0.093430;-0.990964;,
  0.928155;-0.372195;-0.000000;,
  -0.245296;-0.238136;-0.939745;,
  -0.245296;-0.238132;0.939746;,
  0.801568;-0.574299;0.166341;,
  0.801568;-0.574299;-0.166341;,
  0.564948;-0.824709;0.026237;,
  0.564948;-0.824709;-0.026237;,
  0.000004;-0.792438;-0.609953;,
  0.000004;-0.792438;0.609953;,
  -0.791666;0.000101;0.610954;,
  -0.791666;0.000101;-0.610954;,
  -0.995079;0.000177;-0.099084;,
  0.793222;-0.000101;-0.608932;,
  0.849738;-0.399150;-0.344421;,
  -0.995079;0.000177;0.099084;,
  0.849738;-0.399150;0.344421;,
  0.793222;-0.000101;0.608932;,
  0.005001;-0.995063;0.099118;,
  -0.003858;0.792474;0.609893;,
  0.005001;-0.995063;-0.099118;,
  -0.003858;0.792474;-0.609893;,
  0.000004;1.000000;0.000000;,
  1.000000;-0.000095;-0.000000;,
  -0.924326;0.381605;0.000000;,
  -1.000000;0.000095;0.000000;,
  0.004779;-0.999989;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  82;
  4;1,1,1,1;,
  4;0,0,0,0;,
  4;2,31,31,4;,
  4;3,5,5,5;,
  4;33,33,33,33;,
  4;6,2,4,8;,
  4;6,8,34,35;,
  4;7,5,5,5;,
  4;7,5,5,3;,
  4;33,33,33,33;,
  4;33,33,33,33;,
  4;9,9,9,9;,
  4;9,9,9,9;,
  4;5,5,5,10;,
  4;5,10,3,5;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;31,31,2,11;,
  4;31,11,36,31;,
  4;14,6,35,12;,
  4;14,12,37,38;,
  4;13,0,0,13;,
  4;1,1,1,1;,
  4;1,1,1,1;,
  4;39,5,5,5;,
  4;39,5,5,7;,
  4;5,39,10,5;,
  4;9,9,9,9;,
  4;14,38,36,11;,
  4;40,1,1,40;,
  4;22,24,7,3;,
  4;23,21,2,6;,
  4;21,26,11,2;,
  4;25,22,3,10;,
  4;27,28,13,13;,
  4;24,41,39,7;,
  4;42,23,6,14;,
  4;43,44,40,40;,
  4;26,42,14,11;,
  4;41,25,10,39;,
  4;19,20,28,27;,
  4;45,46,44,43;,
  4;16,16,16,16;,
  4;47,47,47,47;,
  4;15,15,15,15;,
  4;48,48,48,48;,
  4;18,18,18,18;,
  4;49,49,49,49;,
  4;17,17,17,17;,
  4;50,50,50,50;,
  4;29,51,51,19;,
  4;52,53,44,52;,
  4;54,30,20,54;,
  4;55,56,56,43;,
  4;57,57,57,45;,
  4;58,58,28,58;,
  4;59,59,46,59;,
  4;60,60,60,27;,
  4;31,31,31,31;,
  4;5,5,5,5;,
  4;61,61,61,61;,
  4;5,5,5,5;,
  4;31,31,31,31;,
  4;62,62,62,62;,
  4;32,32,45,46;,
  4;31,31,31,31;,
  4;5,5,5,5;,
  4;63,63,64,64;,
  4;63,63,19,20;,
  4;5,5,5,5;,
  4;31,31,31,31;,
  4;32,32,65,65;,
  3;28,20,30;,
  3;43,55,45;,
  3;27,29,19;,
  3;44,46,53;,
  4;66,66,66,66;,
  4;67,67,67,67;,
  4;68,68,68,68;,
  4;69,69,69,69;,
  4;70,70,70,70;,
  4;71,71,71,71;;
 }
 MeshTextureCoords {
  116;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.853780;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.853780;1.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.146220;1.000000;,
  0.000000;0.000000;,
  0.146220;0.000000;,
  0.148140;0.000000;,
  0.148140;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.851860;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.851860;1.000000;,
  0.851860;1.000000;,
  0.851860;0.000000;,
  1.000000;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.851860;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.851860;1.000000;,
  0.000000;1.000000;,
  0.146220;1.000000;,
  0.146220;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.146220;0.000000;,
  0.146220;0.000000;,
  0.851860;0.000000;,
  0.851860;0.000000;,
  1.000000;0.000000;,
  0.851860;1.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.851860;1.000000;,
  0.146220;1.000000;,
  0.146220;1.000000;,
  0.146220;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.851860;0.000000;,
  0.146220;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.851860;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.851860;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.146220;1.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.146220;0.000000;,
  0.851860;0.000000;,
  0.851860;0.000000;,
  0.146220;0.000000;,
  0.146220;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.851860;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.851860;0.000000;,
  0.146220;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.851860;1.000000;,
  0.851860;0.000000;,
  0.146220;0.000000;,
  0.146220;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
