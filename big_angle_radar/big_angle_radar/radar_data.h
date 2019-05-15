#pragma once
struct big_angle_radar_target_info {
	float targetid;//target id
	float x;//x
	float y;//y
	float v;//speed
	float acc;//accelerate speed
};

struct big_angle_radar_data {
	float Targets;//radar test itself flag
	float type;//1 represents this is radar_data
	float  version;//protocol version
	float curtime;//time
	big_angle_radar_target_info targets[59];
	int compensation;//enable the struct is 1200 Byte
};

struct UDP_stream_data {
	char a1[4];//data1 header flag
	big_angle_radar_data b1;
	char a2[4];//data2 header flag
	big_angle_radar_data b2;
};
