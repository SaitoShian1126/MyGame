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
 130;
 0.39442;-0.07733;-0.15999;,
 -1.03890;-0.07733;1.27333;,
 0.39442;-0.07733;1.55885;,
 -1.63261;-0.07733;-0.15999;,
 -1.03890;-0.07733;-1.59332;,
 0.39442;-0.07733;-2.18702;,
 1.82775;-0.07733;-1.59332;,
 2.42145;-0.07733;-0.15999;,
 1.82775;-0.07733;1.27333;,
 -1.21313;0.30260;1.44756;,
 -1.87900;0.30260;-0.16000;,
 0.39442;0.30260;2.11342;,
 -1.21313;0.30260;-1.76755;,
 2.00197;0.30260;1.44755;,
 0.39442;0.30260;-2.43341;,
 2.66784;0.30260;-0.15999;,
 2.00197;0.30260;-1.76754;,
 -1.56807;0.00954;1.49431;,
 -2.38096;0.00954;-0.15999;,
 -2.38096;-2.72451;-0.39892;,
 -1.56807;-2.72451;1.25538;,
 0.39442;-2.72451;2.06827;,
 0.39442;0.00954;2.30720;,
 -1.56807;0.00954;-2.12248;,
 -1.56807;-2.72451;-2.12248;,
 2.35691;-2.72451;1.25538;,
 2.35691;0.00954;1.49431;,
 0.39442;0.00954;-2.93537;,
 0.39442;-2.72451;-2.93537;,
 3.16980;-2.72451;-0.39893;,
 3.16980;0.00954;-0.15999;,
 2.35691;0.00954;-2.12248;,
 2.35691;-2.72451;-2.12248;,
 -1.37292;-4.84723;1.46412;,
 0.39442;-4.84723;2.05650;,
 -2.10497;-4.84723;-0.14949;,
 -1.37292;-4.84723;-2.07890;,
 0.39442;-4.84723;-2.97706;,
 2.16176;-4.84723;-2.07890;,
 2.89382;-4.84723;-0.14948;,
 2.16176;-4.84723;1.46412;,
 -1.15025;-6.88896;1.81065;,
 0.39442;-6.88896;2.39951;,
 -1.79007;-6.88896;0.04023;,
 -1.15025;-6.88896;-2.04600;,
 0.39442;-6.88896;-3.00912;,
 1.93909;-6.88896;-2.04600;,
 2.57892;-6.88896;0.04023;,
 1.93909;-6.88896;1.81065;,
 -0.93558;-10.47292;1.81065;,
 0.39442;-10.47292;2.39951;,
 -1.48649;-10.47292;0.04023;,
 -0.93558;-10.47292;-2.04600;,
 0.39442;-10.47292;-3.00912;,
 1.72443;-10.47292;-2.04600;,
 2.27534;-10.47292;0.04023;,
 1.72443;-10.47292;1.81065;,
 -0.79737;-13.95733;0.94193;,
 0.39442;-13.95733;1.34488;,
 -1.29102;-13.95733;-0.48676;,
 -0.79737;-13.95733;-2.12417;,
 0.39442;-13.95733;-2.90138;,
 1.58622;-13.95733;-2.12417;,
 2.07987;-13.95733;-0.48676;,
 1.58622;-13.95733;0.94192;,
 -0.58670;-17.57740;0.18987;,
 0.39442;-17.57740;0.76320;,
 -0.99309;-18.41739;-0.86405;,
 -0.58670;-18.41739;-2.24820;,
 0.39442;-18.41739;-2.82153;,
 1.37555;-18.41739;-2.24820;,
 1.78194;-18.41739;-0.86405;,
 1.37555;-17.57740;0.18987;,
 -0.59653;-20.35285;0.10290;,
 0.39442;-20.35285;0.84229;,
 0.39442;-19.70575;0.66678;,
 -0.59653;-19.70575;0.16066;,
 -0.83044;-20.35285;-1.42031;,
 -0.83044;-19.70575;-0.93374;,
 -0.47168;-20.60174;-2.86315;,
 -0.47168;-19.70575;-2.15563;,
 0.39442;-20.60174;-3.60254;,
 0.39442;-19.70575;-2.66175;,
 1.26053;-20.60174;-2.86315;,
 1.26053;-19.70575;-2.15563;,
 1.61928;-20.35285;-1.42031;,
 1.61928;-19.70575;-0.93374;,
 1.38538;-20.35285;0.10289;,
 1.38538;-19.70575;0.16066;,
 -0.59654;-21.19284;-0.00187;,
 0.39442;-21.06840;1.01558;,
 -0.83044;-21.19284;-1.99922;,
 -0.64203;-21.19284;-4.40699;,
 0.39442;-21.37951;-5.40433;,
 1.43088;-21.19284;-4.40699;,
 1.61928;-21.19284;-1.99922;,
 1.38538;-21.19284;-0.00187;,
 -0.59654;-22.99408;0.20891;,
 0.39442;-22.69542;0.87127;,
 0.39442;-22.25304;0.98317;,
 -0.59654;-22.25304;0.20891;,
 0.39442;-22.99405;-1.97730;,
 -1.07134;-22.99405;-1.97805;,
 -0.83044;-22.25304;-1.97067;,
 -0.82571;-22.96290;-8.74163;,
 -0.81533;-22.22193;-8.72838;,
 0.39442;-22.96288;-9.14817;,
 0.39442;-22.22193;-9.13644;,
 1.61456;-22.96290;-8.74163;,
 1.60418;-22.22193;-8.72838;,
 1.86019;-22.99405;-1.97805;,
 1.61928;-22.25304;-1.97067;,
 1.38538;-22.99408;0.20891;,
 1.38538;-22.25304;0.20891;,
 0.39442;-21.63501;1.07748;,
 1.38538;-21.63501;0.10482;,
 -0.59654;-21.63501;0.10483;,
 1.61928;-21.63501;-1.98477;,
 -0.83044;-21.63501;-1.98477;,
 1.43088;-21.61927;-5.33257;,
 -0.64203;-21.61927;-5.33257;,
 0.39442;-21.71144;-6.38009;,
 0.39442;-19.03355;0.61601;,
 1.32054;-19.03355;-0.08922;,
 -0.53169;-19.03355;-0.08922;,
 1.70415;-19.03355;-0.89738;,
 -0.91530;-19.03355;-0.89738;,
 1.32054;-19.03355;-2.20392;,
 -0.53169;-19.03355;-2.20392;,
 0.39442;-19.03355;-2.74512;;
 
 136;
 3;0,1,2;,
 3;0,3,1;,
 3;0,4,3;,
 3;0,5,4;,
 3;0,6,5;,
 3;0,7,6;,
 3;0,8,7;,
 3;0,2,8;,
 4;9,1,3,10;,
 4;9,11,2,1;,
 4;10,3,4,12;,
 4;11,13,8,2;,
 4;12,4,5,14;,
 4;13,15,7,8;,
 4;14,5,6,16;,
 4;15,16,6,7;,
 4;17,9,10,18;,
 4;17,18,19,20;,
 4;17,20,21,22;,
 4;17,22,11,9;,
 4;18,10,12,23;,
 4;18,23,24,19;,
 4;22,21,25,26;,
 4;22,26,13,11;,
 4;23,12,14,27;,
 4;23,27,28,24;,
 4;26,25,29,30;,
 4;26,30,15,13;,
 4;27,14,16,31;,
 4;27,31,32,28;,
 4;30,29,32,31;,
 4;30,31,16,15;,
 4;33,34,21,20;,
 4;35,33,20,19;,
 4;36,35,19,24;,
 4;37,36,24,28;,
 4;38,37,28,32;,
 4;39,38,32,29;,
 4;40,39,29,25;,
 4;34,40,25,21;,
 4;41,42,34,33;,
 4;43,41,33,35;,
 4;44,43,35,36;,
 4;45,44,36,37;,
 4;46,45,37,38;,
 4;47,46,38,39;,
 4;48,47,39,40;,
 4;42,48,40,34;,
 4;49,50,42,41;,
 4;51,49,41,43;,
 4;52,51,43,44;,
 4;53,52,44,45;,
 4;54,53,45,46;,
 4;55,54,46,47;,
 4;56,55,47,48;,
 4;50,56,48,42;,
 4;57,58,50,49;,
 4;59,57,49,51;,
 4;60,59,51,52;,
 4;61,60,52,53;,
 4;62,61,53,54;,
 4;63,62,54,55;,
 4;64,63,55,56;,
 4;58,64,56,50;,
 4;65,66,58,57;,
 4;67,65,57,59;,
 4;68,67,59,60;,
 4;69,68,60,61;,
 4;70,69,61,62;,
 4;71,70,62,63;,
 4;72,71,63,64;,
 4;66,72,64,58;,
 4;73,74,75,76;,
 4;77,73,76,78;,
 4;79,77,78,80;,
 4;81,79,80,82;,
 4;83,81,82,84;,
 4;85,83,84,86;,
 4;87,85,86,88;,
 4;74,87,88,75;,
 4;89,90,74,73;,
 4;91,89,73,77;,
 4;92,91,77,79;,
 4;93,92,79,81;,
 4;94,93,81,83;,
 4;95,94,83,85;,
 4;96,95,85,87;,
 4;90,96,87,74;,
 4;97,98,99,100;,
 3;101,98,97;,
 4;102,97,100,103;,
 3;101,97,102;,
 4;104,102,103,105;,
 3;101,102,104;,
 4;106,104,105,107;,
 3;101,104,106;,
 4;108,106,107,109;,
 3;101,106,108;,
 4;110,108,109,111;,
 3;101,108,110;,
 4;112,110,111,113;,
 3;101,110,112;,
 4;98,112,113,99;,
 3;101,112,98;,
 4;114,99,113,115;,
 4;114,115,96,90;,
 4;114,90,89,116;,
 4;114,116,100,99;,
 4;115,113,111,117;,
 4;115,117,95,96;,
 4;116,89,91,118;,
 4;116,118,103,100;,
 4;117,111,109,119;,
 4;117,119,94,95;,
 4;118,91,92,120;,
 4;118,120,105,103;,
 4;119,109,107,121;,
 4;119,121,93,94;,
 4;120,92,93,121;,
 4;120,121,107,105;,
 4;122,75,88,123;,
 4;122,123,72,66;,
 4;122,66,65,124;,
 4;122,124,76,75;,
 4;123,88,86,125;,
 4;123,125,71,72;,
 4;124,65,67,126;,
 4;124,126,78,76;,
 4;125,86,84,127;,
 4;125,127,70,71;,
 4;126,67,68,128;,
 4;126,128,80,78;,
 4;127,84,82,129;,
 4;127,129,69,70;,
 4;128,68,69,129;,
 4;128,129,82,80;;
 
 MeshMaterialList {
  11;
  136;
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
   0.316800;0.160000;0.097600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "��.png";
   }
  }
  Material {
   0.097600;0.097600;0.097600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.920000;0.815120;0.743360;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.552000;0.486400;0.388800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.091200;0.351200;0.179200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.442400;0.373600;0.266400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.759200;0.420000;0.455200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.640000;0.586400;0.307200;1.000000;;
   11.000000;
   0.310000;0.310000;0.310000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;0.460000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  163;
  0.000000;1.000000;0.000000;,
  -0.000001;0.924518;-0.381137;,
  0.290223;0.911504;-0.291431;,
  0.463770;0.885956;-0.000000;,
  0.327934;0.885956;0.327936;,
  -0.000001;0.885954;0.463773;,
  -0.327939;0.885953;0.327939;,
  -0.463776;0.885953;-0.000001;,
  -0.290226;0.911501;-0.291434;,
  -0.000000;-0.029756;0.999557;,
  -0.680162;-0.039685;0.731987;,
  -0.998240;-0.055647;0.020510;,
  -0.707133;-0.034462;-0.706240;,
  -0.000000;-0.009992;-0.999950;,
  0.707133;-0.034462;-0.706241;,
  0.998240;-0.055646;0.020509;,
  0.680162;-0.039684;0.731987;,
  0.542965;0.638684;-0.545226;,
  0.839008;0.544119;-0.000001;,
  -0.000003;0.701721;-0.712452;,
  0.593266;0.544120;0.593270;,
  -0.542971;0.638675;-0.545231;,
  -0.000002;0.544112;0.839013;,
  -0.839016;0.544107;-0.000001;,
  -0.593274;0.544107;0.593274;,
  -0.625592;0.350618;0.696923;,
  -0.868305;0.495490;0.023172;,
  -0.000000;0.249734;0.968315;,
  -0.601447;0.514758;-0.610971;,
  0.625592;0.350621;0.696922;,
  -0.000000;0.512220;-0.858854;,
  0.868304;0.495491;0.023172;,
  0.601446;0.514760;-0.610970;,
  -0.000000;0.088181;0.996104;,
  -0.684914;0.010430;0.728550;,
  -0.994008;-0.106365;0.025182;,
  -0.740114;-0.083080;-0.667330;,
  0.000000;-0.024454;-0.999701;,
  0.740113;-0.083080;-0.667331;,
  0.994008;-0.106364;0.025183;,
  0.684912;0.010431;0.728551;,
  -0.000000;0.069600;0.997575;,
  -0.711699;-0.003305;0.702477;,
  -0.995355;-0.092665;0.026114;,
  -0.787070;-0.066820;-0.613234;,
  -0.000000;-0.024139;-0.999709;,
  0.787069;-0.066819;-0.613235;,
  0.995355;-0.092664;0.026114;,
  0.711697;-0.003305;0.702478;,
  -0.000000;-0.143664;0.989626;,
  -0.724705;-0.121596;0.678246;,
  -0.997311;-0.070042;0.021547;,
  -0.810322;-0.033039;-0.585053;,
  -0.562288;-0.015674;-0.826793;,
  0.810321;-0.033038;-0.585054;,
  0.997311;-0.070041;0.021548;,
  0.724704;-0.121596;0.678246;,
  0.000000;-0.234143;0.972202;,
  -0.715092;-0.176736;0.676319;,
  -0.996754;-0.073142;0.033638;,
  -0.803266;-0.023077;-0.595174;,
  -0.546173;-0.012245;-0.837583;,
  0.803264;-0.023077;-0.595175;,
  0.996754;-0.073142;0.033639;,
  0.715092;-0.176736;0.676319;,
  -0.000001;-0.176595;0.984284;,
  -0.731630;-0.143662;0.666393;,
  -0.992802;-0.101169;0.064105;,
  -0.788953;-0.069592;-0.610500;,
  -0.514252;-0.057801;-0.855689;,
  0.788951;-0.069592;-0.610502;,
  0.992802;-0.101169;0.064105;,
  0.731629;-0.143662;0.666394;,
  -0.524053;0.135669;0.840810;,
  -0.805166;0.060018;0.590004;,
  -0.999802;0.014650;-0.013497;,
  -0.798986;0.166091;-0.577958;,
  -0.000003;0.307349;-0.951597;,
  0.798987;0.166088;-0.577958;,
  0.999802;0.014644;-0.013497;,
  0.805167;0.060014;0.590003;,
  -0.597498;0.050345;0.800289;,
  -0.856093;-0.004131;0.516805;,
  -0.993759;0.106389;-0.033520;,
  -0.718658;0.565152;-0.405134;,
  -0.000002;0.829665;-0.558262;,
  0.718660;0.565150;-0.405133;,
  0.993760;0.106385;-0.033520;,
  0.856094;-0.004134;0.516803;,
  -0.687239;0.076897;0.722350;,
  -0.892651;0.031773;0.449627;,
  -0.996213;0.086912;0.002585;,
  -0.710628;0.644983;-0.281078;,
  -0.000001;0.930112;-0.367277;,
  0.710630;0.644982;-0.281077;,
  0.996213;0.086908;0.002586;,
  0.892652;0.031770;0.449626;,
  -0.622482;-0.049269;0.781082;,
  -0.869425;0.017434;0.493757;,
  -0.991555;0.117543;0.054788;,
  -0.988014;0.152523;-0.023754;,
  -0.000001;0.019190;-0.999816;,
  0.317808;0.018195;-0.947980;,
  0.991555;0.117545;0.054789;,
  0.869425;0.017437;0.493757;,
  -0.582963;-0.098281;0.806533;,
  -0.850352;0.029558;0.525384;,
  -0.984893;0.158732;0.069209;,
  -0.986322;0.163771;-0.018674;,
  0.984892;0.158738;0.069211;,
  0.850351;0.029561;0.525385;,
  0.000000;-0.999728;0.023334;,
  0.685444;0.060537;0.725605;,
  0.894506;0.039019;0.445351;,
  -0.894505;0.039020;0.445352;,
  0.997883;0.056660;0.031938;,
  -0.997883;0.056662;0.031936;,
  0.993826;0.100111;-0.047835;,
  -0.993825;0.100115;-0.047838;,
  -0.000001;0.961811;-0.273713;,
  0.542889;0.036998;0.838989;,
  0.770617;-0.009720;0.637224;,
  -0.770618;-0.009718;0.637223;,
  0.995072;-0.085025;0.051019;,
  -0.995072;-0.085021;0.051020;,
  0.782572;-0.113842;-0.612063;,
  -0.782573;-0.113839;-0.612062;,
  0.501668;-0.106469;-0.858483;,
  -0.460542;0.699787;0.546076;,
  -0.532943;0.845901;0.020557;,
  -0.000000;0.551552;0.834140;,
  -0.356519;0.863590;-0.356521;,
  0.460541;0.699791;0.546073;,
  -0.000000;0.863590;-0.504194;,
  0.532941;0.845903;0.020559;,
  0.356517;0.863592;-0.356518;,
  0.562285;-0.015673;-0.826795;,
  0.546170;-0.012245;-0.837585;,
  0.514248;-0.057801;-0.855692;,
  0.597497;0.050343;0.800289;,
  0.524051;0.135666;0.840813;,
  0.687240;0.076894;0.722349;,
  0.000000;-0.994550;0.104264;,
  0.112970;-0.992279;0.051193;,
  0.000001;-0.999997;-0.002310;,
  -0.000714;-0.999990;-0.004476;,
  -0.317811;0.018195;-0.947980;,
  -0.000000;-0.999991;-0.004347;,
  0.000714;-0.999990;-0.004476;,
  0.986321;0.163776;-0.018674;,
  0.988014;0.152524;-0.023752;,
  -0.000001;-0.999997;-0.002310;,
  -0.112970;-0.992279;0.051193;,
  0.582962;-0.098281;0.806533;,
  0.622483;-0.049266;0.781081;,
  -0.685442;0.060538;0.725606;,
  0.154646;0.950241;-0.270420;,
  0.072881;0.981712;-0.175866;,
  -0.000000;0.984330;-0.176335;,
  -0.154648;0.950241;-0.270420;,
  -0.072882;0.981712;-0.175866;,
  -0.542893;0.036998;0.838986;,
  -0.501672;-0.106468;-0.858481;;
  136;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;17,2,3,18;,
  4;17,19,1,2;,
  4;18,3,4,20;,
  4;19,21,8,1;,
  4;20,4,5,22;,
  4;21,23,7,8;,
  4;22,5,6,24;,
  4;23,24,6,7;,
  4;25,128,129,26;,
  4;25,26,11,10;,
  4;25,10,9,27;,
  4;25,27,130,128;,
  4;26,129,131,28;,
  4;26,28,12,11;,
  4;27,9,16,29;,
  4;27,29,132,130;,
  4;28,131,133,30;,
  4;28,30,13,12;,
  4;29,16,15,31;,
  4;29,31,134,132;,
  4;30,133,135,32;,
  4;30,32,14,13;,
  4;31,15,14,32;,
  4;31,32,135,134;,
  4;34,33,9,10;,
  4;35,34,10,11;,
  4;36,35,11,12;,
  4;37,36,12,13;,
  4;38,37,13,14;,
  4;39,38,14,15;,
  4;40,39,15,16;,
  4;33,40,16,9;,
  4;42,41,33,34;,
  4;43,42,34,35;,
  4;44,43,35,36;,
  4;45,44,36,37;,
  4;46,45,37,38;,
  4;47,46,38,39;,
  4;48,47,39,40;,
  4;41,48,40,33;,
  4;50,49,41,42;,
  4;51,50,42,43;,
  4;52,51,43,44;,
  4;53,52,44,45;,
  4;54,136,45,46;,
  4;55,54,46,47;,
  4;56,55,47,48;,
  4;49,56,48,41;,
  4;58,57,49,50;,
  4;59,58,50,51;,
  4;60,59,51,52;,
  4;61,60,52,53;,
  4;62,137,136,54;,
  4;63,62,54,55;,
  4;64,63,55,56;,
  4;57,64,56,49;,
  4;66,65,57,58;,
  4;67,66,58,59;,
  4;68,67,59,60;,
  4;69,68,60,61;,
  4;70,138,137,62;,
  4;71,70,62,63;,
  4;72,71,63,64;,
  4;65,72,64,57;,
  4;82,81,73,74;,
  4;83,82,74,75;,
  4;84,83,75,76;,
  4;85,84,76,77;,
  4;86,85,77,78;,
  4;87,86,78,79;,
  4;88,87,79,80;,
  4;139,88,80,140;,
  4;90,89,81,82;,
  4;91,90,82,83;,
  4;92,91,83,84;,
  4;93,92,84,85;,
  4;94,93,85,86;,
  4;95,94,86,87;,
  4;96,95,87,88;,
  4;141,96,88,139;,
  4;106,105,97,98;,
  3;111,142,143;,
  4;107,106,98,99;,
  3;111,143,144;,
  4;108,107,99,100;,
  3;111,144,145;,
  4;101,146,146,101;,
  3;111,145,147;,
  4;102,101,101,102;,
  3;111,147,148;,
  4;109,149,150,103;,
  3;111,148,151;,
  4;110,109,103,104;,
  3;111,151,152;,
  4;153,110,104,154;,
  3;111,152,142;,
  4;112,154,104,113;,
  4;112,113,96,141;,
  4;155,89,90,114;,
  4;155,114,98,97;,
  4;113,104,103,115;,
  4;113,115,95,96;,
  4;114,90,91,116;,
  4;114,116,99,98;,
  4;115,103,150,117;,
  4;115,117,94,95;,
  4;116,91,92,118;,
  4;116,118,100,99;,
  4;156,157,158,119;,
  4;156,119,93,94;,
  4;159,92,93,119;,
  4;159,119,158,160;,
  4;120,140,80,121;,
  4;120,121,72,65;,
  4;161,65,66,122;,
  4;161,122,74,73;,
  4;121,80,79,123;,
  4;121,123,71,72;,
  4;122,66,67,124;,
  4;122,124,75,74;,
  4;123,79,78,125;,
  4;123,125,70,71;,
  4;124,67,68,126;,
  4;124,126,76,75;,
  4;125,78,77,127;,
  4;125,127,138,70;,
  4;126,68,69,162;,
  4;126,162,77,76;;
 }
}
