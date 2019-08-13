EESchema Schematic File Version 4
LIBS:Clever_Light-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R5
U 1 1 5D3A9077
P 2900 2450
F 0 "R5" V 3000 2450 50  0000 C CNN
F 1 "360" V 2900 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" V 2830 2450 50  0001 C CNN
F 3 "~" H 2900 2450 50  0001 C CNN
	1    2900 2450
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5D3AA088
P 2900 1650
F 0 "R4" V 3000 1650 50  0000 C CNN
F 1 "360" V 2900 1650 50  0000 C CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" V 2830 1650 50  0001 C CNN
F 3 "~" H 2900 1650 50  0001 C CNN
	1    2900 1650
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 5D3AA1EC
P 1500 1950
F 0 "R3" V 1600 1950 50  0000 C CNN
F 1 "680" V 1500 1950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1430 1950 50  0001 C CNN
F 3 "~" H 1500 1950 50  0001 C CNN
	1    1500 1950
	0    1    1    0   
$EndComp
$Comp
L Device:R R1
U 1 1 5D3AA2C9
P 1300 1000
F 0 "R1" V 1400 1000 50  0000 C CNN
F 1 "2.2k" V 1300 1000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1230 1000 50  0001 C CNN
F 3 "~" H 1300 1000 50  0001 C CNN
	1    1300 1000
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5D3AAB8B
P 3000 1000
F 0 "R2" V 2900 1000 50  0000 C CNN
F 1 "4.7k" V 3000 1000 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 2930 1000 50  0001 C CNN
F 3 "~" H 3000 1000 50  0001 C CNN
	1    3000 1000
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 1950 1900 1950
Wire Wire Line
	1900 2150 1750 2150
Wire Wire Line
	1750 2150 1750 2250
Wire Wire Line
	1350 1950 1150 1950
$Comp
L power:GND #PWR01
U 1 1 5D3B06EB
P 1550 1300
F 0 "#PWR01" H 1550 1050 50  0001 C CNN
F 1 "GND" H 1555 1127 50  0000 C CNN
F 2 "" H 1550 1300 50  0001 C CNN
F 3 "" H 1550 1300 50  0001 C CNN
	1    1550 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5D3B0BD0
P 1750 2250
F 0 "#PWR02" H 1750 2000 50  0001 C CNN
F 1 "GND" H 1755 2077 50  0000 C CNN
F 2 "" H 1750 2250 50  0001 C CNN
F 3 "" H 1750 2250 50  0001 C CNN
	1    1750 2250
	1    0    0    -1  
$EndComp
$Comp
L Clever_Light-rescue:BTA08-600SWRG-BTA08-600SWRG IC1
U 1 1 5D3A683B
P 3650 2150
F 0 "IC1" H 4100 1900 50  0000 C CNN
F 1 "BTA08-600SWRG" H 4100 2300 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabUp" H 4400 2250 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/1/BTA08-600SWRG.pdf" H 4400 2150 50  0001 L CNN
F 4 "" H 4400 2050 50  0001 L CNN "Description"
F 5 "4.6" H 4400 1950 50  0001 L CNN "Height"
F 6 "511-BTA08-600SW" H 4400 1850 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.com/Search/Refine.aspx?Keyword=511-BTA08-600SW" H 4400 1750 50  0001 L CNN "Mouser Price/Stock"
F 8 "STMicroelectronics" H 4400 1650 50  0001 L CNN "Manufacturer_Name"
F 9 "BTA08-600SWRG" H 4400 1550 50  0001 L CNN "Manufacturer_Part_Number"
	1    3650 2150
	-1   0    0    1   
$EndComp
Wire Wire Line
	2500 2150 2650 2150
Wire Wire Line
	2500 1950 2650 1950
Wire Wire Line
	2650 1950 2650 1650
Wire Wire Line
	2650 1650 2750 1650
Wire Wire Line
	2650 2150 2650 2450
Wire Wire Line
	2650 2450 2750 2450
Connection ~ 2650 2150
Wire Wire Line
	2650 2150 2750 2150
