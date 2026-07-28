/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
volatile x=0;
int options=0;//todos
int intervalos1=0; //rectangular alterna
int intervarusa=0;
uint32_t muestra_adc=0;

uint32_t dac_buffer0[701] = {1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,1004,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,714,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,1287,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,445,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,1536,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,1725,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,1836,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,1859,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,1791,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,137,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,1639,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,326,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,1417,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,575,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,1148,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858,858};

//uint32_t dac_buffer00[1001] = {
//931,931,933,937,942,948,955,962,970,978,986,994,1000,1006,1011,1014,1015,1014,1011,1006,999,989,978,964,948,931,912,891,871,849,828,807,787,769,752,737,726,717,711,709,710,716,726,739,757,778,803,831,862,895,930,967,1005,1042,1080,1116,1150,1182,1211,1236,1256,1272,1283,1289,1288,1282,1270,1252,1228,1198,1163,1124,1080,1033,983,931,877,823,769,717,667,620,577,539,506,480,460,448,443,446,456,475,501,535,576,623,676,734,797,863,930,1000,1069,1137,1203,1266,1324,1377,1424,1463,1495,1518,1531,1536,1531,1516,1491,1457,1415,1364,1305,1239,1168,1092,1012,931,848,765,684,606,532,463,402,348,302,267,241,226,222,230,249,278,319,370,430,498,575,657,745,837,930,1025,1119,1211,1300,1383,1460,1529,1589,1639,1678,1705,1721,1724,1714,1692,1658,1612,1554,1487,1410,1325,1233,1135,1034,930,826,723,622,526,436,352,278,213,160,118,89,74,71,83,108,146,196,259,333,416,508,607,711,820,930,1042,1151,1258,1360,1456,1543,1621,1689,1745,1788,1817,1833,1834,1821,1794,1753,1699,1633,1555,1468,1371,1268,1159,1046,931,815,702,591,486,388,298,218,149,93,49,20,5,4,19,47,90,146,214,294,384,482,588,699,814,930,1047,1162,1273,1379,1477,1567,1647,1715,1771,1814,1842,1857,1856,1841,1812,1768,1712,1643,1563,1473,1375,1270,1159,1046,930,815,702,593,490,393,306,228,162,108,67,40,27,28,44,73,116,172,240,318,405,501,603,710,819,930,1041,1150,1254,1353,1445,1528,1602,1665,1715,1753,1778,1790,1787,1772,1743,1701,1648,1583,1509,1425,1335,1239,1138,1035,930,827,726,628,536,451,374,307,249,203,169,147,137,140,156,183,222,272,332,401,478,561,650,742,836,931,1024,1116,1204,1286,1363,1431,1491,1542,1583,1612,1631,1639,1635,1620,1594,1559,1513,1459,1398,1329,1255,1177,1096,1013,931,849,769,693,622,556,497,446,404,370,345,330,325,330,343,366,398,437,484,537,595,658,724,792,861,930,998,1064,1127,1185,1238,1285,1326,1360,1386,1405,1415,1418,1413,1401,1381,1355,1322,1284,1241,1194,1144,1092,1038,984,931,878,828,781,737,698,663,633,609,591,579,573,572,578,589,605,625,650,679,711,745,781,819,856,894,930,966,999,1030,1058,1083,1104,1122,1135,1145,1151,1152,1150,1144,1135,1124,1109,1092,1074,1054,1033,1012,990,970,949,930,913,897,883,872,862,855,850,847,846,847,850,855,861,867,875,883,891,899,906,913,919,924,928,930,931,930,928,924,919,913,906,899,891,883,875,867,861,855,850,847,846,847,850,855,862,872,883,897,913,930,949,970,990,1012,1033,1054,1074,1092,1109,1124,1135,1144,1150,1152,1151,1145,1135,1122,1104,1083,1058,1030,999,966,930,894,856,819,781,745,711,679,650,625,605,589,578,572,573,579,591,609,633,663,698,737,781,828,878,930,984,1038,1092,1144,1194,1241,1284,1322,1355,1381,1401,1413,1418,1415,1405,1386,1360,1326,1285,1238,1185,1127,1064,998,931,861,792,724,658,595,537,484,437,398,366,343,330,325,330,345,370,404,446,497,556,622,693,769,849,931,1013,1096,1177,1255,1329,1398,1459,1513,1559,1594,1620,1635,1639,1631,1612,1583,1542,1491,1431,1363,1286,1204,1116,1024,931,836,742,650,561,478,401,332,272,222,183,156,140,137,147,169,203,249,307,374,451,536,628,726,827,931,1035,1138,1239,1335,1425,1509,1583,1648,1701,1743,1772,1787,1790,1778,1753,1715,1665,1602,1528,1445,1353,1254,1150,1041,931,819,710,603,501,405,318,240,172,116,73,44,28,27,40,67,108,162,228,306,393,490,593,702,815,931,1046,1159,1270,1375,1473,1563,1643,1712,1768,1812,1841,1856,1857,1842,1814,1771,1715,1647,1567,1477,1379,1273,1162,1047,931,814,699,588,482,384,294,214,146,90,47,19,4,5,20,49,93,149,218,298,388,486,591,702,815,930,1046,1159,1268,1371,1468,1555,1633,1699,1753,1794,1821,1834,1833,1817,1788,1745,1689,1621,1543,1456,1360,1258,1151,1042,931,820,711,607,508,416,333,259,196,146,108,83,71,74,89,118,160,213,278,352,436,526,622,723,826,930,1034,1135,1233,1325,1410,1487,1554,1612,1658,1692,1714,1724,1721,1705,1678,1639,1589,1529,1460,1383,1300,1211,1119,1025,931,837,745,657,575,498,430,370,319,278,249,230,222,226,241,267,302,348,402,463,532,606,684,765,848,930,1012,1092,1168,1239,1305,1364,1415,1457,1491,1516,1531,1536,1531,1518,1495,1463,1424,1377,1324,1266,1203,1137,1069,1000,931,863,797,734,676,623,576,535,501,475,456,446,443,448,460,480,506,539,577,620,667,717,769,823,877,930,983,1033,1080,1124,1163,1198,1228,1252,1270,1282,1288,1289,1283,1272,1256,1236,1211,1182,1150,1116,1080,1042,1005,967,931,895,862,831,803,778,757,739,726,716,710,709,711,717,726,737,752,769,787,807,828,849,871,891,912,930,948,964,978,989,999,1006,1011,1014,1015,1014,1011,1006,1000,994,986,978,970,962,955,948,942,937,933,931,931
//};

