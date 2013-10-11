#include "wuhuan.h"

struct parameter
{
	float PV;
	float SV;
	float TV;
	float QV;
	float LoopCurrent; //unit : mA
	float PercnetOfRange; // unit : %
	unsigned char PollingAddr;
	unsigned char LoopCurrentMode;
	unsigned char Msg[24];  //packed
	unsigned char Tag[6];   //packed
	unsigned char Dscp[12];  //descriptor , packed
	unsigned char Date[3];  //date : day/month/year
	unsigned char Tsn[3];  //transducer serial number
	float TransducerUpper;  //PV transducer unit code is the same as PV_UNIT
	float TransducerLower;
	float PVMinSpan;
	float PVUpperRange;
	float PVlowerRange;
	float PVDampingTime;
	enum alarm Alarm;
	enum transfer_func TransferFunc;
	enum protect ProtectStatus;
	enum analog_channel AnalogChlFlg;
	unsigned char Fan[3]; //final assembly number
}para;

/* DV */
void  set_pv(float pv) {		para.PV = pv; }
float get_pv(void)     { 	return para.PV; }
void  set_sv(float sv) { 	para.SV = sv; 	}
float get_sv(void)     { 	return para.SV; }
void  set_tv(float tv) { 	para.TV = tv; 	}
float get_tv(void)     { 	return para.TV; }
void  set_qv(float qv) { 	para.QV = qv; 	}
float get_qv(void)     { 	return para.QV; }
/* loop current and percent of range */
void  set_loop_current(float current) { para.LoopCurrent = current; }
float get_loop_current(void) { return para.LoopCurrent; }
void  set_percent_of_range(float percent_of_range) { para.LoopCurrent = percent_of_range; }
float get_percent_of_range(void) { return para.PercnetOfRange; }
void set_polling_addr(unsigned char polling_addr) { para.PollingAddr = polling_addr; }
/* polling address and loop current mode */
unsigned char get_polling_addr(void) { return para.PollingAddr; }
void set_loop_current_mode(unsigned char current_mode) { para.LoopCurrentMode = current_mode; }
unsigned char get_loop_current_mode(void) { return para.LoopCurrentMode; }
/* message */
void set_message(unsigned char *msg)
{
	unsigned char i = 0;
	for(i = 0;i < 24;i++)
	{
		para.Msg[i] = *(msg+1);
	}
}
unsigned char *get_message(void) { return para.Msg; }
/* tag and descriptor and date */
void set_tag(unsigned char *tag)
{
	unsigned char i = 0;
	for(i = 0;i < 6;i++)
	{
		para.Tag[i] = *(tag+i);
	}
}
unsigned char *get_tag(void) { return para.Tag; }
void set_descriptor(unsigned char *dscp)
{
	unsigned char i = 0;
	for(i = 0;i < 12;i++)
	{
		para.Dscp[i] = *(dscp+i);
	}
}
unsigned char *get_descriptor(void) { return para.Dscp; }
void set_date(unsigned char *date)
{
	unsigned char i = 0;
	for(i = 0;i < 3;i++)
	{
		para.Date[i] = *(date+i);
	}
}
unsigned char *get_date(void) { return para.Date; }
/* PV transducer information */
void set_transducer_serial_num(unsigned char *tsn)
{
	unsigned char i = 0;
	for(i = 0;i < 3;i++)
	{
		para.Tsn[i] = *(tsn+i);
	}
}
unsigned char *get_transducer_serial_num(void) { return para.Tsn; }
void set_transducer_upper(float tsd_upper) { para.TransducerUpper = tsd_upper; }
float get_transducer_upper(void) { return para.TransducerUpper; }
void set_transducer_lower(float tsd_lower) { para.TransducerLower = tsd_lower; }
float get_transducer_lower(void) { return para.TransducerLower; }
void set_pv_min_span(float min_span) { para.PVMinSpan = min_span; }
float get_pv_min_span(void) { return para.PVMinSpan; }
/* PV information */
void set_pv_upper_range(float upper_range) { para.PVUpperRange = upper_range; }
float get_pv_upper_range(void) { return para.PVUpperRange; }
void set_pv_lower_range(float lower_range) { para.PVlowerRange = lower_range; }
float get_pv_lower_range(void) { return para.PVlowerRange; }
void set_pv_damping_time(float damping_time) { para.PVDampingTime = damping_time; }
float get_pv_damping_time(void) { return para.PVDampingTime; }
void set_alarm_sw(enum alarm alarm) { para.Alarm = alarm; }
enum alarm get_alarm_sw(void) { return para.Alarm; }
void set_transfer_func(enum transfer_func tsf_func) { para.TransferFunc = tsf_func; }
enum transfer_func get_transfer_func(void) { return para.TransferFunc; }
void set_protect(enum protect protect_status) { para.ProtectStatus = protect_status; }
enum protect get_protect(void) { return para.ProtectStatus; }
void set_analog_channel(enum analog_channel analog_chl) { para.AnalogChlFlg = analog_chl; }
enum analog_channel get_analog_channel(void) { return para.AnalogChlFlg; }
/* final assembly number */
void set_final_assembly_num(unsigned char *fan)
{
	unsigned char i = 0;
	for(i = 0;i < 3;i++)
	{
		para.Fan[i] = *(fan+i);
	}
}
unsigned char *get_final_assembly_num(void) { return para.Fan; }






