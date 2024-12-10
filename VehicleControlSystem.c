/*
 ============================================================================
 Name        : VehicleControlSystem.c
 Author      : Basmala Sherief
 Version     :
 Copyright   : Your copyright notice
 Description : Vehicle Control system
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define ON 1
#define OFF 0
char engine ,sensor,traffic;
int EngineState=OFF,ACState=OFF,EngineTControl=OFF;
int VehicleSpeed=100,Rtemperature=35,Etemperature=90;
int traffic_light(char *tch);
int room_temperature_data(int *rtemp);
int engine_temperature(int *etemp);
void CurrentVehicleState(int *ES,int *ac,int *vs,int *rt,int *etcs,int *et);
void engine_menu(void)
{
	printf("Enter the letter for the engine state you want :\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	fflush(stdout);
}
void Sensors_set_menu(void)
{
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
	printf("\n");
	fflush(stdout);
	printf("Enter the letter for the sensor you want :\n");
	fflush(stdout);
	scanf(" %c",&sensor);
	if(sensor=='a')
		engine_menu();
	else if(sensor=='b')
	{
		printf("Enter the traffic light color :\n");
		fflush(stdout);
		scanf(" %c",&traffic);
		traffic_light(&traffic);
		VehicleSpeed=traffic_light(&traffic);
		CurrentVehicleState(&EngineState,&ACState,&VehicleSpeed,&Rtemperature,&EngineTControl,&Etemperature);
	}
	else if(sensor=='c')
	{
		printf("Enter the room temperature :\n");
		fflush(stdout);
		scanf(" %d",&Rtemperature);
		ACState=room_temperature_data(&Rtemperature);
		CurrentVehicleState(&EngineState,&ACState,&VehicleSpeed,&Rtemperature,&EngineTControl,&Etemperature);
	}
	else if(sensor=='d')
	{
		printf("Enter the engine temperature :\n");
		fflush(stdout);
		scanf(" %d",&Etemperature);
		EngineTControl=engine_temperature(&Etemperature);
		CurrentVehicleState(&EngineState,&ACState,&VehicleSpeed,&Rtemperature,&EngineTControl,&Etemperature);
	}
}
int main(void) {
	engine_menu();
	scanf(" %c",&engine);
	if(engine=='c')
	{
		EngineState=OFF;
		printf("Program is closed\n");
        printf("System is Quit\n");
	}
	else if(engine=='b')
	{
		EngineState=OFF;
		printf("Engine is turned off\n");
		engine_menu();
	}
	else if(engine=='a')
	{
		EngineState=ON;
		printf("Engine is turned on\n");
		Sensors_set_menu();
		if(sensor=='b')
			Sensors_set_menu();
		else if(sensor=='c')
			Sensors_set_menu();
		else if(sensor=='d')
			Sensors_set_menu();
	}
	else
	{
		printf("You entered a wrong letter please try again :)\n");
		engine_menu();
	}
	return 0;
}
int traffic_light(char *tch)
{
	int VS;
	if(*tch=='G')
	{
		VS=100;
	}
	else if(*tch=='O')
	{
		VS=30;
		ACState=ON;
		Rtemperature*=(5/4)+1;
		EngineTControl=ON;
		Etemperature*=(5/4)+1;
	}
	else if(*tch=='R')
	{
		VS=0;
	}
	return VS;
}
int room_temperature_data(int *rtemp)
{
	char AC;
	if((*rtemp<=10)||(*rtemp>=30))
	{
		AC=ON;
		*rtemp=20;
		printf("Room temperature = 20\n");
	}
	else
	{
		AC=OFF;
		printf("Room temperature is cool\n");
	}
	return AC;
}
int engine_temperature(int *etemp)
{
	char controler;
	if((*etemp<=100)||(*etemp>=150))
	{
		controler=ON;
		*etemp=125;
		printf("Engine temperature = 125\n");
	}
	else
	{
		controler=OFF;
		printf("Engine temperature is suitable\n");
	}
	return controler;
}
void CurrentVehicleState(int *ES,int *ac,int *vs,int *rt,int *etcs,int *et)
{
	printf("Engine state : %d\n",*ES);
	printf("AC state : %d\n",*ac);
	printf("Vehicle speed : %d\n",*vs);
	printf("Room temperature : %d\n",*rt);
	printf("Engine temperature controller state : %d\n",*etcs);
	printf("Engine temperature : %d\n",*et);
}