uint32_t dac_buffer1 [701] ={1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,1861,0,7,14,22,29,36,43,50,57,64,70,77,84,91,97,104,111,117,124,130,136,143,149,155,162,168,174,180,186,192,198,204,210,216,222,227,233,239,245,250,256,262,267,273,278,283,289,294,300,305,310,315,320,326,331,336,341,346,351,356,361,366,370,375,380,385,390,394,399,404,408,413,417,422,426,431,435,440,444,448,453,457,461,465,470,474,478,482,486,490,494,498,502,506,510,514,518,522,526,529,533,537,541,544,548,552,555,559,563,566,570,573,577,580,584,587,590,594,597,601,604,607,610,614,617,620,623,626,630,633,636,639,642,645,648,651,654,657,660,663,666,669,672,674,677,680,683,686,688,691,694,697,699,702,705,707,710,712,715,718,720,723,725,728,730,733,735,737,740,742,745,747,749,752,754,756,759,761,763,765,768,770,772,774,776,779,781,783,785,787,789,791,793,795,797,799,801,803,805,807,809,811,813,815,817,819,821,823,825,826,828,830,832,834,835,837,839,841,843,844,846,848,849,851,853,854,856,858,859,861,863,864,866,867,869,870,872,873,875,877,878,880,881,882,884,885,887,888,890,891,893,894,895,897,898,899,901,902,904,905,906,907,909,910,911,913,914,915,916,918,919,920,921,923,924,925,926,927,928,930,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931};

//uint32_t dac_buffer[100];
//uint16_t dato_dac;
int freq;

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc3;
DMA_HandleTypeDef hdma_adc3;

DAC_HandleTypeDef hdac1;
DMA_HandleTypeDef hdma_dac_ch1;
DMA_HandleTypeDef hdma_dac_ch2;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_DAC1_Init(void);
static void MX_TIM2_Init(void);
static void MX_ADC3_Init(void);
static void MX_TIM4_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void DAC_Voltaje(float volt){

	volt = (volt > 3.3) ? 3.3 : (volt < 0) ? 0 : volt;
	uint16_t dato_dac=(uint16_t)((volt*4095)/3.3);
    HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1,DAC_ALIGN_12B_R, dato_dac);
       }


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_DAC1_Init();
  MX_TIM2_Init();
  MX_ADC3_Init();
  MX_TIM4_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  HAL_ADC_Start_DMA(&hadc3, &muestra_adc, 1);

  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_1);
  HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_2);

  HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
  HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1,DAC_ALIGN_12B_R, 0);
 // HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t*)dac_buffer, N_SAMPLES, DAC_ALIGN_12B_R);




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	 /* DAC_Voltaje(1.5);
	  HAL_Delay(2000);
	  DAC_Voltaje(0);
	  HAL_Delay(2000);*/

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC3_Init(void)
{

  /* USER CODE BEGIN ADC3_Init 0 */

  /* USER CODE END ADC3_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC3_Init 1 */

  /* USER CODE END ADC3_Init 1 */

  /** Common config
  */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc3.Init.Resolution = ADC_RESOLUTION_12B;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc3.Init.LowPowerAutoWait = DISABLE;
  hadc3.Init.ContinuousConvMode = ENABLE;
  hadc3.Init.NbrOfConversion = 1;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc3.Init.DMAContinuousRequests = ENABLE;
  hadc3.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc3.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_247CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC3_Init 2 */

  /* USER CODE END ADC3_Init 2 */

}

