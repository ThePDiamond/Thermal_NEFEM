/*
This document contains the equations for the conduction, convection, and radiation equations
*/

#include <vector>
#include "ThermalEquations.h"

ThermalEquations::ThermalEquations()
:	mInitialTemperatureField(),
	mConductionHeatFluxField(),
	mConvectionHeatFluxField(),
	mRadiationHeatFluxField(),
	mThermalConductivity(),
	mEmissivity()
{}

ThermalEquations::~ThermalEquations(){}

void ThermalEquations::SetInitialConditions(std::vector<int> & rNodeNumbers, std::vector<double> & rInitialTemperature) {
	for (int i=0; i < rNodeNumbers.size(); i++)
	{
		mInitialTemperatureField.insert({ rNodeNumbers[i], rInitialTemperature[i]});
	}
}

void ThermalEquations::SetTField(std::vector<int> & rNodeNumbers, std::vector<double> & rTemperature) {
	for (int i = 0; i < rNodeNumbers.size(); i++)
	{
		mTemperatureField.insert({ rNodeNumbers[i], rTemperature[i] });
	}
}

void ThermalEquations::SetConductionHeatFluxField(std::vector<int> & rNodeNumbers, FluxVector & rHeatFlux) {
	for (int i = 0; i < rNodeNumbers.size(); i++)
	{
		mConductionHeatFluxField.emplace( rNodeNumbers[i], rHeatFlux[0] );
	}
}

void ThermalEquations::SetConvectionHeatFluxField(std::vector<int> & rNodeNumbers, std::vector<Coordinates> & rHeatFlux) {
	for (int i = 0; i < rNodeNumbers.size(); i++)
	{
		mConvectionHeatFluxField.emplace( rNodeNumbers[i], rHeatFlux[i] );
	}
}

void ThermalEquations::SetRadiationHeatFluxField(std::vector<int> & rNodeNumbers, std::vector<Coordinates> & rHeatFlux) {
	for (int i = 0; i < rNodeNumbers.size(); i++)
	{
		mRadiationHeatFluxField.emplace( rNodeNumbers[i], rHeatFlux[i] );
	}
}

FluxVector ThermalEquations::HeatTransferConduction(std::vector<int> rNodeNumbers) {

}