Wire Wire Line
	3050 1650 3650 1650
Wire Wire Line
	3650 1650 3650 2050
Wire Wire Line
	3650 2150 3650 2450
Wire Wire Line
	3650 2450 3050 2450
Wire Wire Line
	2650 1100 2750 1100
Wire Wire Line
	2750 1100 2750 1000
Wire Wire Line
	2750 1000 2850 1000
Wire Wire Line
	1450 1000 1550 1000
Wire Wire Line
	1550 1000 1550 1100
Wire Wire Line
	1550 1100 1650 1100
Wire Wire Line
	1650 1200 1550 1200
Wire Wire Line
	1550 1200 1550 1300
Wire Wire Line
	2650 1200 2750 1200
Wire Wire Line
	2750 1200 2750 1300
Wire Wire Line
	2750 1300 3150 1300
Wire Wire Line
	3650 1650 3750 1650
Connection ~ 3650 1650
Wire Wire Line
	3650 2450 3750 2450
Connection ~ 3650 2450
Text GLabel 3750 1650 2    50   Input ~ 0
L
Text GLabel 3750 2450 2    50   Input ~ 0
LOAD
Text GLabel 1150 1950 0    50   Input ~ 0
ON
Text GLabel 1150 1000 0    50   Input ~ 0
DIM
Text GLabel 3150 1000 2    50   Input ~ 0
DIM+
Text GLabel 3150 1300 2    50   Input ~ 0
DIM-
$Comp
L Connector_Generic:Conn_02x07_Odd_Even J5
U 1 1 5D3C643E
P 4850 2100
F 0 "J5" H 4900 1700 50  0000 C CNN
F 1 "Conn_02x07_Odd_Even" H 4900 2550 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x07_P2.54mm_Vertical" H 4850 2100 50  0001 C CNN
F 3 "~" H 4850 2100 50  0001 C CNN
	1    4850 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J4
U 1 1 5D3D9330
P 7550 1050
F 0 "J4" V 7800 1000 50  0000 C CNN
F 1 "Screw_Terminal_01x02" V 7700 1000 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 7550 1050 50  0001 C CNN
F 3 "~" H 7550 1050 50  0001 C CNN
	1    7550 1050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5D3D5C00
P 6600 1050
F 0 "J3" V 6850 1000 50  0000 C CNN
F 1 "Screw_Terminal_01x02" V 6750 1000 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 6600 1050 50  0001 C CNN
F 3 "~" H 6600 1050 50  0001 C CNN
	1    6600 1050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 5D3D5396
P 5650 1050
F 0 "J2" V 5900 1000 50  0000 C CNN
F 1 "Screw_Terminal_01x02" V 5800 1000 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 5650 1050 50  0001 C CNN
F 3 "~" H 5650 1050 50  0001 C CNN
	1    5650 1050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5D3CCECA
P 4700 1050
F 0 "J1" V 4950 1000 50  0000 C CNN
F 1 "Screw_Terminal_01x02" V 4850 1000 50  0000 C CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-2-5.0-H_1x02_P5.00mm_Horizontal" H 4700 1050 50  0001 C CNN
F 3 "~" H 4700 1050 50  0001 C CNN
	1    4700 1050
	0    -1   -1   0   
$EndComp
Text GLabel 5850 1800 2    50   Input ~ 0
BUTTON1
$Comp
L power:GND #PWR04
U 1 1 5D3E69C3
P 5750 2500
F 0 "#PWR04" H 5750 2250 50  0001 C CNN
F 1 "GND" H 5755 2327 50  0000 C CNN
F 2 "" H 5750 2500 50  0001 C CNN
F 3 "" H 5750 2500 50  0001 C CNN
	1    5750 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5D3E8DCB
P 5750 2150
F 0 "R6" H 5650 2150 50  0000 C CNN
F 1 "4.7k" V 5750 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 5680 2150 50  0001 C CNN
F 3 "~" H 5750 2150 50  0001 C CNN
	1    5750 2150
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 1800 5750 1800
Wire Wire Line
	5750 1800 5750 2000