/**
  * @brief DAC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_DAC1_Init(void)
{

  /* USER CODE BEGIN DAC1_Init 0 */

  /* USER CODE END DAC1_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC1_Init 1 */

  /* USER CODE END DAC1_Init 1 */

  /** DAC Initialization
  */
  hdac1.Instance = DAC1;
  if (HAL_DAC_Init(&hdac1) != HAL_OK)
  {
    Error_Handler();
  }

  /** DAC channel OUT1 config
  */
  sConfig.DAC_SampleAndHold = DAC_SAMPLEANDHOLD_DISABLE;
  sConfig.DAC_Trigger = DAC_TRIGGER_NONE;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  sConfig.DAC_ConnectOnChipPeripheral = DAC_CHIPCONNECT_DISABLE;
  sConfig.DAC_UserTrimming = DAC_TRIMMING_FACTORY;
  if (HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }

  /** DAC channel OUT2 config
  */
  sConfig.DAC_Trigger = DAC_TRIGGER_T4_TRGO;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_DISABLE;
  if (HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC1_Init 2 */

  /* USER CODE END DAC1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 79;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_OC_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_TIMING;
  sConfigOC.Pulse = 2000;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_OC_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.Pulse = 8000;
  if (HAL_TIM_OC_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 9999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 19;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 54;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);
  /* DMA1_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA2_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Channel4_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	freq=((muestra_adc*80)/4095);
	freq = (freq >80 ) ? 80 : (freq < 7) ? 7 : freq;
	TIM2->PSC=freq;

if(options==0){
	TIM2->PSC=freq/2;
}


  if (htim->Instance == TIM2)
  {
	  if (options==0){//rect alterna
	  if (intervalos1==0){// solo rect alterna

		   DAC_Voltaje(1.5);
		   intervalos1=1;
		   TIM2->CCR1=2000;
	  }else{
		  DAC_Voltaje(0);
		  intervalos1=0;
		  TIM2->CCR1=2000;
	  }
	  }else if(options==1){//Bifasica simetrica
		  DAC_Voltaje(1.5);
		  TIM2->CCR1=2000;
		  TIM2->CCR2=4000;
	  }else if(options==2){
		  DAC_Voltaje(1.5);
		  TIM2->CCR1=727;
		  TIM2->CCR2=1454;
	  }

	}else if (htim->Instance == TIM3)
	  {
x++;
		freq=((muestra_adc*20)/4095);
		freq = (freq >20 ) ? 20 : (freq < 1) ? 1 : freq;
		TIM4->PSC=freq;

		if(options==3){
			TIM4->PSC=freq;
		}else if (options==4){

			TIM4->PSC=freq;
		}

	  }

}

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim) {
if (htim->Instance == TIM2) {
   if (HAL_TIM_GetActiveChannel(htim) == HAL_TIM_ACTIVE_CHANNEL_1) {
    	if (options==0){ //rect alterna
        DAC_Voltaje(0.75);

    	}else if(options==1){//Bifasica simetrica
    		DAC_Voltaje(0);
    	}else if(options==2){
    		if(TIM2->CCR1<=6875){
    		DAC_Voltaje(0);
    		TIM2->CCR1+=1454;
    		}
    	}

    }else if(HAL_TIM_GetActiveChannel(htim) == HAL_TIM_ACTIVE_CHANNEL_2){
    	if (options==1){
    		DAC_Voltaje(0.75);
    	}else if(options==2){
    		if(TIM2->CCR2<=6875){
    	    		DAC_Voltaje(1.5);
    	    		TIM2->CCR2+=1454;
    	    		}else{DAC_Voltaje(0.75);}
    	}
    	}
  }else if (htim->Instance == TIM3) {

	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	x++;
	options++;
	if(options==3){
	/*	HAL_TIM_Base_Stop_IT(&htim2);
		HAL_TIM_OC_Stop_IT(&htim2, TIM_CHANNEL_1);
		HAL_TIM_OC_Stop_IT(&htim2, TIM_CHANNEL_2);
		HAL_DAC_Stop(&hdac1, DAC_CHANNEL_1);*/


		///////////

		 HAL_DAC_Start(&hdac1, DAC_CHANNEL_2);
		 HAL_TIM_Base_Start(&htim4);
		 HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, dac_buffer0,701, DAC_ALIGN_12B_R);

	}else if(options==4){
		HAL_DAC_Stop_DMA(&hdac1, DAC_CHANNEL_2);
		HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, dac_buffer1,701, DAC_ALIGN_12B_R);

	}else if(options==5){
		HAL_TIM_Base_Stop(&htim4);
		HAL_DAC_Stop_DMA(&hdac1, DAC_CHANNEL_2);
		options=0;
		x=0;

		 /* HAL_TIM_Base_Start_IT(&htim2);
		  HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_1);
		  HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_2);
		  HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);*/

	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
