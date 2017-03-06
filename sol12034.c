/*
 * 12034. Races
 * TOPIC: counting strategies, inclusion exclusion, pie, dp, binomial coefficients
 * status: Accepted
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 0x400

long long a[N],n;

int main() {
	int ts,cs = 0;
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	
a[1] = 1, a[2] = 3, a[3] = 13, a[4] = 75, a[5] = 541, a[6] = 4683, a[7] = 7069, a[8] = 2811, a[9] = 7837, a[10] = 8211, a[11] = 6469, a[12] = 867, a[13] = 1909, a[14] = 3963, a[15] = 3061, a[16] = 7683, a[17] = 3253, a[18] = 2643, a[19] = 9805, a[20] = 7467, a[21] = 10021, a[22] = 9699, a[23] = 3157, a[24] = 6915, a[25] = 9133, a[26] = 1827, a[27] = 7093, a[28] = 939, a[29] = 5341, a[30] = 8619, a[31] = 2317, a[32] = 4443, a[33] = 7813, a[34] = 10035, a[35] = 9541, a[36] = 6579, a[37] = 349, a[38] = 7323, a[39] = 6469, a[40] = 7467, a[41] = 5413, a[42] = 9027, a[43] = 3421, a[44] = 8955, a[45] = 8125, a[46] = 4731, a[47] = 877, a[48] = 7875, a[49] = 6493, a[50] = 1875, a[51] = 9205, a[52] = 4971, a[53] = 2413, a[54] = 1563, a[55] = 1597, a[56] = 1179, a[57] = 9853, a[58] = 1539, a[59] = 1381, a[60] = 531, a[61] = 301, a[62] = 1779, a[63] = 5989, a[64] = 7707, a[65] = 1909, a[66] = 8235, a[67] = 541, a[68] = 5379, a[69] = 9421, a[70] = 147, a[71] = 3877, a[72] = 5667, a[73] = 4405, a[74] = 1971, a[75] = 277, a[76] = 1347, a[77] = 9301, a[78] = 4131, a[79] = 7165, a[80] = 7995, a[81] = 8509, a[82] = 2331, a[83] = 4165, a[84] = 6867, a[85] = 6829, a[86] = 3531, a[87] = 3013, a[88] = 8163, a[89] = 3661, a[90] = 5955, a[91] = 4957, a[92] = 2667, a[93] = 2365, a[94] = 9147, a[95] = 8557, a[96] = 1203, a[97] = 6493, a[98] = 9435, a[99] = 8005, a[100] = 10011, a[101] = 1549, a[102] = 3603, a[103] = 2317, a[104] = 1467, a[105] = 9781, a[106] = 915, a[107] = 8053, a[108] = 1539, a[109] = 5941, a[110] = 9555, a[111] = 5749, a[112] = 7131, a[113] = 4117, a[114] = 3435, a[115] = 2845, a[116] = 579, a[117] = 733, a[118] = 7707, a[119] = 4789, a[120] = 195, a[121] = 7525, a[122] = 6555, a[123] = 3565, a[124] = 5811, a[125] = 469, a[126] = 6987, a[127] = 4669, a[128] = 10011, a[129] = 9853, a[130] = 4131, a[131] = 8677, a[132] = 411, a[133] = 5701, a[134] = 6219, a[135] = 7741, a[136] = 6651, a[137] = 7693, a[138] = 123, a[139] = 8557, a[140] = 8211, a[141] = 9685, a[142] = 507, a[143] = 6829, a[144] = 6147, a[145] = 9877, a[146] = 7059, a[147] = 9877, a[148] = 9459, a[149] = 7141, a[150] = 3795, a[151] = 2941, a[152] = 8787, a[153] = 5941, a[154] = 2019, a[155] = 1021, a[156] = 7755, a[157] = 7093, a[158] = 7131, a[159] = 1693, a[160] = 4275, a[161] = 469, a[162] = 387, a[163] = 2773, a[164] = 2019, a[165] = 5221, a[166] = 7155, a[167] = 9781, a[168] = 8187, a[169] = 7813, a[170] = 9963, a[171] = 4645, a[172] = 1587, a[173] = 7405, a[174] = 8667, a[175] = 1405, a[176] = 2715, a[177] = 4573, a[178] = 7971, a[179] = 2869, a[180] = 1635, a[181] = 4981, a[182] = 5067, a[183] = 8173, a[184] = 435, a[185] = 8077, a[186] = 387, a[187] = 7741, a[188] = 7803, a[189] = 8413, a[190] = 1899, a[191] = 805, a[192] = 9963, a[193] = 1189, a[194] = 2115, a[195] = 205, a[196] = 1107, a[197] = 613, a[198] = 6267, a[199] = 7237, a[200] = 1299, a[201] = 4141, a[202] = 7563, a[203] = 853, a[204] = 3915, a[205] = 3301, a[206] = 7179, a[207] = 3349, a[208] = 8427, a[209] = 5701, a[210] = 9483, a[211] = 6685, a[212] = 891, a[213] = 4621, a[214] = 7731, a[215] = 5149, a[216] = 9747, a[217] = 5029, a[218] = 4059, a[219] = 8701, a[220] = 651, a[221] = 7813, a[222] = 5715, a[223] = 5293, a[224] = 2331, a[225] = 2101, a[226] = 5163, a[227] = 5389, a[228] = 7083, a[229] = 7909, a[230] = 4251, a[231] = 13, a[232] = 9147, a[233] = 9469, a[234] = 8499, a[235] = 3157, a[236] = 7419, a[237] = 3901, a[238] = 483, a[239] = 5533, a[240] = 7755, a[241] = 4837, a[242] = 2283, a[243] = 5533, a[244] = 3963, a[245] = 7165, a[246] = 2043, a[247] = 8125, a[248] = 8019, a[249] = 1069, a[250] = 3459, a[251] = 6493, a[252] = 4371, a[253] = 1573, a[254] = 3171, a[255] = 253, a[256] = 243, a[257] = 5533, a[258] = 339, a[259] = 9013, a[260] = 8091, a[261] = 5197, a[262] = 3915, a[263] = 4501, a[264] = 1683, a[265] = 9541, a[266] = 9099, a[267] = 9013, a[268] = 4251, a[269] = 4309, a[270] = 7299, a[271] = 8917, a[272] = 963, a[273] = 9853, a[274] = 6723, a[275] = 4357, a[276] = 2643, a[277] = 4285, a[278] = 3579, a[279] = 8845, a[280] = 8691, a[281] = 6685, a[282] = 3291, a[283] = 8677, a[284] = 9243, a[285] = 3565, a[286] = 8115, a[287] = 5845, a[288] = 2283, a[289] = 3493, a[290] = 9819, a[291] = 8461, a[292] = 6387, a[293] = 7093, a[294] = 4083, a[295] = 2725, a[296] = 627, a[297] = 7645, a[298] = 339, a[299] = 8581, a[300] = 9483, a[301] = 4357, a[302] = 2331, a[303] = 5773, a[304] = 747, a[305] = 9637, a[306] = 9939, a[307] = 2629, a[308] = 1683, a[309] = 3973, a[310] = 7323, a[311] = 5533, a[312] = 1899, a[313] = 4909, a[314] = 9723, a[315] = 7309, a[316] = 4755, a[317] = 6277, a[318] = 1707, a[319] = 6373, a[320] = 1011, a[321] = 2533, a[322] = 4179, a[323] = 9589, a[324] = 7971, a[325] = 5605, a[326] = 7035, a[327] = 8173, a[328] = 3555, a[329] = 4309, a[330] = 7347, a[331] = 4357, a[332] = 1035, a[333] = 9181, a[334] = 7059, a[335] = 7285, a[336] = 99, a[337] = 6109, a[338] = 7683, a[339] = 9325, a[340] = 6435, a[341] = 2581, a[342] = 1203, a[343] = 6253, a[344] = 5115, a[345] = 3037, a[346] = 435, a[347] = 9493, a[348] = 2595, a[349] = 4189, a[350] = 4347, a[351] = 7765, a[352] = 5043, a[353] = 4261, a[354] = 6099, a[355] = 7405, a[356] = 6339, a[357] = 4501, a[358] = 8091, a[359] = 4189, a[360] = 8211, a[361] = 8845, a[362] = 3507, a[363] = 2845, a[364] = 8595, a[365] = 1213, a[366] = 10011, a[367] = 877, a[368] = 9651, a[369] = 1501, a[370] = 3459, a[371] = 3949, a[372] = 3075, a[373] = 6469, a[374] = 8763, a[375] = 4645, a[376] = 8091, a[377] = 133, a[378] = 3291, a[379] = 9469, a[380] = 867, a[381] = 4837, a[382] = 7251, a[383] = 61, a[384] = 5859, a[385] = 3829, a[386] = 9243, a[387] = 781, a[388] = 5667, a[389] = 8269, a[390] = 2451, a[391] = 2101, a[392] = 5163, a[393] = 8029, a[394] = 339, a[395] = 4477, a[396] = 8739, a[397] = 2533, a[398] = 6555, a[399] = 517, a[400] = 339, a[401] = 3949, a[402] = 2595, a[403] = 5581, a[404] = 1131, a[405] = 6109, a[406] = 2955, a[407] = 7213, a[408] = 3267, a[409] = 4573, a[410] = 6219, a[411] = 9349, a[412] = 4659, a[413] = 2077, a[414] = 1419, a[415] = 3493, a[416] = 6003, a[417] = 2413, a[418] = 3771, a[419] = 5029, a[420] = 3, a[421] = 13, a[422] = 75, a[423] = 541, a[424] = 4683, a[425] = 7069, a[426] = 2811, a[427] = 7837, a[428] = 8211, a[429] = 6469, a[430] = 867, a[431] = 1909, a[432] = 3963, a[433] = 3061, a[434] = 7683, a[435] = 3253, a[436] = 2643, a[437] = 9805, a[438] = 7467, a[439] = 10021, a[440] = 9699, a[441] = 3157, a[442] = 6915, a[443] = 9133, a[444] = 1827, a[445] = 7093, a[446] = 939, a[447] = 5341, a[448] = 8619, a[449] = 2317, a[450] = 4443, a[451] = 7813, a[452] = 10035, a[453] = 9541, a[454] = 6579, a[455] = 349, a[456] = 7323, a[457] = 6469, a[458] = 7467, a[459] = 5413, a[460] = 9027, a[461] = 3421, a[462] = 8955, a[463] = 8125, a[464] = 4731, a[465] = 877, a[466] = 7875, a[467] = 6493, a[468] = 1875, a[469] = 9205, a[470] = 4971, a[471] = 2413, a[472] = 1563, a[473] = 1597, a[474] = 1179, a[475] = 9853, a[476] = 1539, a[477] = 1381, a[478] = 531, a[479] = 301, a[480] = 1779, a[481] = 5989, a[482] = 7707, a[483] = 1909, a[484] = 8235, a[485] = 541, a[486] = 5379, a[487] = 9421, a[488] = 147, a[489] = 3877, a[490] = 5667, a[491] = 4405, a[492] = 1971, a[493] = 277, a[494] = 1347, a[495] = 9301, a[496] = 4131, a[497] = 7165, a[498] = 7995, a[499] = 8509, a[500] = 2331, a[501] = 4165, a[502] = 6867, a[503] = 6829, a[504] = 3531, a[505] = 3013, a[506] = 8163, a[507] = 3661, a[508] = 5955, a[509] = 4957, a[510] = 2667, a[511] = 2365, a[512] = 9147, a[513] = 8557, a[514] = 1203, a[515] = 6493, a[516] = 9435, a[517] = 8005, a[518] = 10011, a[519] = 1549, a[520] = 3603, a[521] = 2317, a[522] = 1467, a[523] = 9781, a[524] = 915, a[525] = 8053, a[526] = 1539, a[527] = 5941, a[528] = 9555, a[529] = 5749, a[530] = 7131, a[531] = 4117, a[532] = 3435, a[533] = 2845, a[534] = 579, a[535] = 733, a[536] = 7707, a[537] = 4789, a[538] = 195, a[539] = 7525, a[540] = 6555, a[541] = 3565, a[542] = 5811, a[543] = 469, a[544] = 6987, a[545] = 4669, a[546] = 10011, a[547] = 9853, a[548] = 4131, a[549] = 8677, a[550] = 411, a[551] = 5701, a[552] = 6219, a[553] = 7741, a[554] = 6651, a[555] = 7693, a[556] = 123, a[557] = 8557, a[558] = 8211, a[559] = 9685, a[560] = 507, a[561] = 6829, a[562] = 6147, a[563] = 9877, a[564] = 7059, a[565] = 9877, a[566] = 9459, a[567] = 7141, a[568] = 3795, a[569] = 2941, a[570] = 8787, a[571] = 5941, a[572] = 2019, a[573] = 1021, a[574] = 7755, a[575] = 7093, a[576] = 7131, a[577] = 1693, a[578] = 4275, a[579] = 469, a[580] = 387, a[581] = 2773, a[582] = 2019, a[583] = 5221, a[584] = 7155, a[585] = 9781, a[586] = 8187, a[587] = 7813, a[588] = 9963, a[589] = 4645, a[590] = 1587, a[591] = 7405, a[592] = 8667, a[593] = 1405, a[594] = 2715, a[595] = 4573, a[596] = 7971, a[597] = 2869, a[598] = 1635, a[599] = 4981, a[600] = 5067, a[601] = 8173, a[602] = 435, a[603] = 8077, a[604] = 387, a[605] = 7741, a[606] = 7803, a[607] = 8413, a[608] = 1899, a[609] = 805, a[610] = 9963, a[611] = 1189, a[612] = 2115, a[613] = 205, a[614] = 1107, a[615] = 613, a[616] = 6267, a[617] = 7237, a[618] = 1299, a[619] = 4141, a[620] = 7563, a[621] = 853, a[622] = 3915, a[623] = 3301, a[624] = 7179, a[625] = 3349, a[626] = 8427, a[627] = 5701, a[628] = 9483, a[629] = 6685, a[630] = 891, a[631] = 4621, a[632] = 7731, a[633] = 5149, a[634] = 9747, a[635] = 5029, a[636] = 4059, a[637] = 8701, a[638] = 651, a[639] = 7813, a[640] = 5715, a[641] = 5293, a[642] = 2331, a[643] = 2101, a[644] = 5163, a[645] = 5389, a[646] = 7083, a[647] = 7909, a[648] = 4251, a[649] = 13, a[650] = 9147, a[651] = 9469, a[652] = 8499, a[653] = 3157, a[654] = 7419, a[655] = 3901, a[656] = 483, a[657] = 5533, a[658] = 7755, a[659] = 4837, a[660] = 2283, a[661] = 5533, a[662] = 3963, a[663] = 7165, a[664] = 2043, a[665] = 8125, a[666] = 8019, a[667] = 1069, a[668] = 3459, a[669] = 6493, a[670] = 4371, a[671] = 1573, a[672] = 3171, a[673] = 253, a[674] = 243, a[675] = 5533, a[676] = 339, a[677] = 9013, a[678] = 8091, a[679] = 5197, a[680] = 3915, a[681] = 4501, a[682] = 1683, a[683] = 9541, a[684] = 9099, a[685] = 9013, a[686] = 4251, a[687] = 4309, a[688] = 7299, a[689] = 8917, a[690] = 963, a[691] = 9853, a[692] = 6723, a[693] = 4357, a[694] = 2643, a[695] = 4285, a[696] = 3579, a[697] = 8845, a[698] = 8691, a[699] = 6685, a[700] = 3291, a[701] = 8677, a[702] = 9243, a[703] = 3565, a[704] = 8115, a[705] = 5845, a[706] = 2283, a[707] = 3493, a[708] = 9819, a[709] = 8461, a[710] = 6387, a[711] = 7093, a[712] = 4083, a[713] = 2725, a[714] = 627, a[715] = 7645, a[716] = 339, a[717] = 8581, a[718] = 9483, a[719] = 4357, a[720] = 2331, a[721] = 5773, a[722] = 747, a[723] = 9637, a[724] = 9939, a[725] = 2629, a[726] = 1683, a[727] = 3973, a[728] = 7323, a[729] = 5533, a[730] = 1899, a[731] = 4909, a[732] = 9723, a[733] = 7309, a[734] = 4755, a[735] = 6277, a[736] = 1707, a[737] = 6373, a[738] = 1011, a[739] = 2533, a[740] = 4179, a[741] = 9589, a[742] = 7971, a[743] = 5605, a[744] = 7035, a[745] = 8173, a[746] = 3555, a[747] = 4309, a[748] = 7347, a[749] = 4357, a[750] = 1035, a[751] = 9181, a[752] = 7059, a[753] = 7285, a[754] = 99, a[755] = 6109, a[756] = 7683, a[757] = 9325, a[758] = 6435, a[759] = 2581, a[760] = 1203, a[761] = 6253, a[762] = 5115, a[763] = 3037, a[764] = 435, a[765] = 9493, a[766] = 2595, a[767] = 4189, a[768] = 4347, a[769] = 7765, a[770] = 5043, a[771] = 4261, a[772] = 6099, a[773] = 7405, a[774] = 6339, a[775] = 4501, a[776] = 8091, a[777] = 4189, a[778] = 8211, a[779] = 8845, a[780] = 3507, a[781] = 2845, a[782] = 8595, a[783] = 1213, a[784] = 10011, a[785] = 877, a[786] = 9651, a[787] = 1501, a[788] = 3459, a[789] = 3949, a[790] = 3075, a[791] = 6469, a[792] = 8763, a[793] = 4645, a[794] = 8091, a[795] = 133, a[796] = 3291, a[797] = 9469, a[798] = 867, a[799] = 4837, a[800] = 7251, a[801] = 61, a[802] = 5859, a[803] = 3829, a[804] = 9243, a[805] = 781, a[806] = 5667, a[807] = 8269, a[808] = 2451, a[809] = 2101, a[810] = 5163, a[811] = 8029, a[812] = 339, a[813] = 4477, a[814] = 8739, a[815] = 2533, a[816] = 6555, a[817] = 517, a[818] = 339, a[819] = 3949, a[820] = 2595, a[821] = 5581, a[822] = 1131, a[823] = 6109, a[824] = 2955, a[825] = 7213, a[826] = 3267, a[827] = 4573, a[828] = 6219, a[829] = 9349, a[830] = 4659, a[831] = 2077, a[832] = 1419, a[833] = 3493, a[834] = 6003, a[835] = 2413, a[836] = 3771, a[837] = 5029, a[838] = 3, a[839] = 13, a[840] = 75, a[841] = 541, a[842] = 4683, a[843] = 7069, a[844] = 2811, a[845] = 7837, a[846] = 8211, a[847] = 6469, a[848] = 867, a[849] = 1909, a[850] = 3963, a[851] = 3061, a[852] = 7683, a[853] = 3253, a[854] = 2643, a[855] = 9805, a[856] = 7467, a[857] = 10021, a[858] = 9699, a[859] = 3157, a[860] = 6915, a[861] = 9133, a[862] = 1827, a[863] = 7093, a[864] = 939, a[865] = 5341, a[866] = 8619, a[867] = 2317, a[868] = 4443, a[869] = 7813, a[870] = 10035, a[871] = 9541, a[872] = 6579, a[873] = 349, a[874] = 7323, a[875] = 6469, a[876] = 7467, a[877] = 5413, a[878] = 9027, a[879] = 3421, a[880] = 8955, a[881] = 8125, a[882] = 4731, a[883] = 877, a[884] = 7875, a[885] = 6493, a[886] = 1875, a[887] = 9205, a[888] = 4971, a[889] = 2413, a[890] = 1563, a[891] = 1597, a[892] = 1179, a[893] = 9853, a[894] = 1539, a[895] = 1381, a[896] = 531, a[897] = 301, a[898] = 1779, a[899] = 5989, a[900] = 7707, a[901] = 1909, a[902] = 8235, a[903] = 541, a[904] = 5379, a[905] = 9421, a[906] = 147, a[907] = 3877, a[908] = 5667, a[909] = 4405, a[910] = 1971, a[911] = 277, a[912] = 1347, a[913] = 9301, a[914] = 4131, a[915] = 7165, a[916] = 7995, a[917] = 8509, a[918] = 2331, a[919] = 4165, a[920] = 6867, a[921] = 6829, a[922] = 3531, a[923] = 3013, a[924] = 8163, a[925] = 3661, a[926] = 5955, a[927] = 4957, a[928] = 2667, a[929] = 2365, a[930] = 9147, a[931] = 8557, a[932] = 1203, a[933] = 6493, a[934] = 9435, a[935] = 8005, a[936] = 10011, a[937] = 1549, a[938] = 3603, a[939] = 2317, a[940] = 1467, a[941] = 9781, a[942] = 915, a[943] = 8053, a[944] = 1539, a[945] = 5941, a[946] = 9555, a[947] = 5749, a[948] = 7131, a[949] = 4117, a[950] = 3435, a[951] = 2845, a[952] = 579, a[953] = 733, a[954] = 7707, a[955] = 4789, a[956] = 195, a[957] = 7525, a[958] = 6555, a[959] = 3565, a[960] = 5811, a[961] = 469, a[962] = 6987, a[963] = 4669, a[964] = 10011, a[965] = 9853, a[966] = 4131, a[967] = 8677, a[968] = 411, a[969] = 5701, a[970] = 6219, a[971] = 7741, a[972] = 6651, a[973] = 7693, a[974] = 123, a[975] = 8557, a[976] = 8211, a[977] = 9685, a[978] = 507, a[979] = 6829, a[980] = 6147, a[981] = 9877, a[982] = 7059, a[983] = 9877, a[984] = 9459, a[985] = 7141, a[986] = 3795, a[987] = 2941, a[988] = 8787, a[989] = 5941, a[990] = 2019, a[991] = 1021, a[992] = 7755, a[993] = 7093, a[994] = 7131, a[995] = 1693, a[996] = 4275, a[997] = 469, a[998] = 387, a[999] = 2773, a[1000] = 2019;
for ( scanf("%d",&ts); ts-- && 1 == scanf("%lld",&n); printf("Case %d: %lld\n",++cs,a[n]) );
	return 0;
}
/*
 *
 * 12034. Race
 * TOPIC: combinatorics
 * status: in progress
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long i64;
#define N 0x400
#define MOD 10056LL

i64 n,c[N][N],res,deg[N][N],A;

int main() {
	int i,j,k,ts,cs = 0;
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	for ( i = 0; i < N; c[i++][0] = 1LL );
	for ( i = 1; i < N; ++i )
		for ( j = 1; j <= i ; ++j )
			c[i][j] = c[i-1][j]+c[i-1][j-1], c[i][j] %= MOD;
	//for ( scanf("%d",&ts); ts-- && 1 == scanf("%lld",&n); ) {
		//printf("Case %d: ",++cs), res = 0;
		for ( n = 1; n <= 1000; ++n ) {
		for ( A = 1; A <= n; ++A )
			for ( deg[A][0] = 1LL, k = 1; k <= n; ++k )
				deg[A][k] = deg[A][k-1]*A, deg[A][k] %= MOD;
		for ( A = 1; A <= n; ++A )
			for ( k = 0; k <= A-1; ++k )
				if ( k&1 )
					for ( res -= c[A][k]*deg[A-k][n], res %= MOD; res < 0; res += MOD );
				else 
					for ( res += c[A][k]*deg[A-k][n], res %= MOD; res < 0; res += MOD );
		printf("a[%lld] = %lld, ",n,res);
		}
	//}
	return 0;
}

*/