#include <vector>
#include <map>

typedef std::vector<std::vector<double>> Matrix;
typedef std::array<double, 3> Coordinates;
typedef std::vector<Coordinates> FluxVector;

class ThermalEquations {
public:

	ThermalEquations();

	virtual ~ThermalEquations();

	void SetInitialConditions(std::vector<int> & rNodeNumbers, std::vector<double> & rInitialTemperature);

	void SetTField(std::vector<int> & rNodeNumbers, std::vector<double> & rTemperature);

	void SetConductionHeatFluxField(std::vector<int> & rNodeNumbers, FluxVector & rHeatFlux);

	void SetConvectionHeatFluxField(std::vector<int> & rNodeNumbers, std::vector<Coordinates>  & rHeatFlux);

	void SetRadiationHeatFluxField(std::vector<int> & rNodeNumbers, std::vector<Coordinates> & rHeatFlux);

	FluxVector HeatTransferConduction(std::vector<int> rNodeNumbers);

	FluxVector HeatTransferConvection(std::vector<int> rNodeNumbers, const double rFreeStreamT);

	FluxVector HeatTransferRadiation(std::vector<int> rNodeNumbers, const double rFreeStreamT, const double rSBConst);

	std::vector<double> ConductionTemperatureField(std::vector<int> rNodeNumbers, FluxVector rConductionHeatFlux);

	std::vector<double> ConvectionTemperatureField(std::vector<int> rNodeNumbers, FluxVector rConvectionHeatFlux);

	std::vector<double> RadiationTemperatureField(std::vector<int> rNodeNumbers, FluxVector rRadiationHeatFlux);

private:

	Matrix mHeatTransferConduction;

	Matrix mHeatTransferConvection;

	Matrix mHeatTransferRadiation;

	std::map<int, double> mInitialTemperatureField;

	std::map<int, double> mTemperatureField;

	std::map<int, Coordinates> mConductionHeatFluxField;

	std::map<int, Coordinates> mConvectionHeatFluxField;

	std::map<int, Coordinates> mRadiationHeatFluxField;

	const std::map<int, Coordinates> mThermalConductivity;

	const double SBconst = 5.67e-8;

	const std::map<int, Coordinates> mEmissivity;

	const double mFreeStreamT = 288.15;
};