$Comp
L power:GND #PWR03
U 1 1 5D3EBEE4
P 5250 2500
F 0 "#PWR03" H 5250 2250 50  0001 C CNN
F 1 "GND" H 5255 2327 50  0000 C CNN
F 2 "" H 5250 2500 50  0001 C CNN
F 3 "" H 5250 2500 50  0001 C CNN
	1    5250 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2200 5250 2200
Wire Wire Line
	5250 2200 5250 2300
Wire Wire Line
	5150 2300 5250 2300
Connection ~ 5250 2300
Wire Wire Line
	5250 2300 5250 2400
Wire Wire Line
	5150 2400 5250 2400
Connection ~ 5250 2400
Wire Wire Line
	5250 2400 5250 2500
Wire Wire Line
	5750 2300 5750 2500
Wire Wire Line
	5750 1800 5850 1800
Connection ~ 5750 1800
Text GLabel 5150 2100 2    50   Input ~ 0
BUTTON2
Text GLabel 4800 1250 3    50   Input ~ 0
BUTTON2
Text GLabel 4700 1250 3    50   Input ~ 0
BUTTON1
Text GLabel 5150 2000 2    50   Input ~ 0
ON
Text GLabel 5150 1900 2    50   Input ~ 0
DIM
Text GLabel 5750 1250 3    50   Input ~ 0
DIM-
Text GLabel 5650 1250 3    50   Input ~ 0
DIM+
Text GLabel 6600 1250 3    50   Input ~ 0
L
Text GLabel 7550 1250 3    50   Input ~ 0
LOAD
Text GLabel 6700 1250 3    50   Input ~ 0
N
Text GLabel 7650 1250 3    50   Input ~ 0
N
NoConn ~ 4650 1800
NoConn ~ 4650 1900
NoConn ~ 4650 2000
NoConn ~ 4650 2100
NoConn ~ 4650 2200
NoConn ~ 4650 2300
NoConn ~ 4650 2400
$Comp
L Clever_Light-rescue:SFH6156-3T-SFH6156-3T Q1
U 1 1 5D3C0E10
P 1650 1100
F 0 "Q1" H 2150 1365 50  0000 C CNN
F 1 "SFH6156-3T" H 2150 1274 50  0000 C CNN
F 2 "Package_DIP:SMDIP-4_W9.53mm_Clearance8mm" H 2500 1200 50  0001 L CNN
F 3 "https://www.vishay.com/docs/83671/sfh6156.pdf" H 2500 1100 50  0001 L CNN
F 4 "Optocoupler Transistor O/P 1-CH" H 2500 1000 50  0001 L CNN "Description"
F 5 "4.059" H 2500 900 50  0001 L CNN "Height"
F 6 "Vishay" H 2500 800 50  0001 L CNN "Manufacturer_Name"
F 7 "SFH6156-3T" H 2500 700 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "782-SFH6156-3T" H 2500 600 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.com/Search/Refine.aspx?Keyword=782-SFH6156-3T" H 2500 500 50  0001 L CNN "Mouser Price/Stock"
F 10 "6998225P" H 2500 400 50  0001 L CNN "RS Part Number"
F 11 "http://uk.rs-online.com/web/p/products/6998225P" H 2500 300 50  0001 L CNN "RS Price/Stock"
F 12 "70061473" H 2500 200 50  0001 L CNN "Allied_Number"
F 13 "https://www.alliedelec.com/vishay-small-signal-opto-products-ssp-sfh6156-3t/70061473/" H 2500 100 50  0001 L CNN "Allied Price/Stock"
	1    1650 1100
	1    0    0    -1  
$EndComp
$Comp
L Relay_SolidState:MOC3063M U1
U 1 1 5D3C235B
P 2200 2050
F 0 "U1" H 2200 2375 50  0000 C CNN
F 1 "MOC3063M" H 2200 2284 50  0000 C CNN
F 2 "Package_DIP:DIP-6_W10.16mm_LongPads" H 2000 1850 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/MO/MOC3061M.pdf" H 2165 2050 50  0001 L CNN
	1    2200 2050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
