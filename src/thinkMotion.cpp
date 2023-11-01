#include "thinkMotion.h"

void thinking(const std::vector<std::string>& names, const AL::ALValue& times, const AL::ALValue& keys, AL::ALMotionProxy * motion, AL::ALLedsProxy * leds)
{
  float duration = 3.0f;
  leds->post.rasta(duration);
  motion->post.angleInterpolationBezier(names, times, keys);
}

void addParams(std::vector<std::string>& names, AL::ALValue& times, AL::ALValue& keys)
{
  names.reserve(26);
  times.arraySetSize(26);
  keys.arraySetSize(26);

  names.push_back("HeadPitch");
  times[0].arraySetSize(6);
  keys[0].arraySetSize(6);

  times[0][0] = 0.24;
  keys[0][0] = AL::ALValue::array(-0.147306, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[0][1] = 1.48;
  keys[0][1] = AL::ALValue::array(-0.00464392, AL::ALValue::array(3, -0.413333, -0.101578), AL::ALValue::array(3, 0.24, 0.0589808));
  times[0][2] = 2.2;
  keys[0][2] = AL::ALValue::array(0.33437, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[0][3] = 2.84;
  keys[0][3] = AL::ALValue::array(-0.00464392, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[0][4] = 3.52;
  keys[0][4] = AL::ALValue::array(0.33437, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[0][5] = 4.96;
  keys[0][5] = AL::ALValue::array(-0.159578, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("HeadYaw");
  times[1].arraySetSize(6);
  keys[1].arraySetSize(6);

  times[1][0] = 0.24;
  keys[1][0] = AL::ALValue::array(0.033706, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[1][1] = 1.48;
  keys[1][1] = AL::ALValue::array(0.309826, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[1][2] = 2.2;
  keys[1][2] = AL::ALValue::array(0.309826, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[1][3] = 2.84;
  keys[1][3] = AL::ALValue::array(0.309826, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[1][4] = 3.52;
  keys[1][4] = AL::ALValue::array(0.309826, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[1][5] = 4.96;
  keys[1][5] = AL::ALValue::array(0.0137641, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LAnklePitch");
  times[2].arraySetSize(6);
  keys[2].arraySetSize(6);

  times[2][0] = 0.24;
  keys[2][0] = AL::ALValue::array(0.0904641, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[2][1] = 1.48;
  keys[2][1] = AL::ALValue::array(-0.00157595, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.28, 0));
  times[2][2] = 2.32;
  keys[2][2] = AL::ALValue::array(0.032172, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[2][3] = 3;
  keys[2][3] = AL::ALValue::array(0.00149202, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[2][4] = 3.68;
  keys[2][4] = AL::ALValue::array(0.0352399, AL::ALValue::array(3, -0.226667, -0.0113537), AL::ALValue::array(3, 0.426667, 0.0213717));
  times[2][5] = 4.96;
  keys[2][5] = AL::ALValue::array(0.0996681, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LAnkleRoll");
  times[3].arraySetSize(6);
  keys[3].arraySetSize(6);

  times[3][0] = 0.24;
  keys[3][0] = AL::ALValue::array(-0.11194, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[3][1] = 1.48;
  keys[3][1] = AL::ALValue::array(-0.113474, AL::ALValue::array(3, -0.413333, 0.00153396), AL::ALValue::array(3, 0.28, -0.00103914));
  times[3][2] = 2.32;
  keys[3][2] = AL::ALValue::array(-0.199378, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[3][3] = 3;
  keys[3][3] = AL::ALValue::array(-0.107338, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[3][4] = 3.68;
  keys[3][4] = AL::ALValue::array(-0.208583, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[3][5] = 4.96;
  keys[3][5] = AL::ALValue::array(-0.113474, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LElbowRoll");
  times[4].arraySetSize(6);
  keys[4].arraySetSize(6);

  times[4][0] = 0.24;
  keys[4][0] = AL::ALValue::array(-0.434081, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[4][1] = 1.48;
  keys[4][1] = AL::ALValue::array(-1.50021, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[4][2] = 2.2;
  keys[4][2] = AL::ALValue::array(-1.48947, AL::ALValue::array(3, -0.24, -0.00378995), AL::ALValue::array(3, 0.213333, 0.00336885));
  times[4][3] = 2.84;
  keys[4][3] = AL::ALValue::array(-1.47873, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[4][4] = 3.52;
  keys[4][4] = AL::ALValue::array(-1.47873, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[4][5] = 4.96;
  keys[4][5] = AL::ALValue::array(-0.418739, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LElbowYaw");
  times[5].arraySetSize(6);
  keys[5].arraySetSize(6);

  times[5][0] = 0.24;
  keys[5][0] = AL::ALValue::array(-1.16895, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[5][1] = 1.48;
  keys[5][1] = AL::ALValue::array(-0.992539, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[5][2] = 2.2;
  keys[5][2] = AL::ALValue::array(-0.992539, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[5][3] = 2.84;
  keys[5][3] = AL::ALValue::array(-1.00328, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[5][4] = 3.52;
  keys[5][4] = AL::ALValue::array(-1.00328, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[5][5] = 4.96;
  keys[5][5] = AL::ALValue::array(-1.18122, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LHand");
  times[6].arraySetSize(6);
  keys[6].arraySetSize(6);

  times[6][0] = 0.24;
  keys[6][0] = AL::ALValue::array(0.2864, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[6][1] = 1.48;
  keys[6][1] = AL::ALValue::array(0.274, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[6][2] = 2.2;
  keys[6][2] = AL::ALValue::array(0.274, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[6][3] = 2.84;
  keys[6][3] = AL::ALValue::array(0.274, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[6][4] = 3.52;
  keys[6][4] = AL::ALValue::array(0.274, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[6][5] = 4.96;
  keys[6][5] = AL::ALValue::array(0.2972, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LHipPitch");
  times[7].arraySetSize(6);
  keys[7].arraySetSize(6);

  times[7][0] = 0.24;
  keys[7][0] = AL::ALValue::array(0.144238, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[7][1] = 1.48;
  keys[7][1] = AL::ALValue::array(0.18719, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.28, 0));
  times[7][2] = 2.32;
  keys[7][2] = AL::ALValue::array(0.131966, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[7][3] = 3;
  keys[7][3] = AL::ALValue::array(0.191792, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[7][4] = 3.68;
  keys[7][4] = AL::ALValue::array(0.139636, AL::ALValue::array(3, -0.226667, 0.00488971), AL::ALValue::array(3, 0.426667, -0.00920417));
  times[7][5] = 4.96;
  keys[7][5] = AL::ALValue::array(0.130432, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LHipRoll");
  times[8].arraySetSize(6);
  keys[8].arraySetSize(6);

  times[8][0] = 0.24;
  keys[8][0] = AL::ALValue::array(0.10282, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[8][1] = 1.48;
  keys[8][1] = AL::ALValue::array(0.15651, AL::ALValue::array(3, -0.413333, -0.036885), AL::ALValue::array(3, 0.28, 0.0249866));
  times[8][2] = 2.32;
  keys[8][2] = AL::ALValue::array(0.288435, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[8][3] = 3;
  keys[8][3] = AL::ALValue::array(0.151908, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[8][4] = 3.68;
  keys[8][4] = AL::ALValue::array(0.283832, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[8][5] = 4.96;
  keys[8][5] = AL::ALValue::array(0.107422, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LHipYawPitch");
  times[9].arraySetSize(6);
  keys[9].arraySetSize(6);

  times[9][0] = 0.24;
  keys[9][0] = AL::ALValue::array(-0.176367, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[9][1] = 1.48;
  keys[9][1] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.28, 0));
  times[9][2] = 2.32;
  keys[9][2] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[9][3] = 3;
  keys[9][3] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[9][4] = 3.68;
  keys[9][4] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[9][5] = 4.96;
  keys[9][5] = AL::ALValue::array(-0.170232, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LKneePitch");
  times[10].arraySetSize(6);
  keys[10].arraySetSize(6);

  times[10][0] = 0.24;
  keys[10][0] = AL::ALValue::array(-0.0782759, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[10][1] = 1.48;
  keys[10][1] = AL::ALValue::array(0.130348, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.28, 0));
  times[10][2] = 2.32;
  keys[10][2] = AL::ALValue::array(0.11961, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[10][3] = 3;
  keys[10][3] = AL::ALValue::array(0.139552, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[10][4] = 3.68;
  keys[10][4] = AL::ALValue::array(0.128814, AL::ALValue::array(3, -0.226667, 0.0107381), AL::ALValue::array(3, 0.426667, -0.020213));
  times[10][5] = 4.96;
  keys[10][5] = AL::ALValue::array(-0.0844118, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LShoulderPitch");
  times[11].arraySetSize(6);
  keys[11].arraySetSize(6);

  times[11][0] = 0.24;
  keys[11][0] = AL::ALValue::array(1.49868, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[11][1] = 1.48;
  keys[11][1] = AL::ALValue::array(2.07392, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[11][2] = 2.2;
  keys[11][2] = AL::ALValue::array(2.07392, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[11][3] = 2.84;
  keys[11][3] = AL::ALValue::array(2.07392, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[11][4] = 3.52;
  keys[11][4] = AL::ALValue::array(2.07392, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[11][5] = 4.96;
  keys[11][5] = AL::ALValue::array(1.48487, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LShoulderRoll");
  times[12].arraySetSize(6);
  keys[12].arraySetSize(6);

  times[12][0] = 0.24;
  keys[12][0] = AL::ALValue::array(0.240796, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[12][1] = 1.48;
  keys[12][1] = AL::ALValue::array(0.676453, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[12][2] = 2.2;
  keys[12][2] = AL::ALValue::array(0.676453, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[12][3] = 2.84;
  keys[12][3] = AL::ALValue::array(0.676453, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[12][4] = 3.52;
  keys[12][4] = AL::ALValue::array(0.676453, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[12][5] = 4.96;
  keys[12][5] = AL::ALValue::array(0.216252, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("LWristYaw");
  times[13].arraySetSize(6);
  keys[13].arraySetSize(6);

  times[13][0] = 0.24;
  keys[13][0] = AL::ALValue::array(0.0398422, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[13][1] = 1.48;
  keys[13][1] = AL::ALValue::array(-0.667332, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[13][2] = 2.2;
  keys[13][2] = AL::ALValue::array(-0.667332, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[13][3] = 2.84;
  keys[13][3] = AL::ALValue::array(-0.667332, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[13][4] = 3.52;
  keys[13][4] = AL::ALValue::array(-0.667332, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[13][5] = 4.96;
  keys[13][5] = AL::ALValue::array(0.0689882, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RAnklePitch");
  times[14].arraySetSize(6);
  keys[14].arraySetSize(6);

  times[14][0] = 0.24;
  keys[14][0] = AL::ALValue::array(0.10282, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[14][1] = 1.48;
  keys[14][1] = AL::ALValue::array(0.036858, AL::ALValue::array(3, -0.413333, 0.01829), AL::ALValue::array(3, 0.28, -0.01239));
  times[14][2] = 2.32;
  keys[14][2] = AL::ALValue::array(0.0107799, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[14][3] = 3;
  keys[14][3] = AL::ALValue::array(0.036858, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[14][4] = 3.68;
  keys[14][4] = AL::ALValue::array(0.0261199, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[14][5] = 4.96;
  keys[14][5] = AL::ALValue::array(0.101286, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RAnkleRoll");
  times[15].arraySetSize(6);
  keys[15].arraySetSize(6);

  times[15][0] = 0.24;
  keys[15][0] = AL::ALValue::array(0.11816, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[15][1] = 1.48;
  keys[15][1] = AL::ALValue::array(0.0153821, AL::ALValue::array(3, -0.413333, 0.0405429), AL::ALValue::array(3, 0.28, -0.0274645));
  times[15][2] = 2.32;
  keys[15][2] = AL::ALValue::array(-0.0858622, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[15][3] = 3;
  keys[15][3] = AL::ALValue::array(0.0276539, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[15][4] = 3.68;
  keys[15][4] = AL::ALValue::array(-0.0873961, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[15][5] = 4.96;
  keys[15][5] = AL::ALValue::array(0.124296, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RElbowRoll");
  times[16].arraySetSize(6);
  keys[16].arraySetSize(6);

  times[16][0] = 0.24;
  keys[16][0] = AL::ALValue::array(0.42496, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[16][1] = 1.48;
  keys[16][1] = AL::ALValue::array(1.45121, AL::ALValue::array(3, -0.413333, -0.163797), AL::ALValue::array(3, 0.24, 0.0951081));
  times[16][2] = 2.2;
  keys[16][2] = AL::ALValue::array(1.54631, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[16][3] = 2.84;
  keys[16][3] = AL::ALValue::array(1.44507, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[16][4] = 3.52;
  keys[16][4] = AL::ALValue::array(1.53097, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[16][5] = 4.96;
  keys[16][5] = AL::ALValue::array(0.40962, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RElbowYaw");
  times[17].arraySetSize(6);
  keys[17].arraySetSize(6);

  times[17][0] = 0.24;
  keys[17][0] = AL::ALValue::array(1.15966, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[17][1] = 1.48;
  keys[17][1] = AL::ALValue::array(0.883542, AL::ALValue::array(3, -0.413333, 0.0698752), AL::ALValue::array(3, 0.24, -0.0405727));
  times[17][2] = 2.2;
  keys[17][2] = AL::ALValue::array(0.828318, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[17][3] = 2.84;
  keys[17][3] = AL::ALValue::array(0.858999, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[17][4] = 3.52;
  keys[17][4] = AL::ALValue::array(0.825251, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[17][5] = 4.96;
  keys[17][5] = AL::ALValue::array(1.18267, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RHand");
  times[18].arraySetSize(6);
  keys[18].arraySetSize(6);

  times[18][0] = 0.24;
  keys[18][0] = AL::ALValue::array(0.3256, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[18][1] = 1.48;
  keys[18][1] = AL::ALValue::array(0.7428, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[18][2] = 2.2;
  keys[18][2] = AL::ALValue::array(0.28, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[18][3] = 2.84;
  keys[18][3] = AL::ALValue::array(0.738, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[18][4] = 3.52;
  keys[18][4] = AL::ALValue::array(0.2872, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[18][5] = 4.96;
  keys[18][5] = AL::ALValue::array(0.3104, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RHipPitch");
  times[19].arraySetSize(6);
  keys[19].arraySetSize(6);

  times[19][0] = 0.24;
  keys[19][0] = AL::ALValue::array(0.13495, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[19][1] = 1.48;
  keys[19][1] = AL::ALValue::array(0.260738, AL::ALValue::array(3, -0.413333, -0.0158503), AL::ALValue::array(3, 0.28, 0.0107373));
  times[19][2] = 2.32;
  keys[19][2] = AL::ALValue::array(0.271475, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[19][3] = 3;
  keys[19][3] = AL::ALValue::array(0.271475, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[19][4] = 3.68;
  keys[19][4] = AL::ALValue::array(0.271475, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[19][5] = 4.96;
  keys[19][5] = AL::ALValue::array(0.131882, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RHipRoll");
  times[20].arraySetSize(6);
  keys[20].arraySetSize(6);

  times[20][0] = 0.24;
  keys[20][0] = AL::ALValue::array(-0.116542, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[20][1] = 1.48;
  keys[20][1] = AL::ALValue::array(-0.0413762, AL::ALValue::array(3, -0.413333, -0.0478588), AL::ALValue::array(3, 0.28, 0.0324205));
  times[20][2] = 2.32;
  keys[20][2] = AL::ALValue::array(0.124296, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[20][3] = 3;
  keys[20][3] = AL::ALValue::array(-0.0459781, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[20][4] = 3.68;
  keys[20][4] = AL::ALValue::array(0.131966, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[20][5] = 4.96;
  keys[20][5] = AL::ALValue::array(-0.122678, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RHipYawPitch");
  times[21].arraySetSize(6);
  keys[21].arraySetSize(6);

  times[21][0] = 0.24;
  keys[21][0] = AL::ALValue::array(-0.176367, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[21][1] = 1.48;
  keys[21][1] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.28, 0));
  times[21][2] = 2.32;
  keys[21][2] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[21][3] = 3;
  keys[21][3] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[21][4] = 3.68;
  keys[21][4] = AL::ALValue::array(-0.37272, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[21][5] = 4.96;
  keys[21][5] = AL::ALValue::array(-0.170232, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RKneePitch");
  times[22].arraySetSize(6);
  keys[22].arraySetSize(6);

  times[22][0] = 0.24;
  keys[22][0] = AL::ALValue::array(-0.0904641, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[22][1] = 1.48;
  keys[22][1] = AL::ALValue::array(0.0138481, AL::ALValue::array(3, -0.413333, -0.0067934), AL::ALValue::array(3, 0.28, 0.00460198));
  times[22][2] = 2.32;
  keys[22][2] = AL::ALValue::array(0.01845, AL::ALValue::array(3, -0.28, 0), AL::ALValue::array(3, 0.226667, 0));
  times[22][3] = 3;
  keys[22][3] = AL::ALValue::array(0.01845, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.226667, 0));
  times[22][4] = 3.68;
  keys[22][4] = AL::ALValue::array(0.021518, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.426667, 0));
  times[22][5] = 4.96;
  keys[22][5] = AL::ALValue::array(-0.0966001, AL::ALValue::array(3, -0.426667, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RShoulderPitch");
  times[23].arraySetSize(6);
  keys[23].arraySetSize(6);

  times[23][0] = 0.24;
  keys[23][0] = AL::ALValue::array(1.39598, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[23][1] = 1.48;
  keys[23][1] = AL::ALValue::array(-0.418739, AL::ALValue::array(3, -0.413333, 0), AL::ALValue::array(3, 0.24, 0));
  times[23][2] = 2.2;
  keys[23][2] = AL::ALValue::array(-0.185572, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[23][3] = 2.84;
  keys[23][3] = AL::ALValue::array(-0.329768, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[23][4] = 3.52;
  keys[23][4] = AL::ALValue::array(-0.161028, AL::ALValue::array(3, -0.226667, -0.16874), AL::ALValue::array(3, 0.48, 0.357331));
  times[23][5] = 4.96;
  keys[23][5] = AL::ALValue::array(1.42973, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RShoulderRoll");
  times[24].arraySetSize(6);
  keys[24].arraySetSize(6);

  times[24][0] = 0.24;
  keys[24][0] = AL::ALValue::array(-0.199461, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[24][1] = 1.48;
  keys[24][1] = AL::ALValue::array(-0.254685, AL::ALValue::array(3, -0.413333, 0.0281443), AL::ALValue::array(3, 0.24, -0.0163418));
  times[24][2] = 2.2;
  keys[24][2] = AL::ALValue::array(-0.33292, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[24][3] = 2.84;
  keys[24][3] = AL::ALValue::array(-0.265424, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[24][4] = 3.52;
  keys[24][4] = AL::ALValue::array(-0.331386, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[24][5] = 4.96;
  keys[24][5] = AL::ALValue::array(-0.197927, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));

  names.push_back("RWristYaw");
  times[25].arraySetSize(6);
  keys[25].arraySetSize(6);

  times[25][0] = 0.24;
  keys[25][0] = AL::ALValue::array(0.194775, AL::ALValue::array(3, -0.0933333, 0), AL::ALValue::array(3, 0.413333, 0));
  times[25][1] = 1.48;
  keys[25][1] = AL::ALValue::array(1.38056, AL::ALValue::array(3, -0.413333, -0.0184921), AL::ALValue::array(3, 0.24, 0.0107373));
  times[25][2] = 2.2;
  keys[25][2] = AL::ALValue::array(1.3913, AL::ALValue::array(3, -0.24, 0), AL::ALValue::array(3, 0.213333, 0));
  times[25][3] = 2.84;
  keys[25][3] = AL::ALValue::array(1.3913, AL::ALValue::array(3, -0.213333, 0), AL::ALValue::array(3, 0.226667, 0));
  times[25][4] = 3.52;
  keys[25][4] = AL::ALValue::array(1.3913, AL::ALValue::array(3, -0.226667, 0), AL::ALValue::array(3, 0.48, 0));
  times[25][5] = 4.96;
  keys[25][5] = AL::ALValue::array(0.147222, AL::ALValue::array(3, -0.48, 0), AL::ALValue::array(3, 0, 0));
}

