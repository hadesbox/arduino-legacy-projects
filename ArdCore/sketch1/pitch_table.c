#include "pitch_table.h"

PROGMEM prog_uint32_t pitch_table[2048] = {
	32768, 32812, 32857, 32901, 32946, 32991, 33035, 33080, 33125, 33170, 33215, 33260, 33305, 33350, 33395, 33440, 
	33486, 33531, 33576, 33622, 33667, 33713, 33759, 33804, 33850, 33896, 33942, 33988, 34034, 34080, 34126, 34172, 
	34219, 34265, 34312, 34358, 34405, 34451, 34498, 34545, 34591, 34638, 34685, 34732, 34779, 34826, 34874, 34921, 
	34968, 35015, 35063, 35110, 35158, 35206, 35253, 35301, 35349, 35397, 35445, 35493, 35541, 35589, 35637, 35685, 
	35734, 35782, 35831, 35879, 35928, 35976, 36025, 36074, 36123, 36172, 36221, 36270, 36319, 36368, 36417, 36467, 
	36516, 36566, 36615, 36665, 36715, 36764, 36814, 36864, 36914, 36964, 37014, 37064, 37114, 37165, 37215, 37265, 
	37316, 37366, 37417, 37468, 37518, 37569, 37620, 37671, 37722, 37773, 37824, 37876, 37927, 37978, 38030, 38081, 
	38133, 38185, 38236, 38288, 38340, 38392, 38444, 38496, 38548, 38600, 38653, 38705, 38757, 38810, 38863, 38915, 
	38968, 39021, 39074, 39127, 39180, 39233, 39286, 39339, 39392, 39446, 39499, 39553, 39606, 39660, 39714, 39767, 
	39821, 39875, 39929, 39983, 40037, 40092, 40146, 40200, 40255, 40309, 40364, 40419, 40473, 40528, 40583, 40638, 
	40693, 40748, 40804, 40859, 40914, 40970, 41025, 41081, 41136, 41192, 41248, 41304, 41360, 41416, 41472, 41528, 
	41584, 41641, 41697, 41753, 41810, 41867, 41923, 41980, 42037, 42094, 42151, 42208, 42265, 42323, 42380, 42437, 
	42495, 42552, 42610, 42668, 42726, 42783, 42841, 42899, 42958, 43016, 43074, 43132, 43191, 43249, 43308, 43367, 
	43425, 43484, 43543, 43602, 43661, 43720, 43780, 43839, 43898, 43958, 44017, 44077, 44137, 44196, 44256, 44316, 
	44376, 44436, 44497, 44557, 44617, 44678, 44738, 44799, 44859, 44920, 44981, 45042, 45103, 45164, 45225, 45287, 
	45348, 45409, 45471, 45533, 45594, 45656, 45718, 45780, 45842, 45904, 45966, 46028, 46091, 46153, 46216, 46278, 
	46341, 46404, 46467, 46530, 46593, 46656, 46719, 46782, 46846, 46909, 46973, 47036, 47100, 47164, 47228, 47292, 
	47356, 47420, 47484, 47548, 47613, 47677, 47742, 47807, 47871, 47936, 48001, 48066, 48131, 48196, 48262, 48327, 
	48393, 48458, 48524, 48590, 48655, 48721, 48787, 48853, 48920, 48986, 49052, 49119, 49185, 49252, 49319, 49385, 
	49452, 49519, 49586, 49654, 49721, 49788, 49856, 49923, 49991, 50059, 50126, 50194, 50262, 50330, 50399, 50467, 
	50535, 50604, 50672, 50741, 50810, 50878, 50947, 51016, 51085, 51155, 51224, 51293, 51363, 51432, 51502, 51572, 
	51642, 51712, 51782, 51852, 51922, 51992, 52063, 52133, 52204, 52275, 52346, 52417, 52488, 52559, 52630, 52701, 
	52773, 52844, 52916, 52987, 53059, 53131, 53203, 53275, 53347, 53419, 53492, 53564, 53637, 53710, 53782, 53855, 
	53928, 54001, 54074, 54148, 54221, 54294, 54368, 54442, 54515, 54589, 54663, 54737, 54811, 54886, 54960, 55034, 
	55109, 55184, 55258, 55333, 55408, 55483, 55558, 55634, 55709, 55785, 55860, 55936, 56012, 56087, 56163, 56240, 
	56316, 56392, 56468, 56545, 56622, 56698, 56775, 56852, 56929, 57006, 57083, 57161, 57238, 57316, 57393, 57471, 
	57549, 57627, 57705, 57783, 57861, 57940, 58018, 58097, 58176, 58254, 58333, 58412, 58491, 58571, 58650, 58729, 
	58809, 58889, 58968, 59048, 59128, 59208, 59289, 59369, 59449, 59530, 59611, 59691, 59772, 59853, 59934, 60015, 
	60097, 60178, 60260, 60341, 60423, 60505, 60587, 60669, 60751, 60833, 60916, 60998, 61081, 61164, 61247, 61330, 
	61413, 61496, 61579, 61663, 61746, 61830, 61914, 61997, 62081, 62166, 62250, 62334, 62419, 62503, 62588, 62673, 
	62757, 62843, 62928, 63013, 63098, 63184, 63269, 63355, 63441, 63527, 63613, 63699, 63785, 63872, 63958, 64045, 
	64132, 64219, 64306, 64393, 64480, 64567, 64655, 64742, 64830, 64918, 65006, 65094, 65182, 65270, 65359, 65447, 
	65536, 65625, 65714, 65803, 65892, 65981, 66071, 66160, 66250, 66339, 66429, 66519, 66609, 66700, 66790, 66880, 
	66971, 67062, 67153, 67244, 67335, 67426, 67517, 67609, 67700, 67792, 67884, 67976, 68068, 68160, 68252, 68345, 
	68438, 68530, 68623, 68716, 68809, 68902, 68996, 69089, 69183, 69276, 69370, 69464, 69558, 69653, 69747, 69841, 
	69936, 70031, 70126, 70221, 70316, 70411, 70507, 70602, 70698, 70793, 70889, 70985, 71082, 71178, 71274, 71371, 
	71468, 71564, 71661, 71758, 71856, 71953, 72050, 72148, 72246, 72344, 72442, 72540, 72638, 72736, 72835, 72934, 
	73032, 73131, 73230, 73330, 73429, 73528, 73628, 73728, 73828, 73928, 74028, 74128, 74229, 74329, 74430, 74531, 
	74632, 74733, 74834, 74935, 75037, 75139, 75240, 75342, 75444, 75547, 75649, 75751, 75854, 75957, 76060, 76163, 
	76266, 76369, 76473, 76576, 76680, 76784, 76888, 76992, 77096, 77201, 77305, 77410, 77515, 77620, 77725, 77830, 
	77936, 78041, 78147, 78253, 78359, 78465, 78572, 78678, 78785, 78891, 78998, 79105, 79212, 79320, 79427, 79535, 
	79642, 79750, 79858, 79967, 80075, 80183, 80292, 80401, 80510, 80619, 80728, 80837, 80947, 81057, 81166, 81276, 
	81386, 81497, 81607, 81718, 81828, 81939, 82050, 82161, 82273, 82384, 82496, 82607, 82719, 82831, 82944, 83056, 
	83169, 83281, 83394, 83507, 83620, 83733, 83847, 83960, 84074, 84188, 84302, 84416, 84531, 84645, 84760, 84875, 
	84990, 85105, 85220, 85336, 85451, 85567, 85683, 85799, 85915, 86032, 86148, 86265, 86382, 86499, 86616, 86733, 
	86851, 86968, 87086, 87204, 87322, 87441, 87559, 87678, 87796, 87915, 88034, 88154, 88273, 88393, 88513, 88632, 
	88752, 88873, 88993, 89114, 89234, 89355, 89476, 89598, 89719, 89840, 89962, 90084, 90206, 90328, 90451, 90573, 
	90696, 90819, 90942, 91065, 91188, 91312, 91436, 91559, 91684, 91808, 91932, 92057, 92181, 92306, 92431, 92557, 
	92682, 92807, 92933, 93059, 93185, 93311, 93438, 93564, 93691, 93818, 93945, 94072, 94200, 94327, 94455, 94583, 
	94711, 94840, 94968, 95097, 95226, 95355, 95484, 95613, 95743, 95872, 96002, 96132, 96263, 96393, 96524, 96654, 
	96785, 96916, 97048, 97179, 97311, 97443, 97575, 97707, 97839, 97972, 98104, 98237, 98370, 98504, 98637, 98771, 
	98905, 99039, 99173, 99307, 99442, 99576, 99711, 99846, 99982, 100117, 100253, 100388, 100524, 100661, 100797, 100934, 
	101070, 101207, 101344, 101482, 101619, 101757, 101895, 102033, 102171, 102309, 102448, 102587, 102726, 102865, 103004, 103144, 
	103283, 103423, 103564, 103704, 103844, 103985, 104126, 104267, 104408, 104550, 104691, 104833, 104975, 105117, 105260, 105402, 
	105545, 105688, 105831, 105975, 106118, 106262, 106406, 106550, 106694, 106839, 106984, 107129, 107274, 107419, 107565, 107710, 
	107856, 108002, 108149, 108295, 108442, 108589, 108736, 108883, 109031, 109178, 109326, 109474, 109623, 109771, 109920, 110069, 
	110218, 110367, 110517, 110667, 110816, 110967, 111117, 111267, 111418, 111569, 111720, 111872, 112023, 112175, 112327, 112479, 
	112631, 112784, 112937, 113090, 113243, 113396, 113550, 113704, 113858, 114012, 114167, 114321, 114476, 114631, 114787, 114942, 
	115098, 115254, 115410, 115566, 115723, 115879, 116036, 116194, 116351, 116509, 116667, 116825, 116983, 117141, 117300, 117459, 
	117618, 117777, 117937, 118097, 118257, 118417, 118577, 118738, 118899, 119060, 119221, 119383, 119544, 119706, 119869, 120031, 
	120194, 120356, 120519, 120683, 120846, 121010, 121174, 121338, 121502, 121667, 121832, 121997, 122162, 122328, 122493, 122659, 
	122825, 122992, 123158, 123325, 123492, 123660, 123827, 123995, 124163, 124331, 124500, 124668, 124837, 125006, 125176, 125345, 
	125515, 125685, 125855, 126026, 126197, 126367, 126539, 126710, 126882, 127054, 127226, 127398, 127571, 127744, 127917, 128090, 
	128263, 128437, 128611, 128785, 128960, 129135, 129310, 129485, 129660, 129836, 130012, 130188, 130364, 130541, 130718, 130895, 
	131072, 131250, 131427, 131605, 131784, 131962, 132141, 132320, 132499, 132679, 132859, 133039, 133219, 133399, 133580, 133761, 
	133942, 134124, 134305, 134487, 134669, 134852, 135035, 135217, 135401, 135584, 135768, 135952, 136136, 136320, 136505, 136690, 
	136875, 137060, 137246, 137432, 137618, 137805, 137991, 138178, 138366, 138553, 138741, 138929, 139117, 139305, 139494, 139683, 
	139872, 140062, 140251, 140441, 140632, 140822, 141013, 141204, 141395, 141587, 141779, 141971, 142163, 142356, 142549, 142742, 
	142935, 143129, 143323, 143517, 143711, 143906, 144101, 144296, 144491, 144687, 144883, 145080, 145276, 145473, 145670, 145867, 
	146065, 146263, 146461, 146659, 146858, 147057, 147256, 147456, 147655, 147855, 148056, 148256, 148457, 148658, 148860, 149061, 
	149263, 149466, 149668, 149871, 150074, 150277, 150481, 150685, 150889, 151093, 151298, 151503, 151708, 151914, 152119, 152325, 
	152532, 152738, 152945, 153152, 153360, 153568, 153776, 153984, 154193, 154402, 154611, 154820, 155030, 155240, 155450, 155661, 
	155872, 156083, 156294, 156506, 156718, 156930, 157143, 157356, 157569, 157783, 157996, 158210, 158425, 158639, 158854, 159069, 
	159285, 159501, 159717, 159933, 160150, 160367, 160584, 160802, 161019, 161238, 161456, 161675, 161894, 162113, 162333, 162553, 
	162773, 162993, 163214, 163435, 163657, 163878, 164100, 164323, 164545, 164768, 164991, 165215, 165439, 165663, 165887, 166112, 
	166337, 166562, 166788, 167014, 167240, 167467, 167694, 167921, 168148, 168376, 168604, 168833, 169061, 169290, 169520, 169749, 
	169979, 170210, 170440, 170671, 170902, 171134, 171366, 171598, 171830, 172063, 172296, 172530, 172763, 172997, 173232, 173466, 
	173701, 173937, 174172, 174408, 174645, 174881, 175118, 175355, 175593, 175831, 176069, 176308, 176546, 176786, 177025, 177265, 
	177505, 177745, 177986, 178227, 178469, 178711, 178953, 179195, 179438, 179681, 179924, 180168, 180412, 180657, 180901, 181146, 
	181392, 181638, 181884, 182130, 182377, 182624, 182871, 183119, 183367, 183615, 183864, 184113, 184363, 184612, 184863, 185113, 
	185364, 185615, 185866, 186118, 186370, 186623, 186876, 187129, 187382, 187636, 187890, 188145, 188400, 188655, 188911, 189166, 
	189423, 189679, 189936, 190194, 190451, 190709, 190968, 191226, 191485, 191745, 192005, 192265, 192525, 192786, 193047, 193309, 
	193571, 193833, 194095, 194358, 194622, 194885, 195149, 195414, 195678, 195943, 196209, 196475, 196741, 197007, 197274, 197542, 
	197809, 198077, 198346, 198614, 198883, 199153, 199423, 199693, 199963, 200234, 200505, 200777, 201049, 201321, 201594, 201867, 
	202141, 202415, 202689, 202963, 203238, 203514, 203789, 204065, 204342, 204619, 204896, 205173, 205451, 205730, 206008, 206287, 
	206567, 206847, 207127, 207408, 207689, 207970, 208252, 208534, 208816, 209099, 209382, 209666, 209950, 210235, 210519, 210805, 
	211090, 211376, 211663, 211949, 212236, 212524, 212812, 213100, 213389, 213678, 213967, 214257, 214547, 214838, 215129, 215421, 
	215712, 216005, 216297, 216590, 216884, 217178, 217472, 217766, 218061, 218357, 218653, 218949, 219245, 219542, 219840, 220138, 
	220436, 220735, 221034, 221333, 221633, 221933, 222234, 222535, 222836, 223138, 223441, 223743, 224046, 224350, 224654, 224958, 
	225263, 225568, 225874, 226180, 226486, 226793, 227100, 227408, 227716, 228024, 228333, 228643, 228952, 229262, 229573, 229884, 
	230195, 230507, 230820, 231132, 231445, 231759, 232073, 232387, 232702, 233017, 233333, 233649, 233966, 234283, 234600, 234918, 
	235236, 235555, 235874, 236193, 236513, 236834, 237155, 237476, 237798, 238120, 238442, 238765, 239089, 239413, 239737, 240062, 
	240387, 240713, 241039, 241365, 241692, 242020, 242348, 242676, 243005, 243334, 243664, 243994, 244324, 244655, 244987, 245319, 
	245651, 245984, 246317, 246651, 246985, 247319, 247654, 247990, 248326, 248662, 248999, 249336, 249674, 250012, 250351, 250690, 
	251030, 251370, 251711, 252052, 252393, 252735, 253077, 253420, 253763, 254107, 254452, 254796, 255141, 255487, 255833, 256180, 
	256527, 256874, 257222, 257571, 257920, 258269, 258619, 258969, 259320, 259671, 260023, 260376, 260728, 261081, 261435, 261789, 
	262144, 262499, 262855, 263211, 263567, 263924, 264282, 264640, 264999, 265358, 265717, 266077, 266437, 266798, 267160, 267522, 
	267884, 268247, 268611, 268974, 269339, 269704, 270069, 270435, 270801, 271168, 271535, 271903, 272272, 272641, 273010, 273380, 
	273750, 274121, 274492, 274864, 275237, 275609, 275983, 276357, 276731, 277106, 277481, 277857, 278234, 278611, 278988, 279366, 
	279744, 280123, 280503, 280883, 281263, 281644, 282026, 282408, 282791, 283174, 283557, 283942, 284326, 284711, 285097, 285483, 
	285870, 286257, 286645, 287033, 287422, 287812, 288202, 288592, 288983, 289374, 289766, 290159, 290552, 290946, 291340, 291735, 
	292130, 292526, 292922, 293319, 293716, 294114, 294512, 294911, 295311, 295711, 296112, 296513, 296914, 297317, 297719, 298123, 
	298527, 298931, 299336, 299742, 300148, 300554, 300961, 301369, 301777, 302186, 302596, 303005, 303416, 303827, 304239, 304651, 
	305063, 305477, 305891, 306305, 306720, 307135, 307552, 307968, 308385, 308803, 309222, 309640, 310060, 310480, 310901, 311322, 
	311744, 312166, 312589, 313012, 313436, 313861, 314286, 314712, 315138, 315565, 315993, 316421, 316849, 317279, 317708, 318139, 
	318570, 319001, 319434, 319866, 320300, 320734, 321168, 321603, 322039, 322475, 322912, 323349, 323787, 324226, 324665, 325105, 
	325546, 325987, 326428, 326870, 327313, 327757, 328201, 328645, 329091, 329536, 329983, 330430, 330877, 331326, 331775, 332224, 
	332674, 333125, 333576, 334028, 334480, 334934, 335387, 335842, 336297, 336752, 337208, 337665, 338123, 338581, 339039, 339499, 
	339959, 340419, 340880, 341342, 341805, 342268, 342731, 343196, 343661, 344126, 344592, 345059, 345527, 345995, 346463, 346933, 
	347403, 347873, 348345, 348817, 349289, 349762, 350236, 350711, 351186, 351662, 352138, 352615, 353093, 353571, 354050, 354530, 
	355010, 355491, 355972, 356455, 356938, 357421, 357905, 358390, 358876, 359362, 359849, 360336, 360824, 361313, 361803, 362293, 
	362784, 363275, 363767, 364260, 364754, 365248, 365742, 366238, 366734, 367231, 367728, 368227, 368725, 369225, 369725, 370226, 
	370728, 371230, 371733, 372236, 372741, 373246, 373751, 374258, 374765, 375272, 375781, 376290, 376799, 377310, 377821, 378333, 
	378845, 379359, 379873, 380387, 380903, 381419, 381935, 382453, 382971, 383490, 384009, 384529, 385050, 385572, 386094, 386617, 
	387141, 387666, 388191, 388717, 389243, 389771, 390299, 390827, 391357, 391887, 392418, 392949, 393482, 394015, 394549, 395083, 
	395618, 396154, 396691, 397228, 397767, 398305, 398845, 399385, 399926, 400468, 401011, 401554, 402098, 402643, 403188, 403734, 
	404281, 404829, 405377, 405927, 406477, 407027, 407579, 408131, 408684, 409237, 409792, 410347, 410903, 411459, 412017, 412575, 
	413134, 413694, 414254, 414815, 415377, 415940, 416503, 417068, 417633, 418198, 418765, 419332, 419900, 420469, 421039, 421609, 
	422180, 422752, 423325, 423899, 424473, 425048, 425624, 426200, 426778, 427356, 427935, 428514, 429095, 429676, 430258, 430841, 
	431425, 432009, 432595, 433181, 433768, 434355, 434944, 435533, 436123, 436714, 437305, 437898, 438491, 439085, 439680, 440275, 
	440872, 441469, 442067, 442666, 443266, 443866, 444468, 445070, 445673, 446276, 446881, 447486, 448093, 448700, 449308, 449916, 
	450526, 451136, 451747, 452359, 452972, 453586, 454200, 454815, 455432, 456049, 456666, 457285, 457905, 458525, 459146, 459768, 
	460391, 461015, 461639, 462265, 462891, 463518, 464146, 464775, 465404, 466035, 466666, 467298, 467931, 468565, 469200, 469836, 
	470472, 471110, 471748, 472387, 473027, 473668, 474309, 474952, 475595, 476240, 476885, 477531, 478178, 478826, 479474, 480124, 
	480774, 481426, 482078, 482731, 483385, 484040, 484695, 485352, 486010, 486668, 487327, 487987, 488648, 489310, 489973, 490637, 
	491302, 491967, 492634, 493301, 493970, 494639, 495309, 495980, 496652, 497325, 497998, 498673, 499348, 500025, 500702, 501381, 
	502060, 502740, 503421, 504103, 504786, 505470, 506155, 506840, 507527, 508215, 508903, 509592, 510283, 510974, 511666, 512359, 
	513054, 513749, 514445, 515142, 515839, 516538, 517238, 517939, 518640, 519343, 520047, 520751, 521457, 522163, 522870, 523579
};
