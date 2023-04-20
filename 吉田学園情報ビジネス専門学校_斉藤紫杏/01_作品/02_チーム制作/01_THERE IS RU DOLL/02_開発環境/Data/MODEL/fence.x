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
 446;
 -32.85934;31.66556;-0.77027;,
 -32.85934;32.48733;-0.77027;,
 33.34477;32.48733;-0.77027;,
 33.34477;31.66556;-0.77027;,
 33.34477;32.48733;0.77027;,
 33.34477;31.66556;0.77027;,
 -32.85934;32.48733;0.77027;,
 -32.85934;31.66556;0.77027;,
 -0.17473;37.31477;-0.74756;,
 0.47267;37.31477;-0.37378;,
 0.47267;6.39212;-0.37378;,
 -0.17473;6.39212;-0.74756;,
 0.47267;37.31477;0.37378;,
 0.47267;6.39212;0.37378;,
 -0.17473;37.31477;0.74756;,
 -0.17473;6.39212;0.74756;,
 -0.82214;37.31477;0.37378;,
 -0.82214;6.39212;0.37378;,
 -0.82214;37.31477;-0.37378;,
 -0.82214;6.39212;-0.37378;,
 -0.17473;37.31477;0.00000;,
 -0.17473;6.39212;0.00000;,
 33.35869;-0.28284;-0.00000;,
 33.35869;-0.28284;-0.74756;,
 34.00610;-0.28284;-0.37378;,
 34.00610;-0.28284;0.37378;,
 33.35869;-0.28284;0.74756;,
 32.71129;-0.28284;0.37378;,
 32.71129;-0.28284;-0.37378;,
 -32.85934;6.62016;-0.77027;,
 33.34477;6.62016;-0.77027;,
 33.34477;5.79839;-0.77027;,
 -32.85934;5.79839;-0.77027;,
 33.34477;6.62016;0.77027;,
 33.34477;5.79839;0.77027;,
 -32.85934;6.62016;0.77027;,
 -32.85934;5.79839;0.77027;,
 -32.85934;37.10745;-0.77027;,
 -32.85934;37.92922;-0.77027;,
 33.34477;37.92922;-0.77027;,
 33.34477;37.10745;-0.77027;,
 33.34477;37.92922;0.77027;,
 33.34477;37.10745;0.77027;,
 -32.85934;37.92922;0.77027;,
 -32.85934;37.10745;0.77027;,
 32.71129;43.23620;0.37378;,
 33.35869;43.23620;0.74756;,
 32.71129;43.23620;-0.37378;,
 34.00610;43.23620;0.37378;,
 33.35869;43.23620;-0.74756;,
 34.00610;43.23620;-0.37378;,
 32.50935;43.32969;0.49037;,
 33.35869;43.32969;0.98074;,
 32.50935;43.32969;-0.49037;,
 34.20804;43.32969;0.49037;,
 33.35869;43.32969;-0.98074;,
 34.20804;43.32969;-0.49037;,
 31.45793;47.31715;1.09740;,
 33.35869;47.31715;2.19481;,
 31.45793;47.31715;-1.09740;,
 35.25946;47.31715;1.09740;,
 33.35869;47.31715;-2.19481;,
 35.25946;47.31715;-1.09740;,
 33.35869;51.56497;0.00000;,
 -33.35869;-0.28284;0.00000;,
 -34.00610;-0.28284;-0.37378;,
 -33.35869;-0.28284;-0.74756;,
 -34.00610;-0.28284;0.37378;,
 -33.35869;-0.28284;0.74756;,
 -32.71129;-0.28284;0.37378;,
 -32.71129;-0.28284;-0.37378;,
 -32.71129;43.23620;0.37378;,
 -33.35869;43.23620;0.74756;,
 -32.71129;43.23620;-0.37378;,
 -34.00610;43.23620;0.37378;,
 -33.35869;43.23620;-0.74756;,
 -34.00610;43.23620;-0.37378;,
 -32.50935;43.32969;0.49037;,
 -33.35869;43.32969;0.98074;,
 -32.50935;43.32969;-0.49037;,
 -34.20804;43.32969;0.49037;,
 -33.35869;43.32969;-0.98074;,
 -34.20804;43.32969;-0.49037;,
 -31.45793;47.31715;1.09740;,
 -33.35869;47.31715;2.19481;,
 -31.45793;47.31715;-1.09740;,
 -35.25946;47.31715;1.09740;,
 -33.35869;47.31715;-2.19481;,
 -35.25946;47.31715;-1.09740;,
 -33.35869;51.56497;0.00000;,
 4.50058;25.39775;0.71118;,
 4.54087;25.39775;-0.51708;,
 4.19230;24.19307;-0.51707;,
 4.15329;24.20774;0.71119;,
 5.09880;25.39775;-0.64563;,
 4.73245;23.98985;-0.64562;,
 5.12319;25.39775;0.56772;,
 4.75608;23.98094;0.56772;,
 2.99455;23.43548;-0.51705;,
 2.99455;23.45622;0.71117;,
 2.99455;23.14809;-0.64562;,
 2.99455;23.13552;0.56771;,
 1.72619;23.90493;-0.51707;,
 1.74541;23.91962;0.71119;,
 1.46017;23.70171;-0.64562;,
 1.44853;23.69283;0.56772;,
 0.73445;25.73394;-0.51708;,
 0.76162;25.73394;0.71117;,
 0.35822;25.73394;-0.64563;,
 0.34177;25.73394;0.56772;,
 16.56269;18.86702;-0.51708;,
 16.56142;19.57235;-0.64563;,
 16.94194;19.60320;0.56772;,
 16.93092;18.84493;0.71119;,
 1.54690;27.46823;-0.64563;,
 1.86292;27.31151;-0.51708;,
 1.53307;27.47509;0.56772;,
 1.88574;27.30019;0.71117;,
 4.05689;28.62665;-0.64563;,
 4.07977;28.35449;-0.51708;,
 4.05588;28.63855;0.56772;,
 4.08144;28.33483;0.71117;,
 6.73729;27.45081;0.56772;,
 6.74109;27.13032;0.71117;,
 6.73744;27.43826;-0.64563;,
 6.74083;27.15104;-0.51708;,
 28.63320;13.01953;-0.64562;,
 28.98049;14.20955;-0.64563;,
 28.94147;14.22422;0.58263;,
 28.59292;13.01953;0.58264;,
 28.40134;14.42744;0.71118;,
 28.03498;13.01953;0.71118;,
 28.37769;14.43635;-0.50216;,
 28.01058;13.01953;-0.50216;,
 30.13922;14.96106;-0.64561;,
 30.13922;14.98181;0.58261;,
 30.13922;15.26919;0.71118;,
 30.13922;15.28177;-0.50215;,
 31.38835;14.49767;-0.64563;,
 31.40759;14.51235;0.58263;,
 31.67360;14.71558;0.71119;,
 31.68525;14.72447;-0.50216;,
 32.37215;12.68337;-0.64561;,
 32.39933;12.68336;0.58264;,
 32.77555;12.68337;0.71119;,
 32.79201;12.68336;-0.50216;,
 31.58686;10.94906;0.71118;,
 31.27085;11.10581;0.58264;,
 31.60071;10.94219;-0.50216;,
 31.24803;11.11711;-0.64561;,
 29.07689;9.79063;0.71118;,
 29.05400;10.06280;0.58264;,
 29.07790;9.77874;-0.50216;,
 29.05234;10.08245;-0.64561;,
 26.39649;10.96648;-0.50216;,
 26.39268;11.28696;-0.64561;,
 26.39633;10.97903;0.71118;,
 26.39295;11.26626;0.58264;,
 29.00270;25.39775;0.71118;,
 29.35000;24.20774;0.71119;,
 29.31098;24.19307;-0.51707;,
 28.96242;25.39775;-0.51708;,
 28.77084;23.98985;-0.64562;,
 28.40449;25.39775;-0.64563;,
 28.74720;23.98094;0.56772;,
 28.38009;25.39775;0.56772;,
 30.50873;23.45622;0.71117;,
 30.50873;23.43548;-0.51705;,
 30.50873;23.14809;-0.64562;,
 30.50873;23.13552;0.56771;,
 31.75787;23.91962;0.71119;,
 31.77709;23.90493;-0.51707;,
 32.04311;23.70171;-0.64562;,
 32.05475;23.69283;0.56772;,
 32.74167;25.73394;0.71117;,
 32.76884;25.73394;-0.51708;,
 33.14507;25.73394;-0.64563;,
 33.16152;25.73394;0.56772;,
 31.95638;27.46823;-0.64563;,
 31.64037;27.31151;-0.51708;,
 31.97021;27.47509;0.56772;,
 31.61754;27.30019;0.71117;,
 29.44640;28.62665;-0.64563;,
 29.42351;28.35449;-0.51708;,
 29.44741;28.63855;0.56772;,
 29.42184;28.33483;0.71117;,
 26.76600;27.45081;0.56772;,
 26.76220;27.13032;0.71117;,
 26.76584;27.43826;-0.64563;,
 26.76246;27.15104;-0.51708;,
 4.87009;13.01953;-0.64562;,
 4.91037;13.01953;0.58264;,
 4.56181;14.22422;0.58263;,
 4.52280;14.20955;-0.64563;,
 5.46831;13.01953;0.71118;,
 5.10195;14.42744;0.71118;,
 5.49271;13.01953;-0.50216;,
 5.12560;14.43635;-0.50216;,
 3.36406;14.98181;0.58261;,
 3.36406;14.96106;-0.64561;,
 3.36406;15.26919;0.71118;,
 3.36406;15.28177;-0.50215;,
 2.09570;14.51235;0.58263;,
 2.11493;14.49767;-0.64563;,
 1.82968;14.71558;0.71119;,
 1.81804;14.72447;-0.50216;,
 1.10396;12.68336;0.58264;,
 1.13114;12.68337;-0.64561;,
 0.72774;12.68337;0.71119;,
 0.71128;12.68336;-0.50216;,
 1.91642;10.94906;0.71118;,
 2.23244;11.10581;0.58264;,
 1.90257;10.94219;-0.50216;,
 2.25526;11.11711;-0.64561;,
 4.42640;9.79063;0.71118;,
 4.44929;10.06280;0.58264;,
 4.42539;9.77874;-0.50216;,
 4.45095;10.08245;-0.64561;,
 7.10680;10.96648;-0.50216;,
 7.11060;11.28696;-0.64561;,
 7.10696;10.97903;0.71118;,
 7.11034;11.26626;0.58264;,
 -4.50058;25.39775;0.71118;,
 -4.15329;24.20774;0.71119;,
 -4.19230;24.19307;-0.51707;,
 -4.54087;25.39775;-0.51708;,
 -4.73245;23.98985;-0.64562;,
 -5.09880;25.39775;-0.64563;,
 -4.75608;23.98094;0.56772;,
 -5.12319;25.39775;0.56772;,
 -2.99455;23.45622;0.71117;,
 -2.99455;23.43548;-0.51705;,
 -2.99455;23.14809;-0.64562;,
 -2.99455;23.13552;0.56771;,
 -1.74541;23.91962;0.71119;,
 -1.72619;23.90493;-0.51707;,
 -1.46017;23.70171;-0.64562;,
 -1.44853;23.69283;0.56772;,
 -0.76162;25.73394;0.71117;,
 -0.73445;25.73394;-0.51708;,
 -0.35822;25.73394;-0.64563;,
 -0.34177;25.73394;0.56772;,
 -16.94060;18.86702;-0.51708;,
 -16.57236;18.84493;0.71119;,
 -16.56135;19.60320;0.56772;,
 -16.94187;19.57235;-0.64563;,
 -1.54690;27.46823;-0.64563;,
 -1.86292;27.31151;-0.51708;,
 -1.53307;27.47509;0.56772;,
 -1.88574;27.30019;0.71117;,
 -4.05689;28.62665;-0.64563;,
 -4.07977;28.35449;-0.51708;,
 -4.05588;28.63855;0.56772;,
 -4.08144;28.33483;0.71117;,
 -6.73729;27.45081;0.56772;,
 -6.74109;27.13032;0.71117;,
 -6.73744;27.43826;-0.64563;,
 -6.74083;27.15104;-0.51708;,
 -28.63320;13.01953;-0.64562;,
 -28.59292;13.01953;0.58264;,
 -28.94147;14.22422;0.58263;,
 -28.98049;14.20955;-0.64563;,
 -28.03498;13.01953;0.71118;,
 -28.40134;14.42744;0.71118;,
 -28.01058;13.01953;-0.50216;,
 -28.37769;14.43635;-0.50216;,
 -30.13922;14.98181;0.58261;,
 -30.13922;14.96106;-0.64561;,
 -30.13922;15.26919;0.71118;,
 -30.13922;15.28177;-0.50215;,
 -31.40759;14.51235;0.58263;,
 -31.38835;14.49767;-0.64563;,
 -31.67360;14.71558;0.71119;,
 -31.68525;14.72447;-0.50216;,
 -32.39933;12.68336;0.58264;,
 -32.37215;12.68337;-0.64561;,
 -32.77555;12.68337;0.71119;,
 -32.79201;12.68336;-0.50216;,
 -31.58686;10.94906;0.71118;,
 -31.27085;11.10581;0.58264;,
 -31.60071;10.94219;-0.50216;,
 -31.24803;11.11711;-0.64561;,
 -29.07689;9.79063;0.71118;,
 -29.05400;10.06280;0.58264;,
 -29.07790;9.77874;-0.50216;,
 -29.05234;10.08245;-0.64561;,
 -26.39649;10.96648;-0.50216;,
 -26.39268;11.28696;-0.64561;,
 -26.39633;10.97903;0.71118;,
 -26.39295;11.26626;0.58264;,
 -29.00270;25.39775;0.71118;,
 -28.96242;25.39775;-0.51708;,
 -29.31098;24.19307;-0.51707;,
 -29.35000;24.20774;0.71119;,
 -28.40449;25.39775;-0.64563;,
 -28.77084;23.98985;-0.64562;,
 -28.38009;25.39775;0.56772;,
 -28.74720;23.98094;0.56772;,
 -30.50873;23.43548;-0.51705;,
 -30.50873;23.45622;0.71117;,
 -30.50873;23.14809;-0.64562;,
 -30.50873;23.13552;0.56771;,
 -31.77709;23.90493;-0.51707;,
 -31.75787;23.91962;0.71119;,
 -32.04311;23.70171;-0.64562;,
 -32.05475;23.69283;0.56772;,
 -32.76884;25.73394;-0.51708;,
 -32.74167;25.73394;0.71117;,
 -33.14507;25.73394;-0.64563;,
 -33.16152;25.73394;0.56772;,
 -31.95638;27.46823;-0.64563;,
 -31.64037;27.31151;-0.51708;,
 -31.97021;27.47509;0.56772;,
 -31.61754;27.30019;0.71117;,
 -29.44640;28.62665;-0.64563;,
 -29.42351;28.35449;-0.51708;,
 -29.44741;28.63855;0.56772;,
 -29.42184;28.33483;0.71117;,
 -26.76600;27.45081;0.56772;,
 -26.76220;27.13032;0.71117;,
 -26.76584;27.43826;-0.64563;,
 -26.76246;27.15104;-0.51708;,
 -4.87009;13.01953;-0.64562;,
 -4.52280;14.20955;-0.64563;,
 -4.56181;14.22422;0.58263;,
 -4.91037;13.01953;0.58264;,
 -5.10195;14.42744;0.71118;,
 -5.46831;13.01953;0.71118;,
 -5.12560;14.43635;-0.50216;,
 -5.49271;13.01953;-0.50216;,
 -3.36406;14.96106;-0.64561;,
 -3.36406;14.98181;0.58261;,
 -3.36406;15.26919;0.71118;,
 -3.36406;15.28177;-0.50215;,
 -2.11493;14.49767;-0.64563;,
 -2.09570;14.51235;0.58263;,
 -1.82968;14.71558;0.71119;,
 -1.81804;14.72447;-0.50216;,
 -1.13114;12.68337;-0.64561;,
 -1.10396;12.68336;0.58264;,
 -0.72774;12.68337;0.71119;,
 -0.71128;12.68336;-0.50216;,
 -1.91642;10.94906;0.71118;,
 -2.23244;11.10581;0.58264;,
 -1.90257;10.94219;-0.50216;,
 -2.25526;11.11711;-0.64561;,
 -4.42640;9.79063;0.71118;,
 -4.44929;10.06280;0.58264;,
 -4.42539;9.77874;-0.50216;,
 -4.45095;10.08245;-0.64561;,
 -7.10680;10.96648;-0.50216;,
 -7.11060;11.28696;-0.64561;,
 -7.10696;10.97903;0.71118;,
 -7.11034;11.26626;0.58264;,
 31.56009;34.81640;0.00000;,
 32.10428;34.81640;-0.24136;,
 27.20669;32.69763;-0.24136;,
 27.20669;32.93304;0.00000;,
 32.64843;34.81640;0.00000;,
 27.20669;32.46220;0.00000;,
 32.10428;34.81640;0.24136;,
 27.20669;32.69763;0.24136;,
 22.30911;34.81641;-0.24136;,
 22.85331;34.81641;0.00000;,
 21.81754;34.81641;0.00000;,
 22.30911;34.81641;0.24136;,
 27.20669;36.93518;-0.24136;,
 27.20669;36.69977;0.00000;,
 27.20669;37.17061;0.00000;,
 27.20669;36.93518;0.24136;,
 20.79278;34.81640;0.00000;,
 21.33697;34.81640;-0.24136;,
 16.43938;32.69763;-0.24136;,
 16.43938;32.93304;0.00000;,
 16.43938;32.46220;0.00000;,
 21.33697;34.81640;0.24136;,
 16.43938;32.69763;0.24136;,
 11.54180;34.81641;-0.24136;,
 12.08600;34.81641;0.00000;,
 11.07896;34.81640;0.00000;,
 11.54180;34.81641;0.24136;,
 16.43938;36.93518;-0.24136;,
 16.43938;36.69977;0.00000;,
 16.43938;37.17061;0.00000;,
 16.43938;36.93518;0.24136;,
 10.05527;34.81640;0.00000;,
 10.59946;34.81640;-0.24136;,
 5.70187;32.69763;-0.24136;,
 5.70187;32.93304;0.00000;,
 5.70187;32.46220;0.00000;,
 10.59946;34.81640;0.24136;,
 5.70187;32.69763;0.24136;,
 0.80428;34.81641;-0.24136;,
 1.34848;34.81641;0.00000;,
 0.26011;34.81641;0.00000;,
 0.80428;34.81641;0.24136;,
 5.70187;36.93518;-0.24136;,
 5.70187;36.69977;0.00000;,
 5.70187;37.17061;0.00000;,
 5.70187;36.93518;0.24136;,
 -31.56009;34.81640;0.00000;,
 -27.20669;32.93304;0.00000;,
 -27.20669;32.69763;-0.24136;,
 -32.10428;34.81640;-0.24136;,
 -27.20669;32.46220;0.00000;,
 -32.64843;34.81640;0.00000;,
 -27.20669;32.69763;0.24136;,
 -32.10428;34.81640;0.24136;,
 -22.85331;34.81641;0.00000;,
 -22.30911;34.81641;-0.24136;,
 -21.81754;34.81641;0.00000;,
 -22.30911;34.81641;0.24136;,
 -27.20669;36.69977;0.00000;,
 -27.20669;36.93518;-0.24136;,
 -27.20669;37.17061;0.00000;,
 -27.20669;36.93518;0.24136;,
 -20.79278;34.81640;0.00000;,
 -16.43938;32.93304;0.00000;,
 -16.43938;32.69763;-0.24136;,
 -21.33697;34.81640;-0.24136;,
 -16.43938;32.46220;0.00000;,
 -16.43938;32.69763;0.24136;,
 -21.33697;34.81640;0.24136;,
 -12.08600;34.81641;0.00000;,
 -11.54180;34.81641;-0.24136;,
 -11.07896;34.81640;0.00000;,
 -11.54180;34.81641;0.24136;,
 -16.43938;36.69977;0.00000;,
 -16.43938;36.93518;-0.24136;,
 -16.43938;37.17061;0.00000;,
 -16.43938;36.93518;0.24136;,
 -10.05527;34.81640;0.00000;,
 -5.70187;32.93304;0.00000;,
 -5.70187;32.69763;-0.24136;,
 -10.59946;34.81640;-0.24136;,
 -5.70187;32.46220;0.00000;,
 -5.70187;32.69763;0.24136;,
 -10.59946;34.81640;0.24136;,
 -1.34848;34.81641;0.00000;,
 -0.80428;34.81641;-0.24136;,
 -0.26011;34.81641;0.00000;,
 -0.80428;34.81641;0.24136;,
 -5.70187;36.69977;0.00000;,
 -5.70187;36.93518;-0.24136;,
 -5.70187;37.17061;0.00000;,
 -5.70187;36.93518;0.24136;;
 
 464;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,1,0;,
 4;7,0,3,5;,
 4;1,6,4,2;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;16,18,19,17;,
 4;18,8,11,19;,
 3;20,9,8;,
 3;20,12,9;,
 3;20,14,12;,
 3;20,16,14;,
 3;20,18,16;,
 3;20,8,18;,
 3;21,11,10;,
 3;21,10,13;,
 3;21,13,15;,
 3;21,15,17;,
 3;21,17,19;,
 3;21,19,11;,
 3;22,23,24;,
 3;22,24,25;,
 3;22,25,26;,
 3;22,26,27;,
 3;22,27,28;,
 3;22,28,23;,
 4;29,30,31,32;,
 4;30,33,34,31;,
 4;33,35,36,34;,
 4;35,29,32,36;,
 4;35,33,30,29;,
 4;32,31,34,36;,
 4;37,38,39,40;,
 4;40,39,41,42;,
 4;42,41,43,44;,
 4;44,43,38,37;,
 4;44,37,40,42;,
 4;38,43,41,39;,
 4;45,27,26,46;,
 4;45,47,28,27;,
 4;46,26,25,48;,
 4;47,49,23,28;,
 4;48,25,24,50;,
 4;49,50,24,23;,
 4;51,45,46,52;,
 4;51,53,47,45;,
 4;52,46,48,54;,
 4;53,55,49,47;,
 4;54,48,50,56;,
 4;55,56,50,49;,
 4;57,51,52,58;,
 4;57,59,53,51;,
 4;58,52,54,60;,
 4;59,61,55,53;,
 4;60,54,56,62;,
 4;61,62,56,55;,
 3;63,62,61;,
 3;63,60,62;,
 3;63,58,60;,
 3;63,57,58;,
 3;63,59,57;,
 3;63,61,59;,
 3;64,65,66;,
 3;64,67,65;,
 3;64,68,67;,
 3;64,69,68;,
 3;64,70,69;,
 3;64,66,70;,
 4;71,72,68,69;,
 4;71,69,70,73;,
 4;72,74,67,68;,
 4;73,70,66,75;,
 4;74,76,65,67;,
 4;75,66,65,76;,
 4;77,78,72,71;,
 4;77,71,73,79;,
 4;78,80,74,72;,
 4;79,73,75,81;,
 4;80,82,76,74;,
 4;81,75,76,82;,
 4;83,84,78,77;,
 4;83,77,79,85;,
 4;84,86,80,78;,
 4;85,79,81,87;,
 4;86,88,82,80;,
 4;87,81,82,88;,
 3;89,87,88;,
 3;89,88,86;,
 3;89,86,84;,
 3;89,84,83;,
 3;89,83,85;,
 3;89,85,87;,
 4;90,91,92,93;,
 4;91,94,95,92;,
 4;94,96,97,95;,
 4;96,90,93,97;,
 4;93,92,98,99;,
 4;92,95,100,98;,
 4;95,97,101,100;,
 4;97,93,99,101;,
 4;99,98,102,103;,
 4;98,100,104,102;,
 4;100,101,105,104;,
 4;101,99,103,105;,
 4;103,102,106,107;,
 4;102,104,108,106;,
 4;104,105,109,108;,
 4;105,103,107,109;,
 4;94,91,90,96;,
 4;110,111,112,113;,
 4;114,115,106,108;,
 4;114,108,109,116;,
 4;115,117,107,106;,
 4;116,109,107,117;,
 4;118,119,115,114;,
 4;118,114,116,120;,
 4;119,121,117,115;,
 4;120,116,117,121;,
 4;122,120,121,123;,
 4;122,123,113,112;,
 4;122,112,111,124;,
 4;122,124,118,120;,
 4;123,121,119,125;,
 4;123,125,110,113;,
 4;124,111,110,125;,
 4;124,125,119,118;,
 4;126,127,128,129;,
 4;129,128,130,131;,
 4;131,130,132,133;,
 4;133,132,127,126;,
 4;127,134,135,128;,
 4;128,135,136,130;,
 4;130,136,137,132;,
 4;132,137,134,127;,
 4;134,138,139,135;,
 4;135,139,140,136;,
 4;136,140,141,137;,
 4;137,141,138,134;,
 4;138,142,143,139;,
 4;139,143,144,140;,
 4;140,144,145,141;,
 4;141,145,142,138;,
 4;131,133,126,129;,
 4;112,111,110,113;,
 4;146,144,143,147;,
 4;146,148,145,144;,
 4;147,143,142,149;,
 4;148,149,142,145;,
 4;150,146,147,151;,
 4;150,152,148,146;,
 4;151,147,149,153;,
 4;152,153,149,148;,
 4;154,155,153,152;,
 4;154,110,111,155;,
 4;154,156,113,110;,
 4;154,152,150,156;,
 4;155,157,151,153;,
 4;155,111,112,157;,
 4;156,157,112,113;,
 4;156,150,151,157;,
 4;158,159,160,161;,
 4;161,160,162,163;,
 4;163,162,164,165;,
 4;165,164,159,158;,
 4;159,166,167,160;,
 4;160,167,168,162;,
 4;162,168,169,164;,
 4;164,169,166,159;,
 4;166,170,171,167;,
 4;167,171,172,168;,
 4;168,172,173,169;,
 4;169,173,170,166;,
 4;170,174,175,171;,
 4;171,175,176,172;,
 4;172,176,177,173;,
 4;173,177,174,170;,
 4;163,165,158,161;,
 4;110,113,112,111;,
 4;178,176,175,179;,
 4;178,180,177,176;,
 4;179,175,174,181;,
 4;180,181,174,177;,
 4;182,178,179,183;,
 4;182,184,180,178;,
 4;183,179,181,185;,
 4;184,185,181,180;,
 4;186,187,185,184;,
 4;186,112,113,187;,
 4;186,188,111,112;,
 4;186,184,182,188;,
 4;187,189,183,185;,
 4;187,113,110,189;,
 4;188,189,110,111;,
 4;188,182,183,189;,
 4;190,191,192,193;,
 4;191,194,195,192;,
 4;194,196,197,195;,
 4;196,190,193,197;,
 4;193,192,198,199;,
 4;192,195,200,198;,
 4;195,197,201,200;,
 4;197,193,199,201;,
 4;199,198,202,203;,
 4;198,200,204,202;,
 4;200,201,205,204;,
 4;201,199,203,205;,
 4;203,202,206,207;,
 4;202,204,208,206;,
 4;204,205,209,208;,
 4;205,203,207,209;,
 4;194,191,190,196;,
 4;112,113,110,111;,
 4;210,211,206,208;,
 4;210,208,209,212;,
 4;211,213,207,206;,
 4;212,209,207,213;,
 4;214,215,211,210;,
 4;214,210,212,216;,
 4;215,217,213,211;,
 4;216,212,213,217;,
 4;218,216,217,219;,
 4;218,219,111,110;,
 4;218,110,113,220;,
 4;218,220,214,216;,
 4;219,217,215,221;,
 4;219,221,112,111;,
 4;220,113,112,221;,
 4;220,221,215,214;,
 4;222,223,224,225;,
 4;225,224,226,227;,
 4;227,226,228,229;,
 4;229,228,223,222;,
 4;223,230,231,224;,
 4;224,231,232,226;,
 4;226,232,233,228;,
 4;228,233,230,223;,
 4;230,234,235,231;,
 4;231,235,236,232;,
 4;232,236,237,233;,
 4;233,237,234,230;,
 4;234,238,239,235;,
 4;235,239,240,236;,
 4;236,240,241,237;,
 4;237,241,238,234;,
 4;227,229,222,225;,
 4;242,243,244,245;,
 4;246,240,239,247;,
 4;246,248,241,240;,
 4;247,239,238,249;,
 4;248,249,238,241;,
 4;250,246,247,251;,
 4;250,252,248,246;,
 4;251,247,249,253;,
 4;252,253,249,248;,
 4;254,255,253,252;,
 4;254,244,243,255;,
 4;254,256,245,244;,
 4;254,252,250,256;,
 4;255,257,251,253;,
 4;255,243,242,257;,
 4;256,257,242,245;,
 4;256,250,251,257;,
 4;258,259,260,261;,
 4;259,262,263,260;,
 4;262,264,265,263;,
 4;264,258,261,265;,
 4;261,260,266,267;,
 4;260,263,268,266;,
 4;263,265,269,268;,
 4;265,261,267,269;,
 4;267,266,270,271;,
 4;266,268,272,270;,
 4;268,269,273,272;,
 4;269,267,271,273;,
 4;271,270,274,275;,
 4;270,272,276,274;,
 4;272,273,277,276;,
 4;273,271,275,277;,
 4;262,259,258,264;,
 4;244,243,242,245;,
 4;278,279,274,276;,
 4;278,276,277,280;,
 4;279,281,275,274;,
 4;280,277,275,281;,
 4;282,283,279,278;,
 4;282,278,280,284;,
 4;283,285,281,279;,
 4;284,280,281,285;,
 4;286,284,285,287;,
 4;286,287,245,242;,
 4;286,242,243,288;,
 4;286,288,282,284;,
 4;287,285,283,289;,
 4;287,289,244,245;,
 4;288,243,244,289;,
 4;288,289,283,282;,
 4;290,291,292,293;,
 4;291,294,295,292;,
 4;294,296,297,295;,
 4;296,290,293,297;,
 4;293,292,298,299;,
 4;292,295,300,298;,
 4;295,297,301,300;,
 4;297,293,299,301;,
 4;299,298,302,303;,
 4;298,300,304,302;,
 4;300,301,305,304;,
 4;301,299,303,305;,
 4;303,302,306,307;,
 4;302,304,308,306;,
 4;304,305,309,308;,
 4;305,303,307,309;,
 4;294,291,290,296;,
 4;242,245,244,243;,
 4;310,311,306,308;,
 4;310,308,309,312;,
 4;311,313,307,306;,
 4;312,309,307,313;,
 4;314,315,311,310;,
 4;314,310,312,316;,
 4;315,317,313,311;,
 4;316,312,313,317;,
 4;318,316,317,319;,
 4;318,319,243,244;,
 4;318,244,245,320;,
 4;318,320,314,316;,
 4;319,317,315,321;,
 4;319,321,242,243;,
 4;320,245,242,321;,
 4;320,321,315,314;,
 4;322,323,324,325;,
 4;325,324,326,327;,
 4;327,326,328,329;,
 4;329,328,323,322;,
 4;323,330,331,324;,
 4;324,331,332,326;,
 4;326,332,333,328;,
 4;328,333,330,323;,
 4;330,334,335,331;,
 4;331,335,336,332;,
 4;332,336,337,333;,
 4;333,337,334,330;,
 4;334,338,339,335;,
 4;335,339,340,336;,
 4;336,340,341,337;,
 4;337,341,338,334;,
 4;327,329,322,325;,
 4;244,245,242,243;,
 4;342,340,339,343;,
 4;342,344,341,340;,
 4;343,339,338,345;,
 4;344,345,338,341;,
 4;346,342,343,347;,
 4;346,348,344,342;,
 4;347,343,345,349;,
 4;348,349,345,344;,
 4;350,351,349,348;,
 4;350,242,245,351;,
 4;350,352,243,242;,
 4;350,348,346,352;,
 4;351,353,347,349;,
 4;351,245,244,353;,
 4;352,353,244,243;,
 4;352,346,347,353;,
 4;354,355,356,357;,
 4;355,358,359,356;,
 4;358,360,361,359;,
 4;360,354,357,361;,
 4;357,356,362,363;,
 4;356,359,364,362;,
 4;359,361,365,364;,
 4;361,357,363,365;,
 4;363,362,366,367;,
 4;362,364,368,366;,
 4;364,365,369,368;,
 4;365,363,367,369;,
 4;367,366,355,354;,
 4;366,368,358,355;,
 4;368,369,360,358;,
 4;369,367,354,360;,
 4;370,371,372,373;,
 4;371,364,374,372;,
 4;364,375,376,374;,
 4;375,370,373,376;,
 4;373,372,377,378;,
 4;372,374,379,377;,
 4;374,376,380,379;,
 4;376,373,378,380;,
 4;378,377,381,382;,
 4;377,379,383,381;,
 4;379,380,384,383;,
 4;380,378,382,384;,
 4;382,381,371,370;,
 4;381,383,364,371;,
 4;383,384,375,364;,
 4;384,382,370,375;,
 4;385,386,387,388;,
 4;386,379,389,387;,
 4;379,390,391,389;,
 4;390,385,388,391;,
 4;388,387,392,393;,
 4;387,389,394,392;,
 4;389,391,395,394;,
 4;391,388,393,395;,
 4;393,392,396,397;,
 4;392,394,398,396;,
 4;394,395,399,398;,
 4;395,393,397,399;,
 4;397,396,386,385;,
 4;396,398,379,386;,
 4;398,399,390,379;,
 4;399,397,385,390;,
 4;400,401,402,403;,
 4;403,402,404,405;,
 4;405,404,406,407;,
 4;407,406,401,400;,
 4;401,408,409,402;,
 4;402,409,410,404;,
 4;404,410,411,406;,
 4;406,411,408,401;,
 4;408,412,413,409;,
 4;409,413,414,410;,
 4;410,414,415,411;,
 4;411,415,412,408;,
 4;412,400,403,413;,
 4;413,403,405,414;,
 4;414,405,407,415;,
 4;415,407,400,412;,
 4;416,417,418,419;,
 4;419,418,420,410;,
 4;410,420,421,422;,
 4;422,421,417,416;,
 4;417,423,424,418;,
 4;418,424,425,420;,
 4;420,425,426,421;,
 4;421,426,423,417;,
 4;423,427,428,424;,
 4;424,428,429,425;,
 4;425,429,430,426;,
 4;426,430,427,423;,
 4;427,416,419,428;,
 4;428,419,410,429;,
 4;429,410,422,430;,
 4;430,422,416,427;,
 4;431,432,433,434;,
 4;434,433,435,425;,
 4;425,435,436,437;,
 4;437,436,432,431;,
 4;432,438,439,433;,
 4;433,439,440,435;,
 4;435,440,441,436;,
 4;436,441,438,432;,
 4;438,442,443,439;,
 4;439,443,444,440;,
 4;440,444,445,441;,
 4;441,445,442,438;,
 4;442,431,434,443;,
 4;443,434,425,444;,
 4;444,425,437,445;,
 4;445,437,431,442;;
 
 MeshMaterialList {
  1;
  464;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
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
   0.006400;0.144000;0.050400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
}
