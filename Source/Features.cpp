#include "stdafx.h"
#define PROP_MONEY_BAG_01 0x113FD533
#define PICKUP_MONEY_CASE 0x1E9A99F8
#define PROP_MONEY_BAG_02 -1666779307

//bool Features::isPlayerGodmodder(Ped ped)
//{
//	auto playerPed = Hooking::handle_ptr(ped);
//
//	if (playerPed != 0) {
//		bool isIn = INTERIOR::IS_VALID_INTERIOR(INTERIOR::GET_INTERIOR_FROM_ENTITY(ped));
//		if (!isIn)
//		{
//			bool isInvincible = *reinterpret_cast<bool*>(playerPed + 0x189);
//			return isInvincible;
//		}
//	}
//
//	return false;
//}

void Features::weiﬂernigger(bool toggle)
{

//ldfjksaejfksejfksjf

}

bool Features::penisdunigger = false;
auto IsPedShooting(std::int32_t p)
{
	return PED::GET_PED_CONFIG_FLAG(p, 58, TRUE);
}

Vector3 add3(Vector3* vectorA, Vector3* vectorB)
{
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;

	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;

	return result;
}
Vector3 multiply3(Vector3* vector, float x)
{
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;

	result.x *= x;
	result.y *= x;
	result.z *= x;

	return result;
}

char* CharKeyboard2(char* windowName = "", int maxInput = 21, char* defaultText = "")
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

//
void WheelPTFX(char* streamName, char* PTFXName) {

	uint myVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	STREAMING::REQUEST_NAMED_PTFX_ASSET(streamName);
	if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(streamName))
	{
		Vector3 pos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_lf"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos.x, pos.y, pos.z, 0.f, 0.f, 0.f, Features::carPTFXsize, false, false, false);

		Vector3 pos1 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_lr"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos1.x, pos1.y, pos1.z, 0.f, 0.f, 0.f, Features::carPTFXsize, false, false, false);

		Vector3 pos2 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_rf"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos2.x, pos2.y, pos2.z, 0.f, 0.f, 0.f, Features::carPTFXsize, false, false, false);

		Vector3 pos3 = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(myVeh, ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(myVeh, "wheel_rr"));
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(streamName);
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_AT_COORD_2(PTFXName, pos3.x, pos3.y, pos3.z, 0.f, 0.f, 0.f, Features::carPTFXsize, false, false, false);
	}
	else STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
}

//void PTFXCALLBoneless(char* call1, char* call2, char* name, int bone) {
//	float fx = 0.08f;
//	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
//	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
//	int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(name, PLAYER::PLAYER_PED_ID(), 0.00f, 0.00f, 0.00f,
//		0.00f, 0.00f, 0.0f, bone, fx, 1, 1, 1);
//	STREAMING::REMOVE_PTFX_ASSET();
//
//}
//float Menu::Settings::bulletp = 0.1;
void PTFXCALLBoneless(char* call1, char* call2, char* name, int bone) {
	float fx = Menu::Settings::bulletp;
	STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
	int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(name, PLAYER::PLAYER_PED_ID(), 0.00f, 0.00f, 0.00f,
		0.00f, 0.00f, 0.0f, bone, fx, 1, 1, 1);
	STREAMING::REMOVE_PTFX_ASSET();

}
std::vector<std::string> listFiles(LPCSTR directory)
{
	std::vector<std::string> tempVector;
	int fileCount = 0;
	std::stringstream tempStringStream;
	for (auto & collectedFiles : std::experimental::filesystem::v1::directory_iterator(directory)) {
		tempStringStream << collectedFiles;
		std::string testing = tempStringStream.str();
		if (testing.substr(testing.find_last_of(".") + 1) == "mp3") {
			unsigned foundAmount = testing.find_last_of("/");
			std::string TempHolder = testing.substr(0, foundAmount);
			std::string TempHolder2 = testing.substr(foundAmount + 1);
			tempVector.push_back(TempHolder2.substr(0, TempHolder2.find(".", 0)));
		}
	}
	return tempVector;
}
std::string FloatToString(float flt) {
	std::ostringstream ss;
	ss << flt;
	std::string str(ss.str());
	return str;
}

float StringToFloat(std::string str) {
	return ::atof(str.c_str());
}
Vehicle SpawnVehicleH(DWORD model, Vector3 coords, bool tpinto = 0, float heading = 0.0f) {
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = VEHICLE::erstelle_fahr(model, coords.x, coords.y, coords.z, heading, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		if (tpinto) {
			ENTITY::SET_ENTITY_HEADING(veh, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()));
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return veh;
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}
std::vector<int> ToggleTypes = { 17, 18, 19, 20, 21, 22 };
std::vector<int> ModTypes = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 23, 24, 26, 25, 48, 37, 27, 28, 30, 33, 34, 35, 38, 39, 45 };
std::vector<Object> Spawned;
void printf(std::string f) {
	printf(f.c_str());
}
Object AttachObjectToVehicleByHash(Hash hash, float x, float y, float z, float rotx, float roty, float rotz, Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)) {
	if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
		//CMenu::notifyBottom("~r~You need to be in a vehicle to load a preset !");
		return -1;
	}
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash)) {
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
		Vector3 co = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Object obj = OBJECT::CREATE_OBJECT_NO_OFFSET(hash, co.x, co.y, co.z, 1, 0, 0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(obj);
		ENTITY::FREEZE_ENTITY_POSITION(obj, 1);
		printf("Calling");
		ENTITY::ATTACH_ENTITY_TO_ENTITY(obj, veh, 0, x, y, z, rotx, roty, rotz, 1, 0, 1, 0, 2, 1);
		WAIT(25);
		return obj;
	}
	else {
		printf("Not in image");
		return -1;
	}
}
bool DoesFileExists(std::string path) {
	if (std::ifstream(path)) return true;
	return false;
}
void WriteVehicle(std::string name, Vehicle veh) {
	std::string iniPath = ".\\BLDRFolder\\ini files\\" + name + ".ini";
	for (int i = 0; i < ModTypes.size(); i++) {
		WritePrivateProfileStringA("Vehicle", FloatToString(ModTypes[i]).c_str(), FloatToString(VEHICLE::GET_VEHICLE_MOD(veh, ModTypes[i])).c_str(), iniPath.c_str());
	}
	int HUDColour, HUDLightsColour;
	//VEHICLE::_GET_INTERIOR_DASH_LIGHT_COLOR(veh, &HUDLightsColour);
	//VEHICLE::_GET_INTERIOR_COATING_COLOR(veh, &HUDColour);
	WritePrivateProfileStringA("Vehicle", "DashColor", FloatToString(HUDColour).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "DashLightColor", FloatToString(HUDLightsColour).c_str(), iniPath.c_str());
	int PpaintType = 0;
	int Pcolor = 0;
	int SpaintType = 0;
	int Scolor = 0;
	int Sr, Sg, Sb, Pr, Pg, Pb;
	int Prnd;
	int pearlescent, wheelColor;
	int wheelType = VEHICLE::GET_VEHICLE_WHEEL_TYPE(veh);
	int PlateIndex = VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh);
	char* PlateText = VEHICLE::GET_VEHICLE_NUMBER_PLATE_TEXT(veh);
	bool Bulletproof = !VEHICLE::GET_VEHICLE_TYRES_CAN_BURST(veh);
	bool CustomTyres = VEHICLE::GET_VEHICLE_MOD_VARIATION(veh, 23);
	WritePrivateProfileStringA("Vehicle", "Bulletproof", FloatToString(Bulletproof).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "CustomTyres", FloatToString(CustomTyres).c_str(), iniPath.c_str());
	int NeonR, NeonG, NeonB, SmokeR, SmokeG, SmokeB;
	bool NeonEnabled;
	VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(veh, &NeonR, &NeonG, &NeonB);
	VEHICLE::GET_VEHICLE_TYRE_SMOKE_COLOR(veh, &SmokeR, &SmokeG, &SmokeB);
	if (VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 0)) NeonEnabled = 1;
	for (int i = 0; i < ToggleTypes.size(); i++) {
		WritePrivateProfileStringA("Vehicle", std::string("TOGGLE_" + FloatToString(ToggleTypes[i])).c_str(), FloatToString(VEHICLE::IS_TOGGLE_MOD_ON(veh, ToggleTypes[i])).c_str(), iniPath.c_str());
	}
	int WindowTintIndex = VEHICLE::GET_VEHICLE_WINDOW_TINT(veh);
	WritePrivateProfileStringA("Vehicle", "NeonEnabled", FloatToString(NeonEnabled).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "NeonR", FloatToString(NeonR).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "NeonG", FloatToString(NeonG).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "NeonB", FloatToString(NeonB).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SmokeR", FloatToString(SmokeR).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SmokeG", FloatToString(SmokeG).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SmokeB", FloatToString(SmokeB).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "WindowTint", FloatToString(WindowTintIndex).c_str(), iniPath.c_str());
	VEHICLE::GET_VEHICLE_MOD_COLOR_1(veh, &PpaintType, &Pcolor, &Prnd);
	VEHICLE::GET_VEHICLE_MOD_COLOR_2(veh, &SpaintType, &Scolor);
	VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, &Pr, &Pg, &Pb);
	VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, &Sr, &Sg, &Sb);
	VEHICLE::GET_VEHICLE_EXTRA_COLOURS(veh, &pearlescent, &wheelColor);
	std::ostringstream os; os << ENTITY::GET_ENTITY_MODEL(veh);
	WritePrivateProfileStringA("Vehicle", "Model", os.str().c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryPaintT", FloatToString(PpaintType).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryPaintT", FloatToString(SpaintType).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryPaint", FloatToString(Pcolor).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryPaint", FloatToString(Scolor).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "Pearlescent", FloatToString(pearlescent).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryR", FloatToString(Pr).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryG", FloatToString(Pg).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PrimaryB", FloatToString(Pb).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryR", FloatToString(Sr).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryG", FloatToString(Sg).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "SecondaryB", FloatToString(Sb).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "WheelsColor", FloatToString(wheelColor).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "WheelsType", FloatToString(wheelType).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "Unknown", FloatToString(Prnd).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "Unknown", FloatToString(PlateIndex).c_str(), iniPath.c_str());
	WritePrivateProfileStringA("Vehicle", "PlateText", PlateText, iniPath.c_str());
	for (int i = 0; i < 10; i++) {
		if (VEHICLE::DOES_EXTRA_EXIST(veh, i)) {
			WritePrivateProfileStringA("Vehicle", std::string("Extra_" + FloatToString(i)).c_str(), FloatToString(VEHICLE::IS_VEHICLE_EXTRA_TURNED_ON(veh, i)).c_str(), iniPath.c_str());
		}
	}
	//CMenu::notifyBottom("~g~Successfully saved vehicle. !");
}

void WritePreset(std::string name, float id, float x, float y, float z, float rotx, float roty, float rotz, Hash model) {
	std::string iniPath = ".\\BLDRFolder\\ini files\\" + name + ".ini"; //change path
	if (!std::ifstream(iniPath)) std::ofstream file(iniPath);
	if (DoesFileExists(iniPath)) {
		//CMenu::notifyBottom("~r~You already have a preset with this name");
		return;
	}
	std::string X = FloatToString(x);
	std::string Y = FloatToString(y);
	std::string Z = FloatToString(z);
	std::string RotX = FloatToString(rotx);
	std::string RotY = FloatToString(roty);
	std::string RotZ = FloatToString(rotz);
	std::string Model = FloatToString(model);
	std::string Id = FloatToString(id);
	WritePrivateProfileStringA(Id.c_str(), "X", X.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "Y", Y.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "Z", Z.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "RotX", RotX.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "RotY", RotY.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "RotZ", RotZ.c_str(), iniPath.c_str());
	WritePrivateProfileStringA(Id.c_str(), "Model", Model.c_str(), iniPath.c_str());
}
void SavePreset(std::vector<ObjectInfo> ObjectList, std::string name, bool bWriteVehicle = 0) {
	std::string iniPath = ".\\BLDRFolder\\ini files\\" + name + ".ini"; //change path
	if (bWriteVehicle) WriteVehicle(name, PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
	for (int i = 0; i < ObjectList.size(); i++) {
		std::ostringstream os;
		os << ObjectList[i].hash;
		ObjectList[i].X = round(ObjectList[i].X * 10000) / 10000;
		ObjectList[i].Y = round(ObjectList[i].Y * 10000) / 10000;
		ObjectList[i].Z = round(ObjectList[i].Z * 10000) / 10000;
		ObjectList[i].RotX = round(ObjectList[i].RotX * 10000) / 10000;
		ObjectList[i].RotY = round(ObjectList[i].RotY * 10000) / 10000;
		ObjectList[i].RotZ = round(ObjectList[i].RotZ * 10000) / 10000;
		WritePrivateProfileStringA(FloatToString(i).c_str(), "X", FloatToString(ObjectList[i].X).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "Y", FloatToString(ObjectList[i].Y).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "Z", FloatToString(ObjectList[i].Z).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "RotX", FloatToString(ObjectList[i].RotX).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "RotY", FloatToString(ObjectList[i].RotY).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "RotZ", FloatToString(ObjectList[i].RotZ).c_str(), iniPath.c_str());
		WritePrivateProfileStringA(FloatToString(i).c_str(), "Model", os.str().c_str(), iniPath.c_str());
		printf("\r\n<SAVE # " + FloatToString(i) + " > \r\n");
		printf("\r\nName:" + name);
		printf("\r\X:" + FloatToString(ObjectList[i].X));
		printf("\r\nY:" + FloatToString(ObjectList[i].Y));
		printf("\r\nZ:" + FloatToString(ObjectList[i].Z));
		printf("\r\nRotX:" + FloatToString(ObjectList[i].RotX));
		printf("\r\nRotY:" + FloatToString(ObjectList[i].RotY));
		printf("\r\nRotZ:" + FloatToString(ObjectList[i].RotZ));
		printf("\r\n< END OF SAVE # " + FloatToString(i) + " > \r\n");
	}
	//CMenu::notifyBottom("Preset Saved !");
}
std::string ReadPresetKey(std::string name, std::string section, std::string key) {
	std::string iniPath = ".\\BLDRFolder\\ini files\\" + name + ".ini";
	if (!std::ifstream(iniPath)) {
		std::ofstream file(iniPath);
	}
	char retVal[255];
	GetPrivateProfileStringA(section.c_str(), key.c_str(), "", retVal, 255, iniPath.c_str());
	return retVal;
}
bool DoesPresetKeyExists(std::string name, std::string section, std::string key) {
	return ReadPresetKey(name, section, key).length() > 0;
}
int GetNumberOfObjectFromFile(std::string name) {
	std::string iniPath = ".\\BLDRFolder\\ini files\\" + name + ".ini";
	int no = 0;
	for (int i = 0; i < 150; i++) {
		if (DoesPresetKeyExists(name, FloatToString(i), "X")) {
			no++;
		}
		else {
			return no;
		}
	}
	return no;
}
DWORD StringToDWORD(std::string str) {
	DWORD doubleWord;
	std::string dwordHexString = str;
	std::stringstream dwordStream;
	dwordStream << dwordHexString;
	dwordStream >> std::hex >> doubleWord;
	return doubleWord;
}
int st(std::string txt) { return atoi(txt.c_str()); }
Vehicle LoadVehicle(std::string name) {
	std::string iniPath = ".\\BLDRFolder\\ini files\\" + name + ".ini";
	if (DoesPresetKeyExists(name, "Vehicle", "Model")) {
		Hash Model = static_cast<DWORD>(atoll(ReadPresetKey(name, "Vehicle", "Model").c_str()));
		Vehicle veh = SpawnVehicleH(Model, ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0, 5, 0), 1);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
		int WheelsType;
		WheelsType = st(ReadPresetKey(name, "Vehicle", "WheelsType"));
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, WheelsType);
		bool CustomTyres = st(ReadPresetKey(name, "Vehicle", "CustomTyres"));
		for (int i = 0; i < ModTypes.size(); i++) {
			int mod = st(ReadPresetKey(name, "Vehicle", FloatToString(ModTypes[i])));
			VEHICLE::SET_VEHICLE_MOD(veh, ModTypes[i], mod, CustomTyres);
		}
		int HUDColor = st(ReadPresetKey(name, "Vehicle", "DashColor"));
		int HUDLightsColor = st(ReadPresetKey(name, "Vehicle", "DashLightColor"));
		TEST::_SET_INTERIOR_DASH_LIGHT_COLOR(veh, HUDLightsColor);
		TEST::_SET_INTERIOR_COATING_COLOR(veh, HUDColor);
		std::string PlateText;
		int NeonR, NeonG, NeonB, SmokeR, SmokeG, SmokeB, BulletProof;
		bool NeonEnabled;
		for (int i = 0; i < ToggleTypes.size(); i++) {
			int mod = st(ReadPresetKey(name, "Vehicle", std::string("TOGGLE_" + FloatToString(ToggleTypes[i])).c_str()));

			VEHICLE::TOGGLE_VEHICLE_MOD(veh, ToggleTypes[i], mod);
		}
		int WindowTintIndex = st(ReadPresetKey(name, "Vehicle", "WindowTint"));
		NeonEnabled = st(ReadPresetKey(name, "Vehicle", "NeonEnabled"));
		NeonR = st(ReadPresetKey(name, "Vehicle", "NeonR"));
		NeonG = st(ReadPresetKey(name, "Vehicle", "NeonG"));
		NeonB = st(ReadPresetKey(name, "Vehicle", "NeonB"));
		SmokeR = st(ReadPresetKey(name, "Vehicle", "SmokeR"));
		SmokeG = st(ReadPresetKey(name, "Vehicle", "SmokeG"));
		SmokeB = st(ReadPresetKey(name, "Vehicle", "SmokeB"));
		BulletProof = st(ReadPresetKey(name, "Vehicle", "Bulletproof"));
		if (BulletProof == 1) {
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
			VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
		}
		if (NeonEnabled) {
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, NeonR, NeonG, NeonB);
		}
		VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, WindowTintIndex);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, SmokeR, SmokeG, SmokeB);
		int PrimaryPaintType, SecondaryPaintType, PrimaryPaintID, SecondaryPaintID, Pearlescent, PrimaryR, PrimaryG, PrimaryB, SecondaryR, SecondaryG, SecondaryB, WheelsColor, Unknown, PlateIndex;
		PrimaryPaintType = st(ReadPresetKey(name, "Vehicle", "PrimaryPaintT"));
		SecondaryPaintType = st(ReadPresetKey(name, "Vehicle", "SecondaryPaintT"));
		PrimaryPaintID = st(ReadPresetKey(name, "Vehicle", "PrimaryPaint"));
		SecondaryPaintID = st(ReadPresetKey(name, "Vehicle", "SecondaryPaint"));
		Pearlescent = st(ReadPresetKey(name, "Vehicle", "Pearlescent"));
		PrimaryR = st(ReadPresetKey(name, "Vehicle", "PrimaryR"));
		PrimaryG = st(ReadPresetKey(name, "Vehicle", "PrimaryG"));
		PrimaryB = st(ReadPresetKey(name, "Vehicle", "PrimaryB"));
		SecondaryR = st(ReadPresetKey(name, "Vehicle", "SecondaryR"));
		SecondaryG = st(ReadPresetKey(name, "Vehicle", "SecondaryG"));
		SecondaryB = st(ReadPresetKey(name, "Vehicle", "SecondaryB"));
		WheelsColor = st(ReadPresetKey(name, "Vehicle", "WheelsColor"));
		Unknown = st(ReadPresetKey(name, "Vehicle", "Unknown"));
		PlateIndex = st(ReadPresetKey(name, "Vehicle", "PlateIndex"));
		PlateText = ReadPresetKey(name, "Vehicle", "PlateText");
		VEHICLE::SET_VEHICLE_MOD_COLOR_1(veh, PrimaryPaintType, PrimaryPaintID, Unknown);
		VEHICLE::SET_VEHICLE_MOD_COLOR_2(veh, SecondaryPaintType, SecondaryPaintID);
		VEHICLE::SET_VEHICLE_COLOURS(veh, PrimaryPaintID, SecondaryPaintID);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, Pearlescent, WheelsColor);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, PrimaryR, PrimaryG, PrimaryB);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, SecondaryR, SecondaryG, SecondaryB);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, PlateIndex);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, (char*)PlateText.c_str());
		//CMenu::notifyBottom("~g~Successfully loaded vehicle. !");
		for (int i = 0; i < 10; i++) {
			if (VEHICLE::DOES_EXTRA_EXIST(veh, i)) {
				int ExtraToggle = st(ReadPresetKey(name, "Vehicle", "Extra_" + FloatToString(i)));
				if (ExtraToggle == 1) {
					VEHICLE::SET_VEHICLE_EXTRA(veh, i, 0);
				}
				else {
					VEHICLE::SET_VEHICLE_EXTRA(veh, i, -1);
				}
			}
		}
		return veh;
	}
	return -1;
}
ObjectInfo ReadCustomPreset(std::string name, int id) {
	ObjectInfo oi;
	std::string iniPath = ".\\BLDRFolder\\ini files\\" + name + ".ini";
	std::ostringstream ID; ID << id;
	oi.hash = static_cast<DWORD>(atoll(ReadPresetKey(name, ID.str(), "Model").c_str()));
	oi.X = StringToFloat((char*)ReadPresetKey(name, ID.str(), "X").c_str());
	oi.Y = StringToFloat((char*)ReadPresetKey(name, ID.str(), "Y").c_str());
	oi.Z = StringToFloat((char*)ReadPresetKey(name, ID.str(), "Z").c_str());
	oi.RotX = StringToFloat((char*)ReadPresetKey(name, ID.str(), "RotX").c_str());
	oi.RotY = StringToFloat((char*)ReadPresetKey(name, ID.str(), "RotY").c_str());
	oi.RotZ = StringToFloat((char*)ReadPresetKey(name, ID.str(), "RotZ").c_str());
	return oi;
}
std::vector<std::string> listPresets(LPCSTR directory)
{
	std::vector<std::string> tempVector;
	int fileCount = 0;
	std::stringstream tempStringStream;
	for (auto & collectedFiles : std::experimental::filesystem::v1::directory_iterator(directory)) {
		tempStringStream << collectedFiles;
		std::string testing = tempStringStream.str();
		if (testing.substr(testing.find_last_of(".") + 1) == "ini") {
			unsigned foundAmount = testing.find_last_of("/\\");
			std::string TempHolder = testing.substr(0, foundAmount);
			std::string TempHolder2 = testing.substr(foundAmount + 1);
			tempVector.push_back(TempHolder2.substr(0, TempHolder2.find(".", 0)));
		}
	}
	return tempVector;
}
void LoadPreset(std::string name) {
	Vehicle veh = LoadVehicle(name);
	for (int i = 0; i < GetNumberOfObjectFromFile(name); i++) {
		if (veh != -1) {
			ObjectInfo preset = ReadCustomPreset(name, i);
			Object ob = AttachObjectToVehicleByHash(preset.hash, preset.X, preset.Y, preset.Z, preset.RotX, preset.RotY, preset.RotZ, veh);
			Spawned.push_back(ob);
		}
		else {
			if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
				//CMenu::notifyBottom("You need to be in a vehicle to do this"); return;
			}
			ObjectInfo preset = ReadCustomPreset(name, i);
			Object ob = AttachObjectToVehicleByHash(preset.hash, preset.X, preset.Y, preset.Z, preset.RotX, preset.RotY, preset.RotZ);
			Spawned.push_back(ob);
		}
	}
}
Vector3 rotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}

int Features::l = 1;
int Features::l1 = 1;
int Features::l2 = 1;
int Features::l3 = 1;
int Features::l4 = 1;
int Features::l5 = 1;
int Features::l6 = 1;





char *call1o;
char *call2o;
char *nameo;
Ped PTLoopPed;

char *call1s;
char *call2s;
char *names;

typedef void(__fastcall* tSET_ENTITY_INVINCIBLE)(int entity, bool toggle);
//Set Invincible Ped
void SET_ENTITY_INVINCIBLE(const int& entity, const bool& toggle)
{
	static tSET_ENTITY_INVINCIBLE oSET_ENTITY_INVINCIBLE = (tSET_ENTITY_INVINCIBLE)(Memory::pattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 40 8A F2 E8 ? ? ? ? 33 DB").count(1).get(0).get<void>(0));
	oSET_ENTITY_INVINCIBLE(entity, toggle);
}
int Features::current_frame;
int Features::current_framee;
char* Features::current_header;


bool Features::protection_msg = false;
std::vector<__int64> _eventsID = { 1000837481, 994306218, 713068249, 769347061, -15432926, -181444979, -1571039706, -1190833098, 360381720, 4119492672, }; // so ok, added, if you want to add more your remotes, you need to add here hash of it go here
std::vector<const char*> _eventsID_char = { "Teleport to apartments/Blackscreen", "Non - Kick Player", "Specatating - Message", "Kick to Singleplayer", "Send to Mission", "GTA V Banner Screen", "Mission Message", "Ceo Kick Player", "Ceo Ban Player", "Sound Spam", }; // here name of this hash and add name of that remote
char _EventTriggererBuffer[128];
int _EventArgsBuffer[128];


void Features::UpdateLoop() //bool loop
{
	

	if (protection_msg) {
		Features::Spamp(true); //uhm i dont understand ah, ok, so here is your real protection, because I gave you message of remote on you, you need only to add here your currently protections like that
		Features::CEOBanp(true);// understand? yes putin , one more quesation , you have a Sig for .... OWNED_EXPLOSION LIKE MAKE WORKING BLAME EXPLOSION
		Features::CEOKickp(true);
		//Features::sendtospprotec(true);
		Features::Kickprotec(true);
		Features::Teleportprotec(true);
		Features::Bountyy(true);
		Features::remore(true);

		//Features::prbounty(true);
		Features::STJp(true);
		//Features::gut(true);
		for (int i = 0; i < 124; i++)
		{
			int eventID = 0;
			Hooking::get_event_data(1, i, &eventID, 2);
			if (eventID == 1000837481 || eventID == 994306218 || eventID == 769347061 || eventID == -15432926 || eventID == -181444979 || eventID == -1571039706 || eventID == -1190833098 || eventID == 360381720 || eventID == 4119492672)// and here, that's all and if someone will use 994306218 on you, you'll get notify about that
			{ // and only you can add here protections calling like
				bool unknownEvent = true;
				Hooking::get_event_data(1, i, _EventArgsBuffer, 10);

				for (int y = 0; y < sizeof(_eventsID) - 1; y++) {
					if (eventID == _eventsID[y] && unknownEvent) {
						sprintf_s(_EventTriggererBuffer, "~g~%s ~r~Tried To Use The ~f~%s Event", PLAYER::GET_PLAYER_NAME(_EventArgsBuffer[2]), _eventsID_char[y]);
						notifyMap(_EventTriggererBuffer);
						unknownEvent = false;
						break;
					}
				}
				if (unknownEvent) {
					sprintf_s(_EventTriggererBuffer, "~g~%s ~r~Tried To Use Unknown Event ID~f~%i: ", PLAYER::GET_PLAYER_NAME(_EventArgsBuffer[2]), eventID);
					notifyMap(_EventTriggererBuffer);
				}
			}
		}
	}


	if (Features::penisdunigger)
	{
		if ((timeGetTime() - Features::TimePD3) > Features::stealthdelay)
		{
			Any var0 = 0ul;
			int var3 = 312105838;
			int bankVal = true ? 4 : 1;
			UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, Menu::Settings::gayStealth, bankVal);
			UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

			Features::TimePD3 = timeGetTime();

			int iVar0;
			STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
			STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);

			notifyMap("~r~Bank~w~Transaction Active");
		}
	}

	if (Features::geiletitte)
	{

		if ((timeGetTime() - Features::TimePD3) > Features::stealthdelay)
		{
			Any var0 = 0ul;
			int var3 = 312105838;
			int bankVal = false ? 4 : 1;
			UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, Menu::Settings::gayStealth, bankVal);
			UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

			Features::TimePD3 = timeGetTime();

			int iVar0;
			STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
			STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);

			notifyMap("~r~Wallet~w~Transaction Active");
		}



	}

	if (Features::sagtdegeiligeaufiwtion)
	{

		if ((timeGetTime() - Features::TimePD9) > Features::stealthDelaydel)
		{
			if (Features::StealthDropinte) {
				if (Features::sagtdegeiligeaufiwtion)
				{
					if (Features::amount5 > 0) {
						Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
						UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 454359403, 537254313, Features::amount5, Features::sagtdegeiligeaufiwtion ? 4 : 1);
						UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
					}
					else if (Features::amount5 < 0) {
						Any izmon = 2147483647;
						if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&izmon, 1474183246, 454359403, 537254313, Features::amount5, Features::sagtdegeiligeaufiwtion ? 4 : 1)) {
							UNK3::_NETWORK_SHOP_CHECKOUT_START(izmon);
						}
					}
				}
				Features::TimePD9 = timeGetTime();
			}
		}


	}

	if (Features::etiennejoelsex)
	{
		if ((timeGetTime() - Features::TimePD14) > Features::stealthDelaydel)
		{
			if (Features::StealthDropinte) {
				if (Features::etiennejoelsex)
				{
					int bankVal = false ? 4 : 1;
					if (Features::amount5 > 0) {
						Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
						UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 454359403, 537254313, Features::amount5, bankVal);
						UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
					}
					else if (Features::amount5 < 0) {
						Any izmon = 2147483647;
						if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&izmon, 1474183246, 454359403, 537254313, Features::amount5, bankVal)) {
							UNK3::_NETWORK_SHOP_CHECKOUT_START(izmon);
						}
					}
				}
				Features::TimePD14 = timeGetTime();
			}

		}



	}


	if (Features::ichwichsedireintommy)
	{
		if ((timeGetTime() - Features::TimePD2) > 5000)
		{
			Ped iPed = PLAYER::PLAYER_PED_ID();
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), FALSE);
			Ped spawnedPed = PED::CREATE_RANDOM_PED(playerPosition.x, playerPosition.y, playerPosition.z + 10);
			ENTITY::SET_ENTITY_VELOCITY(spawnedPed, 0, 0, -20);
			ENTITY::SET_ENTITY_NO_COLLISION_ENTITY(spawnedPed, PLAYER::PLAYER_PED_ID(), FALSE);
			PED::SET_PED_MONEY(spawnedPed, 10000);
			ENTITY::SET_ENTITY_HEALTH(spawnedPed, 0);
			ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&spawnedPed);
			Features::TimePD2 = timeGetTime();

		}

	}



	static auto ticker = GetTickCount();
	if ((GetTickCount() - ticker) >= Features::bandelay) {
		if (current_frame >= 2) {
			current_frame = 0;

		}
		else {
			current_frame++;
		}

		current_header = _strdup(("frame" + std::to_string(current_frame)).c_str());

		ticker = GetTickCount();
	}


	playerGodMode ? GodMode(true) : NULL;

	SlowMotion ? slowMotion(true) : NULL;

	enginealwaysonbool ? enginealwayson(true) : NULL;

	nightvisionbool ? nightvision(true) : NULL;

	NeverWanted ? neverWanted(true) : NULL;

	ChaosMode ? Chaos(true) : NULL;

	betiny ? TinyPlayer(true) : NULL;

	superman ? Superman(true) : NULL;

	animatednum ? numbani(true) : NULL;

	mobileRadio ? mobilevoid(true) : NULL;

	moneyGunBagfakepl ? moneyGunBagfakeplall(true) : NULL;

	rbgun ? RBGuner(true) : NULL;

	fcbool ? FlyingCarLoop(true) : NULL;

	orbool ? OffRadar(true) : NULL;

	runfast ? RunFast(false) : NULL;

	dowbool ? DriveOnWater(true) : NULL;

	rlbool ? HasPaintLoop(true) : NULL;

	infammo ? noreloadv(true) : NULL;

	NeverWantedTest1 ? NeverWantedTest2(true) : NULL;

	boostbool ? carboost(true) : NULL;

	playersuperjump ? SuperJump(true) : NULL;

	playerinvisibility ? Invisibility(true) : NULL;

	//playernoragdoll ? NoRagdoll(true) : NULL;

	playertenkped ? TenKPedMoney(true) : NULL;

	featureVisionDrunk ? featureVisionDrunkUpdated(true) : NULL;

	ShootMini ? ShootMiniGun(true) : NULL;

	ShootBall ? ShootBalls(true) : NULL;

	Molitov ? molitov(true) : NULL;

	GravityGun ? gravitygun(true) : NULL;

	ShootTankR ? ShootTankRounds(true) : NULL;

	ShootT ? ShootTanks(true) : NULL;

	ShootR ? ShootRocket(true) : NULL;

	ShootHydra ? Shootthehydra(true) : NULL;

	ShootWeaponT ? ShootWeaponTank(true) : NULL;

	ShootDump ? ShootDumpTruck(true) : NULL;

	ShootBuz ? ShootBuzzard(true) : NULL;

	Trigger ? TriggerAim(true) : NULL;

	ShootZen ? ShootZentorno(true) : NULL;

	ShootSWI ? ShootSWIFT(true) : NULL;

	ShootBo ? ShootBoar(true) : NULL;

	ShootCo ? ShootCow(true) : NULL;

	playersuperjump ? SuperJump(true) : NULL;

	Orbital ? Orbi(true) : NULL;

	Sell ? Sel(true) : NULL;

	waterGun ? WaterGun(true) : NULL;

	explodeGun ? ExplodeGun(true) : NULL;

	pedGun ? PedGun(true) : NULL;

	fireGun ? FireGun(true) : NULL;

	expAmmo ? expAmmos(true) : NULL;

	moneyGun ? MoneyGun(true) : NULL;

	MILJET ? MIL(true) : NULL;

	SHAMAL ? SHAM(true) : NULL;

	MILJET ? MIL(true) : NULL;

	GravGun ? GravGunFunction() : NULL;


	TITAN ? TITANT(true) : NULL;

	rainbowmenu ? Rainbowmenu(true) : NULL;

	AMBUL ? AMBULANCE(true) : NULL;

	orbool ? OffRadar(true) : NULL;

	NameESP ? NameTagESP(true) : NULL;

	Weapontest ? weapontest(true) : NULL;

	UltraJ ? UltraJumpp(true) : NULL;

	runfast1 ? RunFast1(true) : NULL;

	Fake ? fake(true) : NULL;

	//rainself ? Rainself(true) : NULL;

	extremejump ? Extremejump(true) : NULL;

	delgun ? DelGun(true) : NULL;

	Vehgun ? vehgun(true) : NULL;

	RPG ? rpg(true) : NULL;

	Grenade ? grenade(true) : NULL;

	Smoke ? smoke(true) : NULL;

	cyrclenew ? CyrcleNew(true) : NULL;

	Backboost ? backboost(true) : NULL;

	dropme2 ? cashdrop23(true) : NULL;

	savenewdrop6 ? cashdrop6(true) : NULL;

	savenewdrop ? cashdrop(true) : NULL;

	savenewdrop3 ? cashdrop3(true) : NULL;

	StealthLooptoggle ? StealthLoop(true) : NULL;

	StealthLooptoggle2 ? StealthLoop2(true) : NULL;

	savenewdrop3 ? cashdrop(true) : NULL;

	savenewdrop5 ? cashdrop5(true) : NULL;

	savenewdrop4 ? cashdrop4(true) : NULL;

	rain2 ? Rain2(true) : NULL;

	savenewdrop21 ? cashdrop21(true) : NULL;

	rainself ? Rainself(true) : NULL;

	savenewdrop112 ? cashdrop112(true) : NULL;

	savenewdrop7 ? cashdrop7(true) : NULL;

	savenewdrop31 ? cashdrop31(true) : NULL;

	MOLOTOV ? molotov(true) : NULL;

	Flare ? flare(true) : NULL; 

	ShootFlare ? Shootflare(true) : NULL;

	Air ? air(true) : NULL;

	BALL ? ball(true) : NULL;

	stealth ? Stealth(true) : NULL;

	gay ? Gay(true) : NULL;

	votes ? kickvotes(true) : NULL;

	explosion ? antiexplosion(true) : NULL;

	profire ? antifire(true) : NULL;

	revweapons ? remoweapons(true) : NULL;

	remote ? inforemote(true) : NULL;

	report ? reattacks(true) : NULL;

	att ? antiattacks(true) : NULL;

	WEATHER ? WEATHERtacks(true) : NULL;

	WANTED ? WANTEDLEVEL(true) : NULL;

	WANTED_LEVEL ? WANTEDLEVELL(true) : NULL;

	RAGDOLL ? REQUESTEVENT(true) : NULL;

	TAUNT ? PLAYERTAUNT(true) : NULL;

	NETWORK ? INCREMENT(true) : NULL;

	NETWORKCRC ? NETWORK_CRC(true) : NULL;

	bypass ? moneyBypass(true) : NULL;

	Speedometerbool ? Speedometer(true) : NULL;

	Testgun ? testgun(true) : NULL;

	particlee1 ? ParticlEE1(true) : NULL;

	particlee ? ParticllE(true) : NULL;

	particle3 ? ParticlE3(true) : NULL;

	particle4 ? ParticlE4(true) : NULL;

	particle5 ? ParticlE5(true) : NULL;

	particle6 ? ParticlE6(true) : NULL;

	particle7 ? ParticlE7(true) : NULL;

	particle8 ? ParticlE8(true) : NULL;

	flybool ? playerflyer(true) : NULL;

	ghostrider ? firerider(true) : NULL;

	remover ? RemoveR(true) : NULL;

	RPLoop ? rpLoop(true) : NULL;

	ShootAnimals ? shootanimal(true) : NULL;

	Laser ? laser(true) : NULL;

	RLaser ? Rlaser(true) : NULL;

	DisplayFPS ? featureDisplayFPS(true) : NULL;

	para ? paranormal(true) : NULL;

	MYDROP ? mydrop(true) : NULL;

	alldrop ? AllDrop(true) : NULL;

	randommon ? randommonnn(true) : NULL;

	Raser ? raser(true) : NULL;

	leagun ? leaWgun(true) : NULL;

	stealthnewsafe ? newStealthLoop(true) : NULL;

	editmoney ? MoneyEdit(true) : NULL;

	Stop ? stop(true) : NULL;

	Superr ? SuperDooper(true) : NULL;

	flxneav ? nearbflx(true) : NULL;

	explodenearbytiresbool ? explodenearbytires(true) : NULL;
	
	hornnearbyvehiclesbool ? hornnearbyvehicles(true) : NULL;

	Vehgunafter ? vehgunafter(true) : NULL;

	isInfBoost ? InfiniteBoost(true) : NULL;

	Color ? color(true) : NULL;

	Colorr ? colorr(true) : NULL;

	Colorrr ? colorrr(true) : NULL;

	delopp ? lolopp(true) : NULL;

	timeerlevel ? settimechang(true) : NULL;

	playerWantedLevel ? ChangeWanted(true) : NULL;

	osk ? OSKR(true) : NULL;

	//closedoors ? doorsclose(true) : NULL;

	Light ? light(true) : NULL;

	cped ? cpedd(true) : NULL;

	//GameStop ? gamestop(true) : NULL;

	Drunk ? drunk(true) : NULL;

	//ALARM ? alarm(true) : NULL;

	Explodegunn ? explodegunn(true) : NULL;

	fixfire ? firefix(true) : NULL;

	delop ? lolop(true) : NULL;

	Rneon ? RainbowNeon(true) : NULL;

	dowbool ? DriveOnWater(true) : NULL;

	PoloDance ? polodance(true) : NULL;

	CEOKickProtection ? CEOKickp(true) : NULL;

	tpp ? Teleportprotec(true) : NULL;

	CeoBanProtection ? CEOBanp(true) : NULL;

	SendToJobProtection ? STJp(true) : NULL;

	SoundSpamProtection ? Spamp(true) : NULL;

	Transaction ? Transaktion(true) : NULL;

	AsteroidShower ? AsteroidShowerToggle(true) : NULL;

	Airstrike ? AirstrikeMode(true) : NULL;

	AirstrikeShower ? AirstrikehowerToggle(true) : NULL;

	ControlInfo ? Control(true) : NULL;

	CLOWNGUN ? clowngun(true) : NULL;

	Drift ? DriftMode(true) : NULL;

	isAutoRegHealth ? AutoRegHealth(true) : NULL;

	removerr ? RemoveRR(true) : NULL;

	cargopall ? cargoPall(true) : NULL;

	sounderrorall ? sound55errorall(true) : NULL;

	VALKYIREROCKET ? valkyirerocket(true) : NULL;

	rider ? ghost(true) : NULL;

	soundYacht ? Yacht(true) : NULL;

	soundOffice ? Office(true) : NULL;

	soundClubhouse ? Clubhouse(true) : NULL;

	soundCompany ? Company(true) : NULL;

	soundTuning ? Tuning(true) : NULL;
	
	isAutoRegArmour ? AutoRegArmour(true) : NULL;

	isSlideRun ? slideRun(true) : NULL;

	free ? freeCam(true) : NULL;

	freeT ? freeCamt(true) : NULL;

	blacls ? black(true) : NULL;

	Bounty ? Bountyy(true) : NULL;
	FIREBREATH ? firebreath(true) : NULL;

	ride_container ? container_rider(true) : NULL;

	magnetbool ? magnetActive(true) : NULL;

	trns ? remore(true) : NULL;

	kickp ? Kickprotec(true) : NULL;

	isRevealPlayers ? revealPlayers(true) : NULL;

	stealthh ? Stealthh(true) : NULL;

	orbooll ? OffRadarr(true) : NULL;

	vehGunBool ? vehiclegun(true) : NULL;

	Pedscale ? pedscale(true) : NULL;

	gameCamZoom ? zoomCam() : NULL;

	isCrouchPlayer ? crouchPlayer(true) : NULL;

	Aimbot ? aimbot(true) : NULL;

	Looppedmoney ? MoneyLoopPed(true) : NULL;

	progen ? bribeAuthorities(true) : NULL;

	freezecamera ? camerafreeze(true) : NULL;

	new1 ? new11(true) : NULL;

	new2 ? new22(true) : NULL;

	new3 ? new33(true) : NULL;

	rankspoofpl ? spoofRankpl(true) : NULL;

	exi ? exa(true) : NULL;












	


	//Online
	if (Forcefield) {
		ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 100, 100, 0, 0, 0, false, true, false, false, false, true);
		ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 13, 99.9f, 99.9f, 99.9f, 0.0f, 0.0f, 0.0f, 1, 1, 1, 1, 0, 1);
	}

	if (giver)
	{
		StealthDropinte();
	}

	if (cargodmodebool)
	{
		cargodmode();
	}

	if (rapidfirer)
	{
		rapidmaker();
	}

	if (killpedsbool)
	{
		killpeds();
	}
	if (explodepedsbool)
	{
		explodepeds();
	}
	if (explodenearbyvehiclesbool)
	{
		explodenearbyvehicles();
	}
	if (deletenearbyvehiclesbool)
	{
		deletenearbyvehicles();
	}
	if (bikeNoFall)
	{
		nofallbike();
	}
	if (stickToGround)
	{
		vehStuckToGround();
	}


	
	
	PLAYER::_EXPAND_WORLD_LIMITS(FLT_MAX, FLT_MAX, FLT_MAX);
	for (int ix = 0; ix < 33; ix++)
	{
		if (freezed[ix])
		{
			Freezer(ix);
		}

		if (moneyguntoggles[ix])
		{
			OtherPlayerMoneyGun(ix);
		}
		if (VehgunP[ix])
		{
			vehgunp(ix);
		}
		if (spectate[ix])
		{
			specter(ix);
		}
		if (cargop[ix])
		{
			cargoP(ix);
		}
		if (playerfireloop[ix])
		{
			FireLoop(ix);
		}
		if (playerwaterloop[ix])
		{
			WaterLoop(ix);
		}

		if (rainMoney[ix])
		{
			rainMoney2(ix);
		}


		if (fuckedhandling[ix])
		{
			fuckhandling(ix);
		}
		if (camshaker[ix])
		{
			shakecam(ix);
		}
		if (exploder[ix])
		{
			explodeloop(ix);
		}
		if (esper)
		{
			esp(ix);
		}
		if (toBank) {
			StealthDropintee();
		}
		if (toBank22) {
			StealthDropintee22();
		}
		if (bullshark) {
			Bullshark();
		}
		if (Teleport) {
			teleport();
		}

		if (cashdrop69Toggle[ix]) {
			cashdrop69(ix);
		}

	}

	//if (orbool == false) { globalHandle(2421664).At(PLAYER::PLAYER_ID(), 358).At(203).As<int>() = 0; }

	flybool ? playerflyer(true) : NULL;
	Flex ? flex(true) : NULL;
	Penis ? penis(true) : NULL;
	AmoFire ? amofire(true) : NULL;
	NevW ? nevw(true) : NULL;
	phonedisable ? disablephone() : NULL;

	if (ClownLoop) {
		PTFXCALLBoneless("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x796e);
		PTFXCALLBoneless("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0x8cbd);
		PTFXCALLBoneless("scr_rcbarry2", "scr_rcbarry2", "scr_clown_appears", 0xdead);
	}
	if (fireworkloop) {
		PTFXCALLBoneless("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", 0x796e);
		PTFXCALLBoneless("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", 0x8cbd);
		PTFXCALLBoneless("scr_indep_fireworks", "scr_indep_fireworks", "scr_indep_firework_trailburst", 0xdead);
	}
	if (alien1) {
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", 0x796e);
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", 0x8cbd);
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_disintegrate", 0xdead);
	}
	if (alien2) {
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0x796e);
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0x8cbd);
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0xdead);
	}
	if (electric) {
		PTFXCALLBoneless("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", 0x796e);
		PTFXCALLBoneless("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", 0x8cbd);
		PTFXCALLBoneless("scr_agencyheistb", "scr_agencyheistb", "scr_agency3b_elec_box", 0xdead);
	}
	if (electricberox) {
		PTFXCALLBoneless("scr_trevor1", "scr_trevor1", "scr_trev1_trailer_boosh", 0x796e);
		PTFXCALLBoneless("scr_trevor1", "scr_trevor1", "scr_trev1_trailer_boosh", 0x8cbd);
		PTFXCALLBoneless("scr_trevor1", "scr_trevor1", "scr_trev1_trailer_boosh", 0xdead);
	}
	if (watereffect) {
		PTFXCALLBoneless("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", 0x796e);
		PTFXCALLBoneless("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", 0x8cbd);
		PTFXCALLBoneless("scr_fbi5a", "scr_fbi5a", "scr_fbi5_ped_water_splash", 0xdead);
	}
	if (bloodeffect) {
		PTFXCALLBoneless("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", 0x796e);
		PTFXCALLBoneless("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", 0x8cbd);
		PTFXCALLBoneless("scr_finalec2", "scr_finalec2", "scr_finale2_blood_entry", 0xdead);
	}
	if (smokeeffect) {
		PTFXCALLBoneless("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", 0x796e); // Kopf
		PTFXCALLBoneless("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", 0x8cbd); // hand
		PTFXCALLBoneless("scr_familyscenem", "scr_familyscenem", "scr_meth_pipe_smoke", 0xdead); // Fuﬂ
	}
	if (moneyeffect) {
		PTFXCALLBoneless("scr_rcbarry2", "scr_rcbarry2", "scr_clown_death", 0x796e);
		PTFXCALLBoneless("scr_rcbarry2", "scr_rcbarry2", "scr_clown_death", 0x8cbd);
		PTFXCALLBoneless("scr_rcbarry2", "scr_rcbarry2", "scr_clown_death", 0xdead);
	}
	if (ghosterr) {
		PTFXCALLBoneless("scr_agencyheist", "scr_agencyheist", "scr_fbi_dd_breach_smoke", 0x796e);
		PTFXCALLBoneless("scr_agencyheist", "scr_agencyheist", "scr_fbi_dd_breach_smoke", 0x8cbd);
		PTFXCALLBoneless("scr_agencyheist", "scr_agencyheist", "scr_fbi_dd_breach_smoke", 0xdead);
	}

	if (CarClownLoop) {
		WheelPTFX("scr_rcbarry2", "scr_clown_appears");
	}
	if (Carfireworkloop) {
		WheelPTFX("scr_indep_fireworks", "scr_indep_firework_trailburst");
	}
	if (Caralien1) {
		WheelPTFX("scr_rcbarry1", "scr_alien_disintegrate");
	}
	if (Caralien2) {
		WheelPTFX("scr_rcbarry1", "scr_alien_teleport");
	}
	if (Carelectric) {
		WheelPTFX("scr_agencyheistb", "scr_agency3b_elec_box");
	}
	if (CarLightning) {
		WheelPTFX("scr_rcbarry2", "scr_clown_death");
	}
	if (moneyeffect15) {
		WheelPTFX("scr_reburials", "scr_burial_dirt");
		WheelPTFX("scr_reburials", "scr_burial_dirt");
		WheelPTFX("scr_reburials", "scr_burial_dirt");
	}

}

bool Features::soundYacht = false;
void Features::Yacht(bool toggle) {
	DWORD64 args[3] = { 729971264, Features::Online::selectedPlayer, 1 };
	SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);
}

bool Features::soundOffice = false;
void Features::Office(bool toggle) {
	DWORD64 args[3] = { 729971264, Features::Online::selectedPlayer, 2 };
	SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);
}

bool Features::soundClubhouse = false;
void Features::Clubhouse(bool toggle) {
	DWORD64 args[3] = { 729971264, Features::Online::selectedPlayer, 3 };
	SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);
}

bool Features::soundCompany = false;
void Features::Company(bool toggle) {
	DWORD64 args[3] = { 729971264, Features::Online::selectedPlayer, 6 };
	SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);
}

bool Features::soundTuning = false;
void Features::Tuning(bool toggle) {
	DWORD64 args[3] = { 729971264, Features::Online::selectedPlayer, 7 };
	SCRIPT::eventur(1, args, 4, 1 << Features::Online::selectedPlayer);
}

double DegreeToRadian(double n) {
	return n * 0.017453292519943295;
}
Vector3 addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}
Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}
char* Features::selectShootVeh = "HYDRA";
bool Features::vehGunBool = false;
void Features::vehiclegun(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY(Features::selectShootVeh);
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, 0);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Features::stealthh = false;
void Features::Stealthh(bool toggle) {
	if ((timeGetTime() - Features::TimePD3) > Features::stealthdelay)
	{
		globalHandle(0x410DF0 + 1).As <int>() = 2147483646;
		globalHandle(0x410DF0 + 7).As <int>() = 2147483647;
		globalHandle(0x410DF0 + 6).As <int>() = 0;
		globalHandle(0x410DF0 + 5).As <int>() = 0;
		globalHandle(0x410DF0 + 3).As <int>() = 312105838;
		globalHandle(0x410DF0 + 2).As <int>() = 10000000;
		globalHandle(0x410DF0).As <int>() = 1;

		TimePD3 = timeGetTime();

		int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);

		notifyMap("~r~Bank~w~Transaction Active");
	}
}



bool Features::stealth = false;
void Features::Stealth(bool toggle) {
	if ((timeGetTime() - Features::TimePD3) > Features::stealthdelay)
	{
		Any var0 = 0ul;
		int var3 = 312105838;
		int bankVal = true ? 4 : 1;
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, Menu::Settings::gayStealth, bankVal);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

		TimePD3 = timeGetTime();

		int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);

		notifyMap("~r~Bank~w~Transaction Active");
	}
}

bool Features::Looppedmoney = false;
void Features::MoneyLoopPed(bool toggle)
{
	if ((timeGetTime() - Features::TimePD2) > 5000)
	{
		Ped iPed = PLAYER::PLAYER_PED_ID();
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), FALSE);
		Ped spawnedPed = PED::CREATE_RANDOM_PED(playerPosition.x, playerPosition.y, playerPosition.z + 10);
		ENTITY::SET_ENTITY_VELOCITY(spawnedPed, 0, 0, -20);
		ENTITY::SET_ENTITY_NO_COLLISION_ENTITY(spawnedPed, PLAYER::PLAYER_PED_ID(), FALSE);
		PED::SET_PED_MONEY(spawnedPed, 10000);
		ENTITY::SET_ENTITY_HEALTH(spawnedPed, 0);
		ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&spawnedPed);
		Features::TimePD2 = timeGetTime();

	}

}

bool Features::AsteroidShower = false;
void Features::AsteroidShowerToggle(bool toggle) {
	if (AsteroidShowerToggle)
	{
		Hash ast = GAMEPLAY::GET_HASH_KEY("prop_asteroid_01");
		GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder");
		Vector3 kek = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		if ((timeGetTime() - Features::TimePD3) > 600) // myTimer >> in main >> "myTimer = timeGetTime();" you can also set the delay faster or slower as 600
		{
			if (STREAMING::IS_MODEL_VALID(ast))
			{
				STREAMING::REQUEST_MODEL(ast);
				while (!STREAMING::HAS_MODEL_LOADED(ast)) WAIT(0);
				float ang = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 20.0f) * 3.14159265359f;
				float rad = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 20.0f) * 15.0f;
				float x = kek.x + rad * cos(ang);
				float y = kek.y + rad * sin(ang);
				Object Asteroid = OBJECT::CREATE_OBJECT(ast, x, y, 200.0f, 1, 1, 1);
				ENTITY::SET_ENTITY_COLLISION(Asteroid, 1, 1);
				ENTITY::APPLY_FORCE_TO_ENTITY(Asteroid, 1, 150.0f, 180.0f, 200.0f, 20.0f, 20.0f, 50.0f, 0, 0, 1, 1, 0, 1);
				Features::TimePD3 = timeGetTime();
			}
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(ast);
		}
	}
}

bool Features::freezecamera = false;
void Features::camerafreeze(bool toggle)
{
	Player player = Features::Online::selectedPlayer;

	uint64_t args[4] = { 566035618, player, (-1439349444 + 6942064), 0 };
	SCRIPT::eventur(1, args, 4, 1 << player);
}

bool Features::AirstrikeShower = false;
void Features::AirstrikehowerToggle(bool toggle) {
	Vector3 kek = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	if ((timeGetTime() - Features::TimePD2) > 600)
	{
		float ang = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 10.0f) * 3.14159265359f;
		float rad = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 10.0f) * 15.0f;
		float x = kek.x + rad * cos(ang);
		float y = kek.y + rad * sin(ang);
		Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
		WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
		while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
			WAIT(0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(x, y, 200.0f, x, y, 0, 250, 1, airStrike, PLAYER::PLAYER_PED_ID(), 1, 0, -1.0);


		Features::TimePD2 = timeGetTime();
	}
}



bool Features::Airstrike = false;
void Features::AirstrikeMode(bool toggle) {
	if (AirstrikeMode)
	{
		Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
		Vector3 kek = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		if ((timeGetTime() - Features::TimePD3) > 600) // myTimer >> in main >> "myTimer = timeGetTime();" you can also set the delay faster or slower as 600
		{
			if (STREAMING::IS_MODEL_VALID(airStrike))
			{
				STREAMING::REQUEST_MODEL(airStrike);
				while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike)) WAIT(0);
				float ang = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 20.0f) * 3.14159265359f;
				float rad = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.0f, 20.0f) * 15.0f;
				float x = kek.x + rad * cos(ang);
				float y = kek.y + rad * sin(ang);
				WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
				ENTITY::SET_ENTITY_COLLISION(airStrike, 1, 1);
				ENTITY::APPLY_FORCE_TO_ENTITY(airStrike, 1, 150.0f, 180.0f, 200.0f, 20.0f, 20.0f, 50.0f, 0, 0, 1, 1, 0, 1);
				Features::TimePD3 = timeGetTime();
			}
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(airStrike);
		}
	}
}

////Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
////Ped playerPed = PLAYER::PLAYER_PED_ID();
////Vector3 coords = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
////Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
////WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
////while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
////WAIT(0);
////GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
////			}
//

bool Features::geiletitte = false;
bool Features::gay = false;
void Features::Gay(bool toggle) {
	if ((timeGetTime() - Features::TimePD3) > Features::stealthdelay)
	{
		Any var0 = 0ul;
		int var3 = 312105838;
		int bankVal = false ? 4 : 1;
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, Menu::Settings::gayStealth, bankVal);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

		TimePD3 = timeGetTime();

		int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);

		notifyMap("~r~Wallet~w~Transaction Active");
	}
}

bool Features::Flex = false;
void Features::flex(bool toggle)
{
	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, 0x1F8 }, eFrameFlagExplosiveMelee);

}

bool Features::Aimbot = false;
void Features::aimbot(bool toggle)
{
	if (toggle)
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 4 + 2;

		Entity *peds = new Entity[ArrSize];
		peds[0] = ElementAmount;
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_INDEX(), 1);
		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()), peds, -1);
		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			int bone = ENTITY::GET_ENTITY_BONE_INDEX_BY_NAME(peds[OffsetID], "SKEL_Head");
			Vector3 pos = ENTITY::GET_WORLD_POSITION_OF_ENTITY_BONE(peds[OffsetID], bone);
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()) != peds[OffsetID])
			{
				PED::SET_PED_SHOOTS_AT_COORD(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()), pos.x, pos.y, pos.z, true);
			}
		}

	}
}



bool Features::exi = false;
void Features::exa(bool toggle)
{
	int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
	if (UI::DOES_BLIP_EXIST(WaypointHandle)) {
			Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
			WaypointPos.z += 25.0f;
			FIRE::ADD_EXPLOSION(WaypointPos.x, WaypointPos.y, WaypointPos.z, Features::Explosionfickkkk, 10000.f, Menu::Settings::schwesselfick, Menu::Settings::schwesselfickk, Menu::Settings::camerra);
	}
	
}

bool Features::para = false;
void Features::paranormal(bool toggle)
{
	if (GetAsyncKeyState(VK_NUMPAD9))
	{
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press Num9");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
		UI::_DRAW_NOTIFICATION(FALSE, FALSE);

		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		Vehicle veh[arrSize];
		veh[0] = numElements;
		//setAnimation("rcmpaparazzo_4", "lift_hands_in_air_loop");
		int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
		if (veh != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);
					STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
					GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
					GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
					GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", veh[offsettedID], 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

				}
			}
		}
	}
}

bool Features::NevW = false;
void Features::nevw(bool toggle)
{
	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_INFO_WANTED }, 0);
}

bool Features::Penis = false; 
void Features::penis(bool toggle)
{
	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, 0x1F8 }, eFrameFlagExplosiveAmmo);
}

bool Features::AmoFire = false; 
void Features::amofire(bool toggle)
{
	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, 0x1F8 }, eFrameFlagFireAmmo);
}


float Features::pedsizee = 1.0f;
float Features::pedwithh = 1.0f;
bool Features::Pedscale = false;
void Features::pedscale(bool toggle)
{
	//Features::pedsizee = Memory::get_value<float>({ 0x08, 0x88 });
	Memory::set_value<float>({ 0x08, 0x88 }, Pedscale ? Features::pedsizee : 0.1f);
	Memory::set_value<float>({ 0x08, 0X0064 }, Pedscale ? Features::pedwithh : 0.1f);
}


bool Features::featureVisionDrunk = false;
void Features::featureVisionDrunkUpdated(bool toggle)
{
	BOOL bPlayerExists = ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID());
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (featureVisionDrunkUpdated)
		if (featureVisionDrunk)
		{
			STREAMING::REQUEST_ANIM_SET("move_m@drunk@verydrunk");
			while (!STREAMING::HAS_ANIM_SET_LOADED("move_m@drunk@verydrunk"))
			{
				WAIT(0);
			}
			PED::SET_PED_MOVEMENT_CLIPSET(playerPed, "move_m@drunk@verydrunk", 1.0f);
			CAM::SHAKE_GAMEPLAY_CAM("DRUNK_SHAKE", 1.0f);
		}
		else
		{
			PED::RESET_PED_MOVEMENT_CLIPSET(playerPed, 1.0f);
			CAM::STOP_GAMEPLAY_CAM_SHAKING(true);
		}
	AUDIO::SET_PED_IS_DRUNK(playerPed, featureVisionDrunk);
}


// 	static void CLEAR_PLAYER_WANTED_LEVEL(Player player) { invoke<Void>(0xB302540597885499, player); } // 0xB302540597885499 0x54EA5BCC
//  static void SET_RUN_SPRINT_MULTIPLIER_FOR_PLAYER(Player player, float multiplier) { invoke<Void>(0x6DB47AA77FD94E09, player, multiplier); } // 0x6DB47AA77FD94E09 0x825423C2


//Never Wanted 
bool Features::NeverWantedTest1 = false;
void Features::NeverWantedTest2(bool toggle)
{
	Player PlayerPed = PLAYER::PLAYER_ID();
	PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
	PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PlayerPed);
}





bool Features::controler = false;
bool Features::infammo = false;
bool Features::freezed[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::Freezer(Player target) {
	Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	AI::CLEAR_PED_TASKS_IMMEDIATELY(vic);
	AI::CLEAR_PED_TASKS(vic);
	AI::CLEAR_PED_SECONDARY_TASK(vic);
}

int Features::ExploCh = 1;

void Features::BypassOnlineVehicleKick(Vehicle vehicle)
{
	Player player = PLAYER::PLAYER_ID();
	int var;
	DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
}

bool Features::Stop = false;
void Features::stop(bool toggle)
{
	
	VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);
	

}

bool Features::Freezetime = false;
void Features::freezetime(bool toggle)
{

	TIME::PAUSE_CLOCK(0);

}

bool Features::toBank = false;
void Features::StealthDropintee() {
	if ((timeGetTime() - Features::TimePD3) > 800)
	{
		Any var0 = 0ul;
		int var3 = 312105838;
		int bankVal = 1;

		if (!toBank)
			bankVal = 4;

		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, 10000000, bankVal);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

		Features::TimePD3 = timeGetTime();
	}
}

bool Features::bullshark = false;
void Features::Bullshark()
{
	globalHandle(2524719).At(830).As<int>() = 1;
}


int TimePD77;
int  Features::amount22 = 15000000;
bool Features::toBank22 = false;
void Features::StealthDropintee22() {
	if ((timeGetTime() - TimePD77) > Features::stealthDelay1)
	{
		
		globalHandle(0x410DF0 + 1).As<int>() = 2147483646;
		globalHandle(0x410DF0 + 7).As<int>() = 2147483647;
		globalHandle(0x410DF0 + 6).As<int>() = 0;
		globalHandle(0x410DF0 + 5).As<int>() = 0;
		globalHandle(0x410DF0 + 3).As<int>() = -1586170317;
		globalHandle(0x410DF0 + 2).As<int>() = 15000000;
		globalHandle(0x410DF0).As<int>() = 1;

		

		int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);

		TimePD77 = timeGetTime();

		notifyMap("~w~Add 15 Mil");
	}
}

bool Features::dropme2 = false;
void Features::cashdrop23(bool toggle)
{
	Ped iPed = PLAYER::PLAYER_PED_ID();
	if ((timeGetTime() - Features::TimePD1) > 150)
	{
		STREAMING::REQUEST_MODEL(-1666779307);
		if (!STREAMING::HAS_MODEL_LOADED(-1666779307)) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::CREATE_MONEY_PICKUPS(playerPosition.x, playerPosition.y, playerPosition.z, 2500, 1, -1666779307);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(-1666779307);

			Features::TimePD1 = timeGetTime();

		}
	}//done wait
}






bool Features::magnetbool = false;
void Features::magnetActive(bool toggle) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID());
	Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
	if (vehHash == 0xFCFCB68B || vehHash == 4244420235 || vehHash == -50547061) {
		if (VEHICLE::_DOES_CARGOBOB_HAVE_PICKUP_MAGNET) {
			Vehicle cargobob = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			VEHICLE::_SET_CARGOBOB_PICKUP_MAGNET_ACTIVE(cargobob, magnetbool);
		}
		else {
			notifyBottom("~r~No magnet attached.");
		}
	}
	else {
		notifyBottom("~r~You're not in a Cargobob.");
	}
}
bool Features::toBank9 = false;
void Features::StealthDropintee5() {
	if ((timeGetTime() - Features::TimePD3) > 800)
	{
		Any var0 = 0ul;
		int var3 = 312105838;
		int bankVal = 1;

		if (!toBank)
			bankVal = 4;

		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, 5000000, bankVal);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

		Features::TimePD3 = timeGetTime();
	}
}

decltype(Features::player_alpha) Features::player_alpha = 255;

decltype(Features::Drawmaker) Features::Drawmaker = 0;


decltype(Features::lvl) Features::lvl = 8000;



void Features::autovehi54(Hash toSpawn) {
	Hash model = static_cast<Hash>(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{

		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::erstelle_fahr(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_REGISTER(veh, true);
		BypassOnlineVehicleKick(0);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		if (Features::spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		if (Features::spawnmaxed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{

				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Redhunter");
				AUDIO::SET_VEH_RADIO_STATION(veh, "OFF");
				//GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
				//GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", veh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2.0, false, false, false);

			}
		}
	}
}

void Features::autovehi(char* toSpawn) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{

		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::erstelle_fahr(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, false);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		NETWORK::NETWORK_FADE_IN_ENTITY(veh, 0);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_REGISTER(veh, true);
		BypassOnlineVehicleKick(0);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		if (Features::spawnincar)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}
		if (Features::spawnmaxed)
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{

				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Redhunter");
				AUDIO::SET_VEH_RADIO_STATION(veh, "OFF");
				//GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
				//GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", veh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2.0, false, false, false);

			}
		}
	}
}

int r = 255, g = 0, b = 0;
void RGBFade()
{
	if (r > 0 && b == 0) {
		r--;
		g++;
	}
	if (g > 0 && r == 0) {
		g--;
		b++;
	}
	if (b > 0 && g == 0) {
		r++;
		b--;
	}
}

int Features::stealthDelay4088 = 100;
bool Features::Rneon = false;
void Features::RainbowNeon(bool toggle)
{
	if ((timeGetTime() - Features::TimePD3) > Features::stealthDelay4088)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (RainbowNeon)
		{
			RGBFade();
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
			{
				if (VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 0) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 2) && VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 3))
				{
					VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, b);
				}
				else
				{
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
					VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
					VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, r, g, b);
				}
			}
		}
		Features::TimePD5 = timeGetTime();
	}
}

//int Features::Alphap = 0;
//void Features::alphap(int level) {
//	ENTITY::SET_ENTITY_ALPHA(Features::AlphaP, 0, 0);
//}

int Features::timeerlevel = 0;
void Features::settimechang(int level) {
	NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(Features::timeerlevel, 0, 0);
}

int Features::timeerlevelc = 0;
void Features::settimechangc(int level) {
	GAMEPLAY::SET_RANDOM_SEED(Features::timeerlevelc);
}

int Features::timeerlevelcc = 0;
void Features::settimechangcc(int level) {
	GAMEPLAY::SET_FAKE_WANTED_LEVEL(Features::timeerlevelcc);
}


int Features::playerWantedLevel = 0;
void Features::ChangeWanted(int level) {
	Memory::set_value<int32_t>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, Features::playerWantedLevel - 1 + 1 - 0 + 1 - 1);
}

void Features::autovehi2(char* toSpawn, Vector3 ourCoords) {
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::erstelle_fahr(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, true);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);

		WAIT(150);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}
}

/*
bool Features::expmeel = false;
bool Features::fireammo = false;
bool Features::expammo = false;
*/
/*
void Features::Expmeels(bool toggle) {
GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());
}
void Features::Fireammos(bool toggle) {
GAMEPLAY::SET_FIRE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());
}
void Features::Expammos(bool toggle) {
GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());  /
}*/
bool Features::rbgun = false;
void Features::RBGuner(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	static LPCSTR weaponNames[] = {
		"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
		"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
		"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
		"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
		"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
		"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
		"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
		"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
		"WEAPON_PROXMINE", "WEAPON_SNOWBALL"," WEAPON_BALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
		"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
		"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "WEAPON_ANIMAL", "WEAPON_STICKYBOMB"
	};
	for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
	{
		if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), 0))
		{
			WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), rand() % 8);
		}
	}
}

bool Features::free = false;
void Features::freeCam(bool toggle)
{
	static bool lock;
	static std::int32_t cam;
	static float dist;
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 p_coord = { 0,0,0 };
	int Handle = PLAYER::PLAYER_PED_ID();

	if (!CAM::DOES_CAM_EXIST(cam)) {
		cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
		CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
		CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
	}
	if (!toggle)
	{
		Vector3 camCoords = CAM::GET_CAM_COORD(cam);
		ENTITY::SET_ENTITY_COORDS(Handle, camCoords.x, camCoords.y, camCoords.z, 0, 0, 0, 1);
		CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1);
		CAM::SET_CAM_ACTIVE(cam, 0);
		CAM::DESTROY_CAM(cam, true);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);

	}

	CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1);
	CAM::SET_CAM_ACTIVE(cam, 1);
	CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);

	p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
	PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

	auto speed = .5f;
	if (IsKeyPressed(VK_LSHIFT))
	{
		speed += .3f;
	}

	if (IsKeyPressed(VK_KEY_S))
	{
		speed /= -1;
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}

	if (IsKeyPressed(VK_KEY_W))
	{
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}
	//load2();
}

bool Features::freeT = false;
void Features::freeCamt(bool toggle)
{
	static bool lock;
	static std::int32_t cam;
	static float dist;
	auto rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	auto coord = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 p_coord = { 0,0,0 };
	int Handle = PLAYER::PLAYER_PED_ID();

	if (!CAM::DOES_CAM_EXIST(cam)) {
		cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
		CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);
		CAM::SET_CAM_COORD(cam, coord.x, coord.y, coord.z);
	}
	if (!toggle)
	{
		Vector3 camCoords = CAM::GET_CAM_COORD(cam);
		ENTITY::SET_ENTITY_COORDS(Handle, camCoords.x, camCoords.y, camCoords.z, 0, 0, 0, 1);
		CAM::RENDER_SCRIPT_CAMS(false, true, 700, 1, 1);
		CAM::SET_CAM_ACTIVE(cam, 0);
		CAM::DESTROY_CAM(cam, true);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);

	}

	notifyBottom("~r~Choose a point and disable");


	CAM::RENDER_SCRIPT_CAMS(true, true, 700, 1, 1);
	CAM::SET_CAM_ACTIVE(cam, 1);
	CAM::SET_CAM_ROT(cam, rot.x, rot.y, rot.z, 0);

	p_coord = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(PLAYER::PLAYER_PED_ID(), p_coord.x, p_coord.y, p_coord.z, 0, 0, 0);
	PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
	UI::HIDE_HUD_AND_RADAR_THIS_FRAME();

	auto speed = .5f;
	if (IsKeyPressed(VK_LSHIFT))
	{
		speed += .3f;
	}

	if (IsKeyPressed(VK_KEY_S))
	{
		speed /= -1;
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}

	if (IsKeyPressed(VK_KEY_W))
	{
		auto c = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&rot), speed));
		CAM::SET_CAM_COORD(cam, c.x, c.y, c.z);
	}
	//load2();
}


bool Features::cstrcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}

void Features::TPtoWaypoint()
{
	int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
	if (UI::DOES_BLIP_EXIST(WaypointHandle))
	{
		Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
		WaypointPos.z += 25.0f;
		int Handle = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
			Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z, 0, 0, 0, 1);
	}
}

bool Features::delgun = false;
void Features::DelGun(bool toggle) {

	Entity del_entity;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &del_entity))

		if (ENTITY::DOES_ENTITY_EXIST(del_entity) && NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(del_entity))
		{
			Vector3 tmp = ENTITY::GET_ENTITY_COORDS(del_entity, 1);
			ENTITY::DETACH_ENTITY(del_entity, 1, 1);
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(del_entity, 0, 0, 0, 0, 0, 0);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(del_entity, 0, 1);
			ENTITY::DELETE_ENTITY(&del_entity);
		}
}

//Fast Swim 
bool Features::fastswim = false;
void Features::SwimFast(bool toggle)
{
	if (!fastswim)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_SWIM_SPD }, Menu::Settings::run);
	}

}

bool Features::Weapontest = false;
void Features::weapontest(bool toggle)
{
	if (Weapontest)
	{
		if (IsPedShooting(PLAYER::PLAYER_PED_ID()))
		{
			Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 Dir = rot_to_direction(&Rot);
			Vector3 CPosition = CAM::GET_GAMEPLAY_CAM_COORD();
			Vector3 PlayerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			float spawnDistance = get_distance(&CPosition, &PlayerPosition);
			spawnDistance += 2;
			Vector3 SPosition = add(&CPosition, &multiply(&Dir, spawnDistance));
			DWORD Model = $("prop_asteroid_01");
			Object ObJect = OBJECT::CREATE_OBJECT(Model, SPosition.x, SPosition.y, SPosition.z, 1, 1, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
			if (ENTITY::DOES_ENTITY_EXIST(ObJect))
			{
				ENTITY::SET_ENTITY_RECORDS_COLLISIONS(ObJect, true);
				for (float f = 0.0f; f < 75.0f; f++) {
					if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(ObJect))break;
					ENTITY::APPLY_FORCE_TO_ENTITY(ObJect, 1, Dir.x*10.0f, Dir.y*10.0f, Dir.z*10.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
					WAIT(0);
				}
				Vector3 Coordinates = ENTITY::GET_ENTITY_COORDS(ObJect, 1);
				FIRE::ADD_EXPLOSION(Coordinates.x, Coordinates.y, Coordinates.z, 9, 25.0f, 1, 1, 0.5f);
			}
		}
	}
}



//Fast Run
bool Features::runfast = false;
void Features::RunFast(bool toggle)
{
	if (!runfast)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, Menu::Settings::run);
	}

}

bool Features::runfast1 = false;
void Features::RunFast1(bool toggle)
{
	if (!runfast)
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 1);
	}
	else
	{
		Memory::set_value<float>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , OFFSET_PLAYER_INFO_RUN_SPD }, 4.5);
	}
}

//bool Features::randommon = false;
//void Features::randommonnn(bool toggle) {
//	if ((timeGetTime() - Features::TimePD3) > Features::stealthDelay1)
//	{
//		Any var0 = 0ul;
//		int var3 = 312105838;
//		int bankVal = 4;
//		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(15466, 10000000), bankVal);
//		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);
//
//		Features::TimePD3 = timeGetTime();
//	}
//}

bool Features::rainbowmenu = true;
void Features::Rainbowmenu(bool toggle)
{
	if ((timeGetTime() - Features::TimePD2) > 600)
	{
		if (Menu::Settings::arrowww.r > 0 && Menu::Settings::arrowww.b == 0, Menu::Settings::arrow2.r > 0 && Menu::Settings::arrow2.b == 0)
		{
			Menu::Settings::arrowww.r--;
			Menu::Settings::arrowww.g++;
			Menu::Settings::arrow2.r--;
			Menu::Settings::arrow2.g++;
		}
		if (Menu::Settings::arrowww.g > 0 && Menu::Settings::arrowww.r == 0, Menu::Settings::arrow2.g > 0 && Menu::Settings::arrow2.r == 0)
		{
			Menu::Settings::arrowww.g--;
			Menu::Settings::arrowww.b++;
			Menu::Settings::arrow2.g--;
			Menu::Settings::arrow2.b++;
		}
		if (Menu::Settings::arrowww.b > 0 && Menu::Settings::arrowww.g == 0, Menu::Settings::arrow2.b > 0 && Menu::Settings::arrow2.g == 0)
		{
			Menu::Settings::arrowww.r++;
			Menu::Settings::arrowww.b--;
			Menu::Settings::arrow2.r++;
			Menu::Settings::arrow2.b--;
		}

		if (Menu::Settings::arrow2.r > 0 && Menu::Settings::arrow2.b == 0, Menu::Settings::arrowww.r > 0 && Menu::Settings::arrowww.b == 0)
		{
			Menu::Settings::arrowww.r--;
			Menu::Settings::arrowww.g++;
			Menu::Settings::arrow2.r--;
			Menu::Settings::arrow2.g++;
		}
		if (Menu::Settings::arrow2.g > 0 && Menu::Settings::arrow2.r == 0, Menu::Settings::arrowww.g > 0 && Menu::Settings::arrowww.r == 0)
		{
			Menu::Settings::arrowww.g--;
			Menu::Settings::arrowww.b++;
			Menu::Settings::arrow2.g--;
			Menu::Settings::arrow2.b++;
		}
		if (Menu::Settings::arrow2.b > 0 && Menu::Settings::arrow2.g == 0, Menu::Settings::arrowww.b > 0 && Menu::Settings::arrowww.g == 0)
		{
			Menu::Settings::arrowww.r++;
			Menu::Settings::arrowww.b--;
			Menu::Settings::arrow2.r++;
			Menu::Settings::arrow2.b--;
		}
		
		(Menu::Settings::arrowww.r, Menu::Settings::arrowww.g, Menu::Settings::arrowww.b);
		(Menu::Settings::arrow2.r, Menu::Settings::arrow2.g, Menu::Settings::arrow2.b);

	}
}

/*void pushEnt(Entity entity, float x, float y, float z)
{
ENTITY::APPLY_FORCE_TO_ENTITY(entity, 1, x, y, z, 0.0f, 0.0f, 0.0f, 0, TRUE, TRUE, TRUE, FALSE, TRUE);
}

bool Features::runfast = false;
void Features::RunFast(bool toggle)
{
Ped playerPed = PLAYER::PLAYER_PED_ID();
if (AI::IS_PED_RUNNING(playerPed) || AI::IS_PED_SPRINTING(playerPed) && !PED::IS_PED_RUNNING_RAGDOLL_TASK(playerPed))
{
pushEnt(playerPed, 0.0f, 1.0f, 0.0f);
}

}*/


bool Features::stickToGround = false;
void Features::vehStuckToGround() {
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
}

bool Features::osk = false;
void Features::OSKR(bool toggle)
{
	if (!osk) {
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 1.f);
	}
	else {
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_WEAPON_MANAGER, OFFSET_WEAPON_CURRENT, OFFSET_WEAPON_BULLET_DMG }, 10000.0f);
	}
}
bool Features::superman = false;
void Features::Superman(bool toggle)
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 0, 0, 10, 0, 0, 0, 1, true, true, true, true, true);
	}
	Hash hash = GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE");
	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
	/*GodMode(PLAYER::PLAYER_ID());
	NoRagdoll;*/

	notifyBottom("~g~press Space, W, A, D, S...");

	if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
	{
		if (GetAsyncKeyState(0x57)) // W key
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 0, 0);
		}

		if (GetAsyncKeyState(0x53)) // S key
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 6, 0);
		}
		if (GetAsyncKeyState(VK_SHIFT))
		{
			ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 6, 0, 0);
		}
	}

}



bool Features::UltraJ = false;
void Features::UltraJumpp(bool toggle)
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	if (UltraJ)
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(playerPed);
}


bool Features::SlowMotion = false;
void Features::slowMotion(bool toggle) {
	if (toggle == true)
	{
		GAMEPLAY::SET_TIME_SCALE(1.f), (PLAYER::PLAYER_PED_ID(), true);
	}
	else {
		GAMEPLAY::SET_TIME_SCALE(0.6f), (PLAYER::PLAYER_PED_ID(), true);
	}

}

bool Features::PoloDance = false;
void Features::polodance(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Ped *peds = new Ped[ArrSize];
	peds[0] = ElementAmount;
	int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
	for (int i = 0; i < PedFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(peds[OffsetID]);
		if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
		{
			STREAMING::REQUEST_ANIM_DICT("mini@strip_club@pole_dance@pole_dance1");
			if (STREAMING::HAS_ANIM_DICT_LOADED(("mini@strip_club@pole_dance@pole_dance1")))
			{
				AI::TASK_PLAY_ANIM((peds[OffsetID]), "mini@strip_club@pole_dance@pole_dance1", "pd_dance_01", 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
		}
	}
}

bool Features::explodenearbytiresbool = false;
void Features::explodenearbytires(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehs[OffsetID], TRUE);
			for (int i = 8; i--;) {
				VEHICLE::SET_VEHICLE_TYRE_BURST(vehs[OffsetID], i, TRUE, 1000.f);
			}
		}
	}

}

bool Features::NeverWanted = false;
void Features::neverWanted(bool toggle) {

	Memory::set_value<int32_t>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, -1 + 1 - 0 + 1 - 1);


}


bool Features::PlayerArmor = false;
void Features::armor(bool toggle) {

	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_PLAYER_ARMOR }, 1);

}
//bool Features::playerGodMode = false;
//void Features::GodMode(bool toggle) {
//
//	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_ENTITY_GOD }, 1);
//
//
//
//}
bool Features::playerGodMode = false;
void Features::GodMode(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	int isEnabled = toggle ? 1 : 0;

	Memory::set_value<int>({ OFFSET_PLAYER, OFFSET_ENTITY_GOD }, isEnabled);
	ENTITY::SET_ENTITY_PROOFS(playerPed, toggle, toggle, toggle, toggle, toggle, toggle, toggle, toggle);
	/*PED::SET_PED_CAN_RAGDOLL(playerPed, !toggle);
	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, !toggle);*/
}
bool Features::playertenkped = false;
int Features::TimePD;
int Features::TimePD1;
int Features::TimePD2;
int Features::TimePD3;
int Features::TimePD4;
int Features::TimePD5;
int Features::TimePD6;
int Features::TimePD7;
int Features::TimePD8;
int Features::TimePD9;
int Features::TimePD10;
int Features::TimePD11;
int Features::TimePD12;
int Features::TimePD13;
int Features::TimePD14;
void Features::TenKPedMoney(bool toggle)
{
	Features::TimePD = timeGetTime();
	if ((timeGetTime() - Features::TimePD) > 1000) {
		Player playerPed = PLAYER::PLAYER_PED_ID();
		int TenK = 10000;
		Ped ClonedPedMoney = PED::CLONE_PED(playerPed, ENTITY::GET_ENTITY_HEADING(playerPed), 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(ClonedPedMoney, false, false);
		PED::SET_PED_MONEY(ClonedPedMoney, TenK);
		ENTITY::SET_ENTITY_HEALTH(ClonedPedMoney, 0);
		PED::DELETE_PED(&ClonedPedMoney);
		Features::TimePD = timeGetTime();
	}
}
bool Features::playerfireloop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::FireLoop(Player target)
{
	Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 12, 5, true, 0, 0);
}
bool Features::playerwaterloop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::WaterLoop(Player target)
{
	Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 13, 5, true, 0, 0);
}
bool Features::playerinvisibility = false;
void Features::MoniLoop(bool toggle)
{
}
void Features::Invisibility(bool toggle)
{
	if (toggle == true)
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, false);
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
	}
}

void Features::riskyOptins(bool toggle)
{
	notifyBottom("~r~Open Network Options *...");

	WAIT(0);
}

void Features::riskyOptins1(bool toggle)
{
	WAIT(0);
}

void Features::riskymode(bool toggle)
{
	WAIT(0);
}

void Features::hidename(bool toggle)
{
	WAIT(0);
}

//void Features::banprotex(bool toggle)
//{
//	WAIT(0);
//}

void Features::ptx(bool toggle)
{
	WAIT(0);
}

//void Features::kickfk(bool toggle)
//{
//	WAIT(0);
//}

void Features::ep(bool toggle)
{
	WAIT(0);
}

//void Features::cdp(bool toggle)
//{
//	WAIT(0);
//}

void Features::aop(bool toggle)
{
	WAIT(0);
}

void Features::celo(bool toggle)
{
	WAIT(0);
}


//bool Features::playernoragdoll = false;
//void Features::NoRagdoll(bool toggle)
//{
//	Memory::set_value<DWORD>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, OFFSET_PLAYER_RAGDOLL }, toggle ? 0x20 : 0x01);
//	PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER::PLAYER_PED_ID(), !toggle);
//	PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), !toggle);
//	PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), !toggle);
//}

bool Features::savenewdrop222[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::cashdrop222(Player target)
{

	if ((timeGetTime() - Features::TimePD2) > 500) // Time between drops
	{


		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"))) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f / 10, 0, 1999, GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"), FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		}

		Features::TimePD2 = timeGetTime();

	}
}

bool Features::particlee1 = false;
void Features::ParticlEE1(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_clown_appears", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::particlee = false;
void Features::ParticllE(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_fbi4");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_fbi4");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_fbi4_trucks_crash", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::particle3 = false;
void Features::ParticlE3(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry1");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry1");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_alien_teleport", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::particle4 = false; 
void Features::ParticlE4(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_martin1");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_martin1");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_sol1_sniper_impact", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::particle5 = false; 
void Features::ParticlE5(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_ornate_heist");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_ornate_heist");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_heist_ornate_banknotes", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::particle6 = false;
void Features::ParticlE6(bool toggle) 
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_finalec2");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_finalec2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_finale2_blood_entry", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::particle7 = false;
void Features::ParticlE7(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("proj_xmas_firework");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_firework_xmas_burst_rgw", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::isSlideRun = false;
void Features::slideRun(bool toggle)
{
	Ped ped = PLAYER::PLAYER_PED_ID();

	if (AI::IS_PED_RUNNING(ped) || AI::IS_PED_SPRINTING(ped))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0.f, 1.5f, 0.f, 0.f, 0.f, 0.f, 1, true, true, true, false, true);
	}
}

std::string get_ingame_keyboard_result()
{
	std::string    r = "!!INVALID!!";
	if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD())
	{
		char* pCh = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		if (pCh != nullptr)
			r = pCh;
	}
	return r;
}
void Features::setplayername(std::string& name)
{
	size_t newLen = name.size() + 1;
	if (newLen <= 1 || newLen > 20)
		return;
	char    buffer[0x20] = {};
	char*    pSearch = (char*)Hooking::m_onlineName + 0x5C;
	size_t    curLen = strlen(pSearch) + 1;
	strncpy_s(buffer, pSearch, curLen);
	for (uint32_t i = 0, found = 0, match = 0; found < 4; ++pSearch)
	{
		if (*pSearch != buffer[i])
			goto LABEL_RESET;
		if (++match < curLen)
		{
			++i;
			continue;
		}
		strncpy_s(pSearch - i, newLen, &name[0], newLen);
		++found;
	LABEL_RESET:
		i = match = 0;
	}
	strncpy(Hooking::get_player_name(PLAYER::PLAYER_ID()), &name[0], newLen);
}
void Features::NameChanger()
{
	CharKeyboard2("~b~", 21, "~bd~");
	std::string str = get_ingame_keyboard_result();
	if (str != "!!INVALID!!" && str != "")
	{
		setplayername(str);
	}
}

char* Features::setPlayerName(int player, char* tag) {
	ostringstream playerOption;
	playerOption << Hooking::get_player_name(player) << tag;
	return (char*)playerOption.str().c_str();
}
bool Features::particle8 = false;
void Features::ParticlE8(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed)) {
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_fbi5a");
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_fbi5a");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_AT_COORD("scr_fbi5_ped_water_splash", coords.x, coords.y, coords.z, 0.f, 0.f, 0.f, 1.f, 0, 0, 0);
		}
	}
}

bool Features::playersuperjump = false;
void Features::SuperJump(bool toggle)
{
	Memory::set_value<int>({ OFFSET_PLAYER , OFFSET_PLAYER_INFO , 0x1F8 }, eFrameFlagSuperJump);

}

bool Features::extremejump = false;
void Features::Extremejump(bool toggle) {
	if (Extremejump)
	{
		int Me = PLAYER::PLAYER_PED_ID();
		if (GetAsyncKeyState(VK_SPACE))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, 0, +3, 0, 0, 0, 1, 1, 1, 1, 0, 1);
		}
	}

	notifyMap("~w~Press Space");
}


int Features::Online::selectedPlayer = 0;
void Features::Online::TeleportToPlayer(Player player) {

	Entity handle;
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
	PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : handle = PLAYER::PLAYER_PED_ID();
	ENTITY::SET_ENTITY_COORDS(handle, coords.x, coords.y, coords.z, false, false, false, false);
}

void Features::SetRank(int rpvalue)
{
	if (rpvalue < 0 && rpvalue > 8000)
	{
		rpvalue = 8000;
	}
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Features::Levels[rpvalue], 0);
	STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_CHAR_XP_FM"), Features::Levels[rpvalue], 0);

}

int Features::Levels[8000] = { 0, 800, 2100, 3800, 6100, 9500, 12500, 16000, 19800, 24000, 28500, 33400, 38700, 44200, 50200, 56400, 63000, 69900, 77100, 84700, 92500, 100700, 109200, 118000, 127100, 136500, 146200,
156200, 166500, 177100, 188000, 199200, 210700, 222400, 234500, 246800, 259400, 272300, 285500, 299000, 312700, 326800, 341000, 355600, 370500, 385600, 401000, 416600, 432600, 448800, 465200, 482000, 499000,
516300, 533800, 551600, 569600, 588000, 606500, 625400, 644500, 663800, 683400, 703300, 723400, 743800, 764500, 785400, 806500, 827900, 849600, 871500, 893600, 916000, 938700, 961600, 984700, 1008100, 1031800,
1055700, 1079800, 1104200, 1128800, 1153700, 1178800, 1204200, 1229800, 1255600, 1281700, 1308100, 1334600, 1361400, 1388500, 1415800, 1443300, 1471100, 1499100, 1527300, 1555800, 1584350, 1612950, 1641600,
1670300, 1699050, 1727850, 1756700, 1785600, 1814550, 1843550, 1872600, 1901700, 1930850, 1960050, 1989300, 2018600, 2047950, 2077350, 2106800, 2136300, 2165850, 2195450, 2225100, 2254800, 2284550, 2314350,
2344200, 2374100, 2404050, 2434050, 2464100, 2494200, 2524350, 2554550, 2584800, 2615100, 2645450, 2675850, 2706300, 2736800, 2767350, 2797950, 2828600, 2859300, 2890050, 2920850, 2951700, 2982600, 3013550,
3044550, 3075600, 3106700, 3137850, 3169050, 3200300, 3231600, 3262950, 3294350, 3325800, 3357300, 3388850, 3420450, 3452100, 3483800, 3515550, 3547350, 3579200, 3611100, 3643050, 3675050, 3707100, 3739200,
3771350, 3803550, 3835800, 3868100, 3900450, 3932850, 3965300, 3997800, 4030350, 4062950, 4095600, 4128300, 4161050, 4193850, 4226700, 4259600, 4292550, 4325550, 4358600, 4391700, 4424850, 4458050, 4491300,
4524600, 4557950, 4591350, 4624800, 4658300, 4691850, 4725450, 4759100, 4792800, 4826550, 4860350, 4894200, 4928100, 4962050, 4996050, 5030100, 5064200, 5098350, 5132550, 5166800, 5201100, 5235450, 5269850,
5304300, 5338800, 5373350, 5407950, 5442600, 5477300, 5512050, 5546850, 5581700, 5616600, 5651550, 5686550, 5721600, 5756700, 5791850, 5827050, 5862300, 5897600, 5932950, 5968350, 6003800, 6039300, 6074850,
6110450, 6146100, 6181800, 6217550, 6253350, 6289200, 6325100, 6361050, 6397050, 6433100, 6469200, 6505350, 6541550, 6577800, 6614100, 6650450, 6686850, 6723300, 6759800, 6796350, 6832950, 6869600, 6906300,
6943050, 6979850, 7016700, 7053600, 7090550, 7127550, 7164600, 7201700, 7238850, 7276050, 7313300, 7350600, 7387950, 7425350, 7462800, 7500300, 7537850, 7575450, 7613100, 7650800, 7688550, 7726350, 7764200,
7802100, 7840050, 7878050, 7916100, 7954200, 7992350, 8030550, 8068800, 8107100, 8145450, 8183850, 8222300, 8260800, 8299350, 8337950, 8376600, 8415300, 8454050, 8492850, 8531700, 8570600, 8609550, 8648550,
8687600, 8726700, 8765850, 8805050, 8844300, 8883600, 8922950, 8962350, 9001800, 9041300, 9080850, 9120450, 9160100, 9199800, 9239550, 9279350, 9319200, 9359100, 9399050, 9439050, 9479100, 9519200, 9559350,
9599550, 9639800, 9680100, 9720450, 9760850, 9801300, 9841800, 9882350, 9922950, 9963600, 10004300, 10045050, 10085850, 10126700, 10167600, 10208550, 10249550, 10290600, 10331700, 10372850, 10414050, 10455300,
10496600, 10537950, 10579350, 10620800, 10662300, 10703850, 10745450, 10787100, 10828800, 10870550, 10912350, 10954200, 10996100, 11038050, 11080050, 11122100, 11164200, 11206350, 11248550, 11290800, 11333100,
11375450, 11417850, 11460300, 11502800, 11545350, 11587950, 11630600, 11673300, 11716050, 11758850, 11801700, 11844600, 11887550, 11930550, 11973600, 12016700, 12059850, 12103050, 12146300, 12189600, 12232950,
12276350, 12319800, 12363300, 12406850, 12450450, 12494100, 12537800, 12581550, 12625350, 12669200, 12713100, 12757050, 12801050, 12845100, 12889200, 12933350, 12977550, 13021800, 13066100, 13110450, 13154850,
13199300, 13243800, 13288350, 13332950, 13377600, 13422300, 13467050, 13511850, 13556700, 13601600, 13646550, 13691550, 13736600, 13781700, 13826850, 13872050, 13917300, 13962600, 14007950, 14053350, 14098800,
14144300, 14189850, 14235450, 14281100, 14326800, 14372550, 14418350, 14464200, 14510100, 14556050, 14602050, 14648100, 14694200, 14740350, 14786550, 14832800, 14879100, 14925450, 14971850, 15018300, 15064800,
15111350, 15157950, 15204600, 15251300, 15298050, 15344850, 15391700, 15438600, 15485550, 15532550, 15579600, 15626700, 15673850, 15721050, 15768300, 15815600, 15862950, 15910350, 15957800, 16005300, 16052850,
16100450, 16148100, 16195800, 16243550, 16291350, 16339200, 16387100, 16435050, 16483050, 16531100, 16579200, 16627350, 16675550, 16723800, 16772100, 16820450, 16868850, 16917300, 16965800, 17014350, 17062950,
17111600, 17160300, 17209050, 17257850, 17306700, 17355600, 17404550, 17453550, 17502600, 17551700, 17600850, 17650050, 17699300, 17748600, 17797950, 17847350, 17896800, 17946300, 17995850, 18045450, 18095100,
18144800, 18194550, 18244350, 18294200, 18344100, 18394050, 18444050, 18494100, 18544200, 18594350, 18644550, 18694800, 18745100, 18795450, 18845850, 18896300, 18946800, 18997350, 19047950, 19098600, 19149300,
19200050, 19250850, 19301700, 19352600, 19403550, 19454550, 19505600, 19556700, 19607850, 19659050, 19710300, 19761600, 19812950, 19864350, 19915800, 19967300, 20018850, 20070450, 20122100, 20173800, 20225550,
20277350, 20329200, 20381100, 20433050, 20485050, 20537100, 20589200, 20641350, 20693550, 20745800, 20798100, 20850450, 20902850, 20955300, 21007800, 21060350, 21112950, 21165600, 21218300, 21271050, 21323850,
21376700, 21429600, 21482550, 21535550, 21588600, 21641700, 21694850, 21748050, 21801300, 21854600, 21907950, 21961350, 22014800, 22068300, 22121850, 22175450, 22229100, 22282800, 22336550, 22390350, 22444200,
22498100, 22552050, 22606050, 22660100, 22714200, 22768350, 22822550, 22876800, 22931100, 22985450, 23039850, 23094300, 23148800, 23203350, 23257950, 23312600, 23367300, 23422050, 23476850, 23531700, 23586600,
23641550, 23696550, 23751600, 23806700, 23861850, 23917050, 23972300, 24027600, 24082950, 24138350, 24193800, 24249300, 24304850, 24360450, 24416100, 24471800, 24527550, 24583350, 24639200, 24695100, 24751050,
24807050, 24863100, 24919200, 24975350, 25031550, 25087800, 25144100, 25200450, 25256850, 25313300, 25369800, 25426350, 25482950, 25539600, 25596300, 25653050, 25709850, 25766700, 25823600, 25880550, 25937550,
25994600, 26051700, 26108850, 26166050, 26223300, 26280600, 26337950, 26395350, 26452800, 26510300, 26567850, 26625450, 26683100, 26740800, 26798550, 26856350, 26914200, 26972100, 27030050, 27088050, 27146100,
27204200, 27262350, 27320550, 27378800, 27437100, 27495450, 27553850, 27612300, 27670800, 27729350, 27787950, 27846600, 27905300, 27964050, 28022850, 28081700, 28140600, 28199550, 28258550, 28317600, 28376700,
28435850, 28495050, 28554300, 28613600, 28672950, 28732350, 28791800, 28851300, 28910850, 28970450, 29030100, 29089800, 29149550, 29209350, 29269200, 29329100, 29389050, 29449050, 29509100, 29569200, 29629350,
29689550, 29749800, 29810100, 29870450, 29930850, 29991300, 30051800, 30112350, 30172950, 30233600, 30294300, 30355050, 30415850, 30476700, 30537600, 30598550, 30659550, 30720600, 30781700, 30842850, 30904050,
30965300, 31026600, 31087950, 31149350, 31210800, 31272300, 31333850, 31395450, 31457100, 31518800, 31580550, 31642350, 31704200, 31766100, 31828050, 31890050, 31952100, 32014200, 32076350, 32138550, 32200800,
32263100, 32325450, 32387850, 32450300, 32512800, 32575350, 32637950, 32700600, 32763300, 32826050, 32888850, 32951700, 33014600, 33077550, 33140550, 33203600, 33266700, 33329850, 33393050, 33456300, 33519600,
33582950, 33646350, 33709800, 33773300, 33836850, 33900450, 33964100, 34027800, 34091550, 34155350, 34219200, 34283100, 34347050, 34411050, 34475100, 34539200, 34603350, 34667550, 34731800, 34796100, 34860450,
34924850, 34989300, 35053800, 35118350, 35182950, 35247600, 35312300, 35377050, 35441850, 35506700, 35571600, 35636550, 35701550, 35766600, 35831700, 35896850, 35962050, 36027300, 36092600, 36157950, 36223350,
36288800, 36354300, 36419850, 36485450, 36551100, 36616800, 36682550, 36748350, 36814200, 36880100, 36946050, 37012050, 37078100, 37144200, 37210350, 37276550, 37342800, 37409100, 37475450, 37541850, 37608300,
37674800, 37741350, 37807950, 37874600, 37941300, 38008050, 38074850, 38141700, 38208600, 38275550, 38342550, 38409600, 38476700, 38543850, 38611050, 38678300, 38745600, 38812950, 38880350, 38947800, 39015300,
39082850, 39150450, 39218100, 39285800, 39353550, 39421350, 39489200, 39557100, 39625050, 39693050, 39761100, 39829200, 39897350, 39965550, 40033800, 40102100, 40170450, 40238850, 40307300, 40375800, 40444350,
40512950, 40581600, 40650300, 40719050, 40787850, 40856700, 40925600, 40994550, 41063550, 41132600, 41201700, 41270850, 41340050, 41409300, 41478600, 41547950, 41617350, 41686800, 41756300, 41825850, 41895450,
41965100, 42034800, 42104550, 42174350, 42244200, 42314100, 42384050, 42454050, 42524100, 42594200, 42664350, 42734550, 42804800, 42875100, 42945450, 43015850, 43086300, 43156800, 43227350, 43297950, 43368600,
43439300, 43510050, 43580850, 43651700, 43722600, 43793550, 43864550, 43935600, 44006700, 44077850, 44149050, 44220300, 44291600, 44362950, 44434350, 44505800, 44577300, 44648850, 44720450, 44792100, 44863800,
44935550, 45007350, 45079200, 45151100, 45223050, 45295050, 45367100, 45439200, 45511350, 45583550, 45655800, 45728100, 45800450, 45872850, 45945300, 46017800, 46090350, 46162950, 46235600, 46308300, 46381050,
46453850, 46526700, 46599600, 46672550, 46745550, 46818600, 46891700, 46964850, 47038050, 47111300, 47184600, 47257950, 47331350, 47404800, 47478300, 47551850, 47625450, 47699100, 47772800, 47846550, 47920350,
47994200, 48068100, 48142050, 48216050, 48290100, 48364200, 48438350, 48512550, 48586800, 48661100, 48735450, 48809850, 48884300, 48958800, 49033350, 49107950, 49182600, 49257300, 49332050, 49406850, 49481700,
49556600, 49631550, 49706550, 49781600, 49856700, 49931850, 50007050, 50082300, 50157600, 50232950, 50308350, 50383800, 50459300, 50534850, 50610450, 50686100, 50761800, 50837550, 50913350, 50989200, 51065100,
51141050, 51217050, 51293100, 51369200, 51445350, 51521550, 51597800, 51674100, 51750450, 51826850, 51903300, 51979800, 52056350, 52132950, 52209600, 52286300, 52363050, 52439850, 52516700, 52593600, 52670550,
52747550, 52824600, 52901700, 52978850, 53056050, 53133300, 53210600, 53287950, 53365350, 53442800, 53520300, 53597850, 53675450, 53753100, 53830800, 53908550, 53986350, 54064200, 54142100, 54220050, 54298050,
54376100, 54454200, 54532350, 54610550, 54688800, 54767100, 54845450, 54923850, 55002300, 55080800, 55159350, 55237950, 55316600, 55395300, 55474050, 55552850, 55631700, 55710600, 55789550, 55868550, 55947600,
56026700, 56105850, 56185050, 56264300, 56343600, 56422950, 56502350, 56581800, 56661300, 56740850, 56820450, 56900100, 56979800, 57059550, 57139350, 57219200, 57299100, 57379050, 57459050, 57539100, 57619200,
57699350, 57779550, 57859800, 57940100, 58020450, 58100850, 58181300, 58261800, 58342350, 58422950, 58503600, 58584300, 58665050, 58745850, 58826700, 58907600, 58988550, 59069550, 59150600, 59231700, 59312850,
59394050, 59475300, 59556600, 59637950, 59719350, 59800800, 59882300, 59963850, 60045450, 60127100, 60208800, 60290550, 60372350, 60454200, 60536100, 60618050, 60700050, 60782100, 60864200, 60946350, 61028550,
61110800, 61193100, 61275450, 61357850, 61440300, 61522800, 61605350, 61687950, 61770600, 61853300, 61936050, 62018850, 62101700, 62184600, 62267550, 62350550, 62433600, 62516700, 62599850, 62683050, 62766300,
62849600, 62932950, 63016350, 63099800, 63183300, 63266850, 63350450, 63434100, 63517800, 63601550, 63685350, 63769200, 63853100, 63937050, 64021050, 64105100, 64189200, 64273350, 64357550, 64441800, 64526100,
64610450, 64694850, 64779300, 64863800, 64948350, 65032950, 65117600, 65202300, 65287050, 65371850, 65456700, 65541600, 65626550, 65711550, 65796600, 65881700, 65966850, 66052050, 66137300, 66222600, 66307950,
66393350, 66478800, 66564300, 66649850, 66735450, 66821100, 66906800, 66992550, 67078350, 67164200, 67250100, 67336050, 67422050, 67508100, 67594200, 67680350, 67766550, 67852800, 67939100, 68025450, 68111850,
68198300, 68284800, 68371350, 68457950, 68544600, 68631300, 68718050, 68804850, 68891700, 68978600, 69065550, 69152550, 69239600, 69326700, 69413850, 69501050, 69588300, 69675600, 69762950, 69850350, 69937800,
70025300, 70112850, 70200450, 70288100, 70375800, 70463550, 70551350, 70639200, 70727100, 70815050, 70903050, 70991100, 71079200, 71167350, 71255550, 71343800, 71432100, 71520450, 71608850, 71697300, 71785800,
71874350, 71962950, 72051600, 72140300, 72229050, 72317850, 72406700, 72495600, 72584550, 72673550, 72762600, 72851700, 72940850, 73030050, 73119300, 73208600, 73297950, 73387350, 73476800, 73566300, 73655850,
73745450, 73835100, 73924800, 74014550, 74104350, 74194200, 74284100, 74374050, 74464050, 74554100, 74644200, 74734350, 74824550, 74914800, 75005100, 75095450, 75185850, 75276300, 75366800, 75457350, 75547950,
75638600, 75729300, 75820050, 75910850, 76001700, 76092600, 76183550, 76274550, 76365600, 76456700, 76547850, 76639050, 76730300, 76821600, 76912950, 77004350, 77095800, 77187300, 77278850, 77370450, 77462100,
77553800, 77645550, 77737350, 77829200, 77921100, 78013050, 78105050, 78197100, 78289200, 78381350, 78473550, 78565800, 78658100, 78750450, 78842850, 78935300, 79027800, 79120350, 79212950, 79305600, 79398300,
79491050, 79583850, 79676700, 79769600, 79862550, 79955550, 80048600, 80141700, 80234850, 80328050, 80421300, 80514600, 80607950, 80701350, 80794800, 80888300, 80981850, 81075450, 81169100, 81262800, 81356550,
81450350, 81544200, 81638100, 81732050, 81826050, 81920100, 82014200, 82108350, 82202550, 82296800, 82391100, 82485450, 82579850, 82674300, 82768800, 82863350, 82957950, 83052600, 83147300, 83242050, 83336850,
83431700, 83526600, 83621550, 83716550, 83811600, 83906700, 84001850, 84097050, 84192300, 84287600, 84382950, 84478350, 84573800, 84669300, 84764850, 84860450, 84956100, 85051800, 85147550, 85243350, 85339200,
85435100, 85531050, 85627050, 85723100, 85819200, 85915350, 86011550, 86107800, 86204100, 86300450, 86396850, 86493300, 86589800, 86686350, 86782950, 86879600, 86976300, 87073050, 87169850, 87266700, 87363600,
87460550, 87557550, 87654600, 87751700, 87848850, 87946050, 88043300, 88140600, 88237950, 88335350, 88432800, 88530300, 88627850, 88725450, 88823100, 88920800, 89018550, 89116350, 89214200, 89312100, 89410050,
89508050, 89606100, 89704200, 89802350, 89900550, 89998800, 90097100, 90195450, 90293850, 90392300, 90490800, 90589350, 90687950, 90786600, 90885300, 90984050, 91082850, 91181700, 91280600, 91379550, 91478550,
91577600, 91676700, 91775850, 91875050, 91974300, 92073600, 92172950, 92272350, 92371800, 92471300, 92570850, 92670450, 92770100, 92869800, 92969550, 93069350, 93169200, 93269100, 93369050, 93469050, 93569100,
93669200, 93769350, 93869550, 93969800, 94070100, 94170450, 94270850, 94371300, 94471800, 94572350, 94672950, 94773600, 94874300, 94975050, 95075850, 95176700, 95277600, 95378550, 95479550, 95580600, 95681700,
95782850, 95884050, 95985300, 96086600, 96187950, 96289350, 96390800, 96492300, 96593850, 96695450, 96797100, 96898800, 97000550, 97102350, 97204200, 97306100, 97408050, 97510050, 97612100, 97714200, 97816350,
97918550, 98020800, 98123100, 98225450, 98327850, 98430300, 98532800, 98635350, 98737950, 98840600, 98943300, 99046050, 99148850, 99251700, 99354600, 99457550, 99560550, 99663600, 99766700, 99869850, 99973050,
100076300, 100179600, 100282950, 100386350, 100489800, 100593300, 100696850, 100800450, 100904100, 101007800, 101111550, 101215350, 101319200, 101423100, 101527050, 101631050, 101735100, 101839200, 101943350,
102047550, 102151800, 102256100, 102360450, 102464850, 102569300, 102673800, 102778350, 102882950, 102987600, 103092300, 103197050, 103301850, 103406700, 103511600, 103616550, 103721550, 103826600, 103931700,
104036850, 104142050, 104247300, 104352600, 104457950, 104563350, 104668800, 104774300, 104879850, 104985450, 105091100, 105196800, 105302550, 105408350, 105514200, 105620100, 105726050, 105832050, 105938100,
106044200, 106150350, 106256550, 106362800, 106469100, 106575450, 106681850, 106788300, 106894800, 107001350, 107107950, 107214600, 107321300, 107428050, 107534850, 107641700, 107748600, 107855550, 107962550,
108069600, 108176700, 108283850, 108391050, 108498300, 108605600, 108712950, 108820350, 108927800, 109035300, 109142850, 109250450, 109358100, 109465800, 109573550, 109681350, 109789200, 109897100, 110005050,
110113050, 110221100, 110329200, 110437350, 110545550, 110653800, 110762100, 110870450, 110978850, 111087300, 111195800, 111304350, 111412950, 111521600, 111630300, 111739050, 111847850, 111956700, 112065600,
112174550, 112283550, 112392600, 112501700, 112610850, 112720050, 112829300, 112938600, 113047950, 113157350, 113266800, 113376300, 113485850, 113595450, 113705100, 113814800, 113924550, 114034350, 114144200,
114254100, 114364050, 114474050, 114584100, 114694200, 114804350, 114914550, 115024800, 115135100, 115245450, 115355850, 115466300, 115576800, 115687350, 115797950, 115908600, 116019300, 116130050, 116240850,
116351700, 116462600, 116573550, 116684550, 116795600, 116906700, 117017850, 117129050, 117240300, 117351600, 117462950, 117574350, 117685800, 117797300, 117908850, 118020450, 118132100, 118243800, 118355550,
118467350, 118579200, 118691100, 118803050, 118915050, 119027100, 119139200, 119251350, 119363550, 119475800, 119588100, 119700450, 119812850, 119925300, 120037800, 120150350, 120262950, 120375600, 120488300,
120601050, 120713850, 120826700, 120939600, 121052550, 121165550, 121278600, 121391700, 121504850, 121618050, 121731300, 121844600, 121957950, 122071350, 122184800, 122298300, 122411850, 122525450, 122639100,
122752800, 122866550, 122980350, 123094200, 123208100, 123322050, 123436050, 123550100, 123664200, 123778350, 123892550, 124006800, 124121100, 124235450, 124349850, 124464300, 124578800, 124693350, 124807950,
124922600, 125037300, 125152050, 125266850, 125381700, 125496600, 125611550, 125726550, 125841600, 125956700, 126071850, 126187050, 126302300, 126417600, 126532950, 126648350, 126763800, 126879300, 126994850,
127110450, 127226100, 127341800, 127457550, 127573350, 127689200, 127805100, 127921050, 128037050, 128153100, 128269200, 128385350, 128501550, 128617800, 128734100, 128850450, 128966850, 129083300, 129199800,
129316350, 129432950, 129549600, 129666300, 129783050, 129899850, 130016700, 130133600, 130250550, 130367550, 130484600, 130601700, 130718850, 130836050, 130953300, 131070600, 131187950, 131305350, 131422800,
131540300, 131657850, 131775450, 131893100, 132010800, 132128550, 132246350, 132364200, 132482100, 132600050, 132718050, 132836100, 132954200, 133072350, 133190550, 133308800, 133427100, 133545450, 133663850,
133782300, 133900800, 134019350, 134137950, 134256600, 134375300, 134494050, 134612850, 134731700, 134850600, 134969550, 135088550, 135207600, 135326700, 135445850, 135565050, 135684300, 135803600, 135922950,
136042350, 136161800, 136281300, 136400850, 136520450, 136640100, 136759800, 136879550, 136999350, 137119200, 137239100, 137359050, 137479050, 137599100, 137719200, 137839350, 137959550, 138079800, 138200100,
138320450, 138440850, 138561300, 138681800, 138802350, 138922950, 139043600, 139164300, 139285050, 139405850, 139526700, 139647600, 139768550, 139889550, 140010600, 140131700, 140252850, 140374050, 140495300,
140616600, 140737950, 140859350, 140980800, 141102300, 141223850, 141345450, 141467100, 141588800, 141710550, 141832350, 141954200, 142076100, 142198050, 142320050, 142442100, 142564200, 142686350, 142808550,
142930800, 143053100, 143175450, 143297850, 143420300, 143542800, 143665350, 143787950, 143910600, 144033300, 144156050, 144278850, 144401700, 144524600, 144647550, 144770550, 144893600, 145016700, 145139850,
145263050, 145386300, 145509600, 145632950, 145756350, 145879800, 146003300, 146126850, 146250450, 146374100, 146497800, 146621550, 146745350, 146869200, 146993100, 147117050, 147241050, 147365100, 147489200,
147613350, 147737550, 147861800, 147986100, 148110450, 148234850, 148359300, 148483800, 148608350, 148732950, 148857600, 148982300, 149107050, 149231850, 149356700, 149481600, 149606550, 149731550, 149856600,
149981700, 150106850, 150232050, 150357300, 150482600, 150607950, 150733350, 150858800, 150984300, 151109850, 151235450, 151361100, 151486800, 151612550, 151738350, 151864200, 151990100, 152116050, 152242050,
152368100, 152494200, 152620350, 152746550, 152872800, 152999100, 153125450, 153251850, 153378300, 153504800, 153631350, 153757950, 153884600, 154011300, 154138050, 154264850, 154391700, 154518600, 154645550,
154772550, 154899600, 155026700, 155153850, 155281050, 155408300, 155535600, 155662950, 155790350, 155917800, 156045300, 156172850, 156300450, 156428100, 156555800, 156683550, 156811350, 156939200, 157067100,
157195050, 157323050, 157451100, 157579200, 157707350, 157835550, 157963800, 158092100, 158220450, 158348850, 158477300, 158605800, 158734350, 158862950, 158991600, 159120300, 159249050, 159377850, 159506700,
159635600, 159764550, 159893550, 160022600, 160151700, 160280850, 160410050, 160539300, 160668600, 160797950, 160927350, 161056800, 161186300, 161315850, 161445450, 161575100, 161704800, 161834550, 161964350,
162094200, 162224100, 162354050, 162484050, 162614100, 162744200, 162874350, 163004550, 163134800, 163265100, 163395450, 163525850, 163656300, 163786800, 163917350, 164047950, 164178600, 164309300, 164440050,
164570850, 164701700, 164832600, 164963550, 165094550, 165225600, 165356700, 165487850, 165619050, 165750300, 165881600, 166012950, 166144350, 166275800, 166407300, 166538850, 166670450, 166802100, 166933800,
167065550, 167197350, 167329200, 167461100, 167593050, 167725050, 167857100, 167989200, 168121350, 168253550, 168385800, 168518100, 168650450, 168782850, 168915300, 169047800, 169180350, 169312950, 169445600,
169578300, 169711050, 169843850, 169976700, 170109600, 170242550, 170375550, 170508600, 170641700, 170774850, 170908050, 171041300, 171174600, 171307950, 171441350, 171574800, 171708300, 171841850, 171975450,
172109100, 172242800, 172376550, 172510350, 172644200, 172778100, 172912050, 173046050, 173180100, 173314200, 173448350, 173582550, 173716800, 173851100, 173985450, 174119850, 174254300, 174388800, 174523350,
174657950, 174792600, 174927300, 175062050, 175196850, 175331700, 175466600, 175601550, 175736550, 175871600, 176006700, 176141850, 176277050, 176412300, 176547600, 176682950, 176818350, 176953800, 177089300,
177224850, 177360450, 177496100, 177631800, 177767550, 177903350, 178039200, 178175100, 178311050, 178447050, 178583100, 178719200, 178855350, 178991550, 179127800, 179264100, 179400450, 179536850, 179673300,
179809800, 179946350, 180082950, 180219600, 180356300, 180493050, 180629850, 180766700, 180903600, 181040550, 181177550, 181314600, 181451700, 181588850, 181726050, 181863300, 182000600, 182137950, 182275350,
182412800, 182550300, 182687850, 182825450, 182963100, 183100800, 183238550, 183376350, 183514200, 183652100, 183790050, 183928050, 184066100, 184204200, 184342350, 184480550, 184618800, 184757100, 184895450,
185033850, 185172300, 185310800, 185449350, 185587950, 185726600, 185865300, 186004050, 186142850, 186281700, 186420600, 186559550, 186698550, 186837600, 186976700, 187115850, 187255050, 187394300, 187533600,
187672950, 187812350, 187951800, 188091300, 188230850, 188370450, 188510100, 188649800, 188789550, 188929350, 189069200, 189209100, 189349050, 189489050, 189629100, 189769200, 189909350, 190049550, 190189800,
190330100, 190470450, 190610850, 190751300, 190891800, 191032350, 191172950, 191313600, 191454300, 191595050, 191735850, 191876700, 192017600, 192158550, 192299550, 192440600, 192581700, 192722850, 192864050,
193005300, 193146600, 193287950, 193429350, 193570800, 193712300, 193853850, 193995450, 194137100, 194278800, 194420550, 194562350, 194704200, 194846100, 194988050, 195130050, 195272100, 195414200, 195556350,
195698550, 195840800, 195983100, 196125450, 196267850, 196410300, 196552800, 196695350, 196837950, 196980600, 197123300, 197266050, 197408850, 197551700, 197694600, 197837550, 197980550, 198123600, 198266700,
198409850, 198553050, 198696300, 198839600, 198982950, 199126350, 199269800, 199413300, 199556850, 199700450, 199844100, 199987800, 200131550, 200275350, 200419200, 200563100, 200707050, 200851050, 200995100,
201139200, 201283350, 201427550, 201571800, 201716100, 201860450, 202004850, 202149300, 202293800, 202438350, 202582950, 202727600, 202872300, 203017050, 203161850, 203306700, 203451600, 203596550, 203741550,
203886600, 204031700, 204176850, 204322050, 204467300, 204612600, 204757950, 204903350, 205048800, 205194300, 205339850, 205485450, 205631100, 205776800, 205922550, 206068350, 206214200, 206360100, 206506050,
206652050, 206798100, 206944200, 207090350, 207236550, 207382800, 207529100, 207675450, 207821850, 207968300, 208114800, 208261350, 208407950, 208554600, 208701300, 208848050, 208994850, 209141700, 209288600,
209435550, 209582550, 209729600, 209876700, 210023850, 210171050, 210318300, 210465600, 210612950, 210760350, 210907800, 211055300, 211202850, 211350450, 211498100, 211645800, 211793550, 211941350, 212089200,
212237100, 212385050, 212533050, 212681100, 212829200, 212977350, 213125550, 213273800, 213422100, 213570450, 213718850, 213867300, 214015800, 214164350, 214312950, 214461600, 214610300, 214759050, 214907850,
215056700, 215205600, 215354550, 215503550, 215652600, 215801700, 215950850, 216100050, 216249300, 216398600, 216547950, 216697350, 216846800, 216996300, 217145850, 217295450, 217445100, 217594800, 217744550,
217894350, 218044200, 218194100, 218344050, 218494050, 218644100, 218794200, 218944350, 219094550, 219244800, 219395100, 219545450, 219695850, 219846300, 219996800, 220147350, 220297950, 220448600, 220599300,
220750050, 220900850, 221051700, 221202600, 221353550, 221504550, 221655600, 221806700, 221957850, 222109050, 222260300, 222411600, 222562950, 222714350, 222865800, 223017300, 223168850, 223320450, 223472100,
223623800, 223775550, 223927350, 224079200, 224231100, 224383050, 224535050, 224687100, 224839200, 224991350, 225143550, 225295800, 225448100, 225600450, 225752850, 225905300, 226057800, 226210350, 226362950,
226515600, 226668300, 226821050, 226973850, 227126700, 227279600, 227432550, 227585550, 227738600, 227891700, 228044850, 228198050, 228351300, 228504600, 228657950, 228811350, 228964800, 229118300, 229271850,
229425450, 229579100, 229732800, 229886550, 230040350, 230194200, 230348100, 230502050, 230656050, 230810100, 230964200, 231118350, 231272550, 231426800, 231581100, 231735450, 231889850, 232044300, 232198800,
232353350, 232507950, 232662600, 232817300, 232972050, 233126850, 233281700, 233436600, 233591550, 233746550, 233901600, 234056700, 234211850, 234367050, 234522300, 234677600, 234832950, 234988350, 235143800,
235299300, 235454850, 235610450, 235766100, 235921800, 236077550, 236233350, 236389200, 236545100, 236701050, 236857050, 237013100, 237169200, 237325350, 237481550, 237637800, 237794100, 237950450, 238106850,
238263300, 238419800, 238576350, 238732950, 238889600, 239046300, 239203050, 239359850, 239516700, 239673600, 239830550, 239987550, 240144600, 240301700, 240458850, 240616050, 240773300, 240930600, 241087950,
241245350, 241402800, 241560300, 241717850, 241875450, 242033100, 242190800, 242348550, 242506350, 242664200, 242822100, 242980050, 243138050, 243296100, 243454200, 243612350, 243770550, 243928800, 244087100,
244245450, 244403850, 244562300, 244720800, 244879350, 245037950, 245196600, 245355300, 245514050, 245672850, 245831700, 245990600, 246149550, 246308550, 246467600, 246626700, 246785850, 246945050, 247104300,
247263600, 247422950, 247582350, 247741800, 247901300, 248060850, 248220450, 248380100, 248539800, 248699550, 248859350, 249019200, 249179100, 249339050, 249499050, 249659100, 249819200, 249979350, 250139550,
250299800, 250460100, 250620450, 250780850, 250941300, 251101800, 251262350, 251422950, 251583600, 251744300, 251905050, 252065850, 252226700, 252387600, 252548550, 252709550, 252870600, 253031700, 253192850,
253354050, 253515300, 253676600, 253837950, 253999350, 254160800, 254322300, 254483850, 254645450, 254807100, 254968800, 255130550, 255292350, 255454200, 255616100, 255778050, 255940050, 256102100, 256264200,
256426350, 256588550, 256750800, 256913100, 257075450, 257237850, 257400300, 257562800, 257725350, 257887950, 258050600, 258213300, 258376050, 258538850, 258701700, 258864600, 259027550, 259190550, 259353600,
259516700, 259679850, 259843050, 260006300, 260169600, 260332950, 260496350, 260659800, 260823300, 260986850, 261150450, 261314100, 261477800, 261641550, 261805350, 261969200, 262133100, 262297050, 262461050,
262625100, 262789200, 262953350, 263117550, 263281800, 263446100, 263610450, 263774850, 263939300, 264103800, 264268350, 264432950, 264597600, 264762300, 264927050, 265091850, 265256700, 265421600, 265586550,
265751550, 265916600, 266081700, 266246850, 266412050, 266577300, 266742600, 266907950, 267073350, 267238800, 267404300, 267569850, 267735450, 267901100, 268066800, 268232550, 268398350, 268564200, 268730100,
268896050, 269062050, 269228100, 269394200, 269560350, 269726550, 269892800, 270059100, 270225450, 270391850, 270558300, 270724800, 270891350, 271057950, 271224600, 271391300, 271558050, 271724850, 271891700,
272058600, 272225550, 272392550, 272559600, 272726700, 272893850, 273061050, 273228300, 273395600, 273562950, 273730350, 273897800, 274065300, 274232850, 274400450, 274568100, 274735800, 274903550, 275071350,
275239200, 275407100, 275575050, 275743050, 275911100, 276079200, 276247350, 276415550, 276583800, 276752100, 276920450, 277088850, 277257300, 277425800, 277594350, 277762950, 277931600, 278100300, 278269050,
278437850, 278606700, 278775600, 278944550, 279113550, 279282600, 279451700, 279620850, 279790050, 279959300, 280128600, 280297950, 280467350, 280636800, 280806300, 280975850, 281145450, 281315100, 281484800,
281654550, 281824350, 281994200, 282164100, 282334050, 282504050, 282674100, 282844200, 283014350, 283184550, 283354800, 283525100, 283695450, 283865850, 284036300, 284206800, 284377350, 284547950, 284718600,
284889300, 285060050, 285230850, 285401700, 285572600, 285743550, 285914550, 286085600, 286256700, 286427850, 286599050, 286770300, 286941600, 287112950, 287284350, 287455800, 287627300, 287798850, 287970450,
288142100, 288313800, 288485550, 288657350, 288829200, 289001100, 289173050, 289345050, 289517100, 289689200, 289861350, 290033550, 290205800, 290378100, 290550450, 290722850, 290895300, 291067800, 291240350,
291412950, 291585600, 291758300, 291931050, 292103850, 292276700, 292449600, 292622550, 292795550, 292968600, 293141700, 293314850, 293488050, 293661300, 293834600, 294007950, 294181350, 294354800, 294528300,
294701850, 294875450, 295049100, 295222800, 295396550, 295570350, 295744200, 295918100, 296092050, 296266050, 296440100, 296614200, 296788350, 296962550, 297136800, 297311100, 297485450, 297659850, 297834300,
298008800, 298183350, 298357950, 298532600, 298707300, 298882050, 299056850, 299231700, 299406600, 299581550, 299756550, 299931600, 300106700, 300281850, 300457050, 300632300, 300807600, 300982950, 301158350,
301333800, 301509300, 301684850, 301860450, 302036100, 302211800, 302387550, 302563350, 302739200, 302915100, 303091050, 303267050, 303443100, 303619200, 303795350, 303971550, 304147800, 304324100, 304500450,
304676850, 304853300, 305029800, 305206350, 305382950, 305559600, 305736300, 305913050, 306089850, 306266700, 306443600, 306620550, 306797550, 306974600, 307151700, 307328850, 307506050, 307683300, 307860600,
308037950, 308215350, 308392800, 308570300, 308747850, 308925450, 309103100, 309280800, 309458550, 309636350, 309814200, 309992100, 310170050, 310348050, 310526100, 310704200, 310882350, 311060550, 311238800,
311417100, 311595450, 311773850, 311952300, 312130800, 312309350, 312487950, 312666600, 312845300, 313024050, 313202850, 313381700, 313560600, 313739550, 313918550, 314097600, 314276700, 314455850, 314635050,
314814300, 314993600, 315172950, 315352350, 315531800, 315711300, 315890850, 316070450, 316250100, 316429800, 316609550, 316789350, 316969200, 317149100, 317329050, 317509050, 317689100, 317869200, 318049350,
318229550, 318409800, 318590100, 318770450, 318950850, 319131300, 319311800, 319492350, 319672950, 319853600, 320034300, 320215050, 320395850, 320576700, 320757600, 320938550, 321119550, 321300600, 321481700,
321662850, 321844050, 322025300, 322206600, 322387950, 322569350, 322750800, 322932300, 323113850, 323295450, 323477100, 323658800, 323840550, 324022350, 324204200, 324386100, 324568050, 324750050, 324932100,
325114200, 325296350, 325478550, 325660800, 325843100, 326025450, 326207850, 326390300, 326572800, 326755350, 326937950, 327120600, 327303300, 327486050, 327668850, 327851700, 328034600, 328217550, 328400550,
328583600, 328766700, 328949850, 329133050, 329316300, 329499600, 329682950, 329866350, 330049800, 330233300, 330416850, 330600450, 330784100, 330967800, 331151550, 331335350, 331519200, 331703100, 331887050,
332071050, 332255100, 332439200, 332623350, 332807550, 332991800, 333176100, 333360450, 333544850, 333729300, 333913800, 334098350, 334282950, 334467600, 334652300, 334837050, 335021850, 335206700, 335391600,
335576550, 335761550, 335946600, 336131700, 336316850, 336502050, 336687300, 336872600, 337057950, 337243350, 337428800, 337614300, 337799850, 337985450, 338171100, 338356800, 338542550, 338728350, 338914200,
339100100, 339286050, 339472050, 339658100, 339844200, 340030350, 340216550, 340402800, 340589100, 340775450, 340961850, 341148300, 341334800, 341521350, 341707950, 341894600, 342081300, 342268050, 342454850,
342641700, 342828600, 343015550, 343202550, 343389600, 343576700, 343763850, 343951050, 344138300, 344325600, 344512950, 344700350, 344887800, 345075300, 345262850, 345450450, 345638100, 345825800, 346013550,
346201350, 346389200, 346577100, 346765050, 346953050, 347141100, 347329200, 347517350, 347705550, 347893800, 348082100, 348270450, 348458850, 348647300, 348835800, 349024350, 349212950, 349401600, 349590300,
349779050, 349967850, 350156700, 350345600, 350534550, 350723550, 350912600, 351101700, 351290850, 351480050, 351669300, 351858600, 352047950, 352237350, 352426800, 352616300, 352805850, 352995450, 353185100,
353374800, 353564550, 353754350, 353944200, 354134100, 354324050, 354514050, 354704100, 354894200, 355084350, 355274550, 355464800, 355655100, 355845450, 356035850, 356226300, 356416800, 356607350, 356797950,
356988600, 357179300, 357370050, 357560850, 357751700, 357942600, 358133550, 358324550, 358515600, 358706700, 358897850, 359089050, 359280300, 359471600, 359662950, 359854350, 360045800, 360237300, 360428850,
360620450, 360812100, 361003800, 361195550, 361387350, 361579200, 361771100, 361963050, 362155050, 362347100, 362539200, 362731350, 362923550, 363115800, 363308100, 363500450, 363692850, 363885300, 364077800,
364270350, 364462950, 364655600, 364848300, 365041050, 365233850, 365426700, 365619600, 365812550, 366005550, 366198600, 366391700, 366584850, 366778050, 366971300, 367164600, 367357950, 367551350, 367744800,
367938300, 368131850, 368325450, 368519100, 368712800, 368906550, 369100350, 369294200, 369488100, 369682050, 369876050, 370070100, 370264200, 370458350, 370652550, 370846800, 371041100, 371235450, 371429850,
371624300, 371818800, 372013350, 372207950, 372402600, 372597300, 372792050, 372986850, 373181700, 373376600, 373571550, 373766550, 373961600, 374156700, 374351850, 374547050, 374742300, 374937600, 375132950,
375328350, 375523800, 375719300, 375914850, 376110450, 376306100, 376501800, 376697550, 376893350, 377089200, 377285100, 377481050, 377677050, 377873100, 378069200, 378265350, 378461550, 378657800, 378854100,
379050450, 379246850, 379443300, 379639800, 379836350, 380032950, 380229600, 380426300, 380623050, 380819850, 381016700, 381213600, 381410550, 381607550, 381804600, 382001700, 382198850, 382396050, 382593300,
382790600, 382987950, 383185350, 383382800, 383580300, 383777850, 383975450, 384173100, 384370800, 384568550, 384766350, 384964200, 385162100, 385360050, 385558050, 385756100, 385954200, 386152350, 386350550,
386548800, 386747100, 386945450, 387143850, 387342300, 387540800, 387739350, 387937950, 388136600, 388335300, 388534050, 388732850, 388931700, 389130600, 389329550, 389528550, 389727600, 389926700, 390125850,
390325050, 390524300, 390723600, 390922950, 391122350, 391321800, 391521300, 391720850, 391920450, 392120100, 392319800, 392519550, 392719350, 392919200, 393119100, 393319050, 393519050, 393719100, 393919200,
394119350, 394319550, 394519800, 394720100, 394920450, 395120850, 395321300, 395521800, 395722350, 395922950, 396123600, 396324300, 396525050, 396725850, 396926700, 397127600, 397328550, 397529550, 397730600,
397931700, 398132850, 398334050, 398535300, 398736600, 398937950, 399139350, 399340800, 399542300, 399743850, 399945450, 400147100, 400348800, 400550550, 400752350, 400954200, 401156100, 401358050, 401560050,
401762100, 401964200, 402166350, 402368550, 402570800, 402773100, 402975450, 403177850, 403380300, 403582800, 403785350, 403987950, 404190600, 404393300, 404596050, 404798850, 405001700, 405204600, 405407550,
405610550, 405813600, 406016700, 406219850, 406423050, 406626300, 406829600, 407032950, 407236350, 407439800, 407643300, 407846850, 408050450, 408254100, 408457800, 408661550, 408865350, 409069200, 409273100,
409477050, 409681050, 409885100, 410089200, 410293350, 410497550, 410701800, 410906100, 411110450, 411314850, 411519300, 411723800, 411928350, 412132950, 412337600, 412542300, 412747050, 412951850, 413156700,
413361600, 413566550, 413771550, 413976600, 414181700, 414386850, 414592050, 414797300, 415002600, 415207950, 415413350, 415618800, 415824300, 416029850, 416235450, 416441100, 416646800, 416852550, 417058350,
417264200, 417470100, 417676050, 417882050, 418088100, 418294200, 418500350, 418706550, 418912800, 419119100, 419325450, 419531850, 419738300, 419944800, 420151350, 420357950, 420564600, 420771300, 420978050,
421184850, 421391700, 421598600, 421805550, 422012550, 422219600, 422426700, 422633850, 422841050, 423048300, 423255600, 423462950, 423670350, 423877800, 424085300, 424292850, 424500450, 424708100, 424915800,
425123550, 425331350, 425539200, 425747100, 425955050, 426163050, 426371100, 426579200, 426787350, 426995550, 427203800, 427412100, 427620450, 427828850, 428037300, 428245800, 428454350, 428662950, 428871600,
429080300, 429289050, 429497850, 429706700, 429915600, 430124550, 430333550, 430542600, 430751700, 430960850, 431170050, 431379300, 431588600, 431797950, 432007350, 432216800, 432426300, 432635850, 432845450,
433055100, 433264800, 433474550, 433684350, 433894200, 434104100, 434314050, 434524050, 434734100, 434944200, 435154350, 435364550, 435574800, 435785100, 435995450, 436205850, 436416300, 436626800, 436837350,
437047950, 437258600, 437469300, 437680050, 437890850, 438101700, 438312600, 438523550, 438734550, 438945600, 439156700, 439367850, 439579050, 439790300, 440001600, 440212950, 440424350, 440635800, 440847300,
441058850, 441270450, 441482100, 441693800, 441905550, 442117350, 442329200, 442541100, 442753050, 442965050, 443177100, 443389200, 443601350, 443813550, 444025800, 444238100, 444450450, 444662850, 444875300,
445087800, 445300350, 445512950, 445725600, 445938300, 446151050, 446363850, 446576700, 446789600, 447002550, 447215550, 447428600, 447641700, 447854850, 448068050, 448281300, 448494600, 448707950, 448921350,
449134800, 449348300, 449561850, 449775450, 449989100, 450202800, 450416550, 450630350, 450844200, 451058100, 451272050, 451486050, 451700100, 451914200, 452128350, 452342550, 452556800, 452771100, 452985450,
453199850, 453414300, 453628800, 453843350, 454057950, 454272600, 454487300, 454702050, 454916850, 455131700, 455346600, 455561550, 455776550, 455991600, 456206700, 456421850, 456637050, 456852300, 457067600,
457282950, 457498350, 457713800, 457929300, 458144850, 458360450, 458576100, 458791800, 459007550, 459223350, 459439200, 459655100, 459871050, 460087050, 460303100, 460519200, 460735350, 460951550, 461167800,
461384100, 461600450, 461816850, 462033300, 462249800, 462466350, 462682950, 462899600, 463116300, 463333050, 463549850, 463766700, 463983600, 464200550, 464417550, 464634600, 464851700, 465068850, 465286050,
465503300, 465720600, 465937950, 466155350, 466372800, 466590300, 466807850, 467025450, 467243100, 467460800, 467678550, 467896350, 468114200, 468332100, 468550050, 468768050, 468986100, 469204200, 469422350,
469640550, 469858800, 470077100, 470295450, 470513850, 470732300, 470950800, 471169350, 471387950, 471606600, 471825300, 472044050, 472262850, 472481700, 472700600, 472919550, 473138550, 473357600, 473576700,
473795850, 474015050, 474234300, 474453600, 474672950, 474892350, 475111800, 475331300, 475550850, 475770450, 475990100, 476209800, 476429550, 476649350, 476869200, 477089100, 477309050, 477529050, 477749100,
477969200, 478189350, 478409550, 478629800, 478850100, 479070450, 479290850, 479511300, 479731800, 479952350, 480172950, 480393600, 480614300, 480835050, 481055850, 481276700, 481497600, 481718550, 481939550, 482160600, 482381700, 482602850, 482824050, 483045300, 483266600, 483487950, 483709350, 483930800, 484152300, 484373850, 484595450, 484817100, 485038800, 485260550, 485482350, 485704200, 485926100, 486148050, 486370050, 486592100, 486814200, 487036350, 487258550, 487480800, 487703100, 487925450, 488147850, 488370300, 488592800, 488815350, 489037950, 489260600, 489483300, 489706050, 489928850, 490151700, 490374600, 490597550, 490820550, 491043600, 491266700, 491489850, 491713050, 491936300, 492159600, 492382950, 492606350, 492829800, 493053300, 493276850, 493500450, 493724100, 493947800, 494171550, 494395350, 494619200, 494843100, 495067050, 495291050, 495515100, 495739200, 495963350, 496187550, 496411800, 496636100, 496860450, 497084850, 497309300, 497533800, 497758350, 497982950, 498207600, 498432300, 498657050, 498881850, 499106700, 499331600, 499556550, 499781550, 500006600, 500231700, 500456850, 500682050, 500907300, 501132600, 501357950, 501583350, 501808800, 502034300, 502259850, 502485450, 502711100, 502936800, 503162550, 503388350, 503614200, 503840100, 504066050, 504292050, 504518100, 504744200, 504970350, 505196550, 505422800, 505649100, 505875450, 506101850, 506328300, 506554800, 506781350, 507007950, 507234600, 507461300, 507688050, 507914850, 508141700, 508368600, 508595550, 508822550, 509049600, 509276700, 509503850, 509731050, 509958300, 510185600, 510412950, 510640350, 510867800, 511095300, 511322850, 511550450, 511778100, 512005800, 512233550, 512461350, 512689200, 512917100, 513145050, 513373050, 513601100, 513829200, 514057350, 514285550, 514513800, 514742100, 514970450, 515198850, 515427300, 515655800, 515884350, 516112950, 516341600, 516570300, 516799050, 517027850, 517256700, 517485600, 517714550, 517943550, 518172600, 518401700, 518630850, 518860050, 519089300, 519318600, 519547950, 519777350, 520006800, 520236300, 520465850, 520695450, 520925100, 521154800, 521384550, 521614350, 521844200, 522074100, 522304050, 522534050, 522764100, 522994200, 523224350, 523454550, 523684800, 523915100, 524145450, 524375850, 524606300, 524836800, 525067350, 525297950, 525528600, 525759300, 525990050, 526220850, 526451700, 526682600, 526913550, 527144550, 527375600, 527606700, 527837850, 528069050, 528300300, 528531600, 528762950, 528994350, 529225800, 529457300, 529688850, 529920450, 530152100, 530383800, 530615550, 530847350, 531079200, 531311100, 531543050, 531775050, 532007100, 532239200, 532471350, 532703550, 532935800, 533168100, 533400450, 533632850, 533865300, 534097800, 534330350, 534562950, 534795600, 535028300, 535261050, 535493850, 535726700, 535959600, 536192550, 536425550, 536658600, 536891700, 537124850, 537358050, 537591300, 537824600, 538057950, 538291350, 538524800, 538758300, 538991850, 539225450, 539459100, 539692800, 539926550, 540160350, 540394200, 540628100, 540862050, 541096050, 541330100, 541564200, 541798350, 542032550, 542266800, 542501100, 542735450, 542969850, 543204300, 543438800, 543673350, 543907950, 544142600, 544377300, 544612050, 544846850, 545081700, 545316600, 545551550, 545786550, 546021600, 546256700, 546491850, 546727050, 546962300, 547197600, 547432950, 547668350, 547903800, 548139300, 548374850, 548610450, 548846100, 549081800, 549317550, 549553350, 549789200, 550025100, 550261050, 550497050, 550733100, 550969200, 551205350, 551441550, 551677800, 551914100, 552150450, 552386850, 552623300, 552859800, 553096350, 553332950, 553569600, 553806300, 554043050, 554279850, 554516700, 554753600, 554990550, 555227550, 555464600, 555701700, 555938850, 556176050, 556413300, 556650600, 556887950, 557125350, 557362800, 557600300, 557837850, 558075450, 558313100, 558550800, 558788550, 559026350, 559264200, 559502100, 559740050, 559978050, 560216100, 560454200, 560692350, 560930550, 561168800, 561407100, 561645450, 561883850, 562122300, 562360800, 562599350, 562837950, 563076600, 563315300, 563554050, 563792850, 564031700, 564270600, 564509550, 564748550, 564987600, 565226700, 565465850, 565705050, 565944300, 566183600, 566422950, 566662350, 566901800, 567141300, 567380850, 567620450, 567860100, 568099800, 568339550, 568579350, 568819200, 569059100, 569299050, 569539050, 569779100, 570019200, 570259350, 570499550, 570739800, 570980100, 571220450, 571460850, 571701300, 571941800, 572182350, 572422950, 572663600, 572904300, 573145050, 573385850, 573626700, 573867600, 574108550, 574349550, 574590600, 574831700, 575072850, 575314050, 575555300, 575796600, 576037950, 576279350, 576520800, 576762300, 577003850, 577245450, 577487100, 577728800, 577970550, 578212350, 578454200, 578696100, 578938050, 579180050, 579422100, 579664200, 579906350, 580148550, 580390800, 580633100, 580875450, 581117850, 581360300, 581602800, 581845350, 582087950, 582330600, 582573300, 582816050, 583058850, 583301700, 583544600, 583787550, 584030550, 584273600, 584516700, 584759850, 585003050, 585246300, 585489600, 585732950, 585976350, 586219800, 586463300, 586706850, 586950450, 587194100, 587437800, 587681550, 587925350, 588169200, 588413100, 588657050, 588901050, 589145100, 589389200, 589633350, 589877550, 590121800, 590366100, 590610450, 590854850, 591099300, 591343800, 591588350, 591832950, 592077600, 592322300, 592567050, 592811850, 593056700, 593301600, 593546550, 593791550, 594036600, 594281700, 594526850, 594772050, 595017300, 595262600, 595507950, 595753350, 595998800, 596244300, 596489850, 596735450, 596981100, 597226800, 597472550, 597718350, 597964200, 598210100, 598456050, 598702050, 598948100, 599194200, 599440350, 599686550, 599932800, 600179100, 600425450, 600671850, 600918300, 601164800, 601411350, 601657950, 601904600, 602151300, 602398050, 602644850, 602891700, 603138600, 603385550, 603632550, 603879600, 604126700, 604373850, 604621050, 604868300, 605115600, 605362950, 605610350, 605857800, 606105300, 606352850, 606600450, 606848100, 607095800, 607343550, 607591350, 607839200, 608087100, 608335050, 608583050, 608831100, 609079200, 609327350, 609575550, 609823800, 610072100, 610320450, 610568850, 610817300, 611065800, 611314350, 611562950, 611811600, 612060300, 612309050, 612557850, 612806700, 613055600, 613304550, 613553550, 613802600, 614051700, 614300850, 614550050, 614799300, 615048600, 615297950, 615547350, 615796800, 616046300, 616295850, 616545450, 616795100, 617044800, 617294550, 617544350, 617794200, 618044100, 618294050, 618544050, 618794100, 619044200, 619294350, 619544550, 619794800, 620045100, 620295450, 620545850, 620796300, 621046800, 621297350, 621547950, 621798600, 622049300, 622300050, 622550850, 622801700, 623052600, 623303550, 623554550, 623805600, 624056700, 624307850, 624559050, 624810300, 625061600, 625312950, 625564350, 625815800, 626067300, 626318850, 626570450, 626822100, 627073800, 627325550, 627577350, 627829200, 628081100, 628333050, 628585050, 628837100, 629089200, 629341350, 629593550, 629845800, 630098100, 630350450, 630602850, 630855300, 631107800, 631360350, 631612950, 631865600, 632118300, 632371050, 632623850, 632876700, 633129600, 633382550, 633635550, 633888600, 634141700, 634394850, 634648050, 634901300, 635154600, 635407950, 635661350, 635914800, 636168300, 636421850, 636675450, 636929100, 637182800, 637436550, 637690350, 637944200, 638198100, 638452050, 638706050, 638960100, 639214200, 639468350, 639722550, 639976800, 640231100, 640485450, 640739850, 640994300, 641248800, 641503350, 641757950, 642012600, 642267300, 642522050, 642776850, 643031700, 643286600, 643541550, 643796550, 644051600, 644306700, 644561850, 644817050, 645072300, 645327600, 645582950, 645838350, 646093800, 646349300, 646604850, 646860450, 647116100, 647371800, 647627550, 647883350, 648139200, 648395100, 648651050, 648907050, 649163100, 649419200, 649675350, 649931550, 650187800, 650444100, 650700450, 650956850, 651213300, 651469800, 651726350, 651982950, 652239600, 652496300, 652753050, 653009850, 653266700, 653523600, 653780550, 654037550, 654294600, 654551700, 654808850, 655066050, 655323300, 655580600, 655837950, 656095350, 656352800, 656610300, 656867850, 657125450, 657383100, 657640800, 657898550, 658156350, 658414200, 658672100, 658930050, 659188050, 659446100, 659704200, 659962350, 660220550, 660478800, 660737100, 660995450, 661253850, 661512300, 661770800, 662029350, 662287950, 662546600, 662805300, 663064050, 663322850, 663581700, 663840600, 664099550, 664358550, 664617600, 664876700, 665135850, 665395050, 665654300, 665913600, 666172950, 666432350, 666691800, 666951300, 667210850, 667470450, 667730100, 667989800, 668249550, 668509350, 668769200, 669029100, 669289050, 669549050, 669809100, 670069200, 670329350, 670589550, 670849800, 671110100, 671370450, 671630850, 671891300, 672151800, 672412350, 672672950, 672933600, 673194300, 673455050, 673715850, 673976700, 674237600, 674498550, 674759550, 675020600, 675281700, 675542850, 675804050, 676065300, 676326600, 676587950, 676849350, 677110800, 677372300, 677633850, 677895450, 678157100, 678418800, 678680550, 678942350, 679204200, 679466100, 679728050, 679990050, 680252100, 680514200, 680776350, 681038550, 681300800, 681563100, 681825450, 682087850, 682350300, 682612800, 682875350, 683137950, 683400600, 683663300, 683926050, 684188850, 684451700, 684714600, 684977550, 685240550, 685503600, 685766700, 686029850, 686293050, 686556300, 686819600, 687082950, 687346350, 687609800, 687873300, 688136850, 688400450, 688664100, 688927800, 689191550, 689455350, 689719200, 689983100, 690247050, 690511050, 690775100, 691039200, 691303350, 691567550, 691831800, 692096100, 692360450, 692624850, 692889300, 693153800, 693418350, 693682950, 693947600, 694212300, 694477050, 694741850, 695006700, 695271600, 695536550, 695801550, 696066600, 696331700, 696596850, 696862050, 697127300, 697392600, 697657950, 697923350, 698188800, 698454300, 698719850, 698985450, 699251100, 699516800, 699782550, 700048350, 700314200, 700580100, 700846050, 701112050, 701378100, 701644200, 701910350, 702176550, 702442800, 702709100, 702975450, 703241850, 703508300, 703774800, 704041350, 704307950, 704574600, 704841300, 705108050, 705374850, 705641700, 705908600, 706175550, 706442550, 706709600, 706976700, 707243850, 707511050, 707778300, 708045600, 708312950, 708580350, 708847800, 709115300, 709382850, 709650450, 709918100, 710185800, 710453550, 710721350, 710989200, 711257100, 711525050, 711793050, 712061100, 712329200, 712597350, 712865550, 713133800, 713402100, 713670450, 713938850, 714207300, 714475800, 714744350, 715012950, 715281600, 715550300, 715819050, 716087850, 716356700, 716625600, 716894550, 717163550, 717432600, 717701700, 717970850, 718240050, 718509300, 718778600, 719047950, 719317350, 719586800, 719856300, 720125850, 720395450, 720665100, 720934800, 721204550, 721474350, 721744200, 722014100, 722284050, 722554050, 722824100, 723094200, 723364350, 723634550, 723904800, 724175100, 724445450, 724715850, 724986300, 725256800, 725527350, 725797950, 726068600, 726339300, 726610050, 726880850, 727151700, 727422600, 727693550, 727964550, 728235600, 728506700, 728777850, 729049050, 729320300, 729591600, 729862950, 730134350, 730405800, 730677300, 730948850, 731220450, 731492100, 731763800, 732035550, 732307350, 732579200, 732851100, 733123050, 733395050, 733667100, 733939200, 734211350, 734483550, 734755800, 735028100, 735300450, 735572850, 735845300, 736117800, 736390350, 736662950, 736935600, 737208300, 737481050, 737753850, 738026700, 738299600, 738572550, 738845550, 739118600, 739391700, 739664850, 739938050, 740211300, 740484600, 740757950, 741031350, 741304800, 741578300, 741851850, 742125450, 742399100, 742672800, 742946550, 743220350, 743494200, 743768100, 744042050, 744316050, 744590100, 744864200, 745138350, 745412550, 745686800, 745961100, 746235450, 746509850, 746784300, 747058800, 747333350, 747607950, 747882600, 748157300, 748432050, 748706850, 748981700, 749256600, 749531550, 749806550, 750081600, 750356700, 750631850, 750907050, 751182300, 751457600, 751732950, 752008350, 752283800, 752559300, 752834850, 753110450, 753386100, 753661800, 753937550, 754213350, 754489200, 754765100, 755041050, 755317050, 755593100, 755869200, 756145350, 756421550, 756697800, 756974100, 757250450, 757526850, 757803300, 758079800, 758356350, 758632950, 758909600, 759186300, 759463050, 759739850, 760016700, 760293600, 760570550, 760847550, 761124600, 761401700, 761678850, 761956050, 762233300, 762510600, 762787950, 763065350, 763342800, 763620300, 763897850, 764175450, 764453100, 764730800, 765008550, 765286350, 765564200, 765842100, 766120050, 766398050, 766676100, 766954200, 767232350, 767510550, 767788800, 768067100, 768345450, 768623850, 768902300, 769180800, 769459350, 769737950, 770016600, 770295300, 770574050, 770852850, 771131700, 771410600, 771689550, 771968550, 772247600, 772526700, 772805850, 773085050, 773364300, 773643600, 773922950, 774202350, 774481800, 774761300, 775040850, 775320450, 775600100, 775879800, 776159550, 776439350, 776719200, 776999100, 777279050, 777559050, 777839100, 778119200, 778399350, 778679550, 778959800, 779240100, 779520450, 779800850, 780081300, 780361800, 780642350, 780922950, 781203600, 781484300, 781765050, 782045850, 782326700, 782607600, 782888550, 783169550, 783450600, 783731700, 784012850, 784294050, 784575300, 784856600, 785137950, 785419350, 785700800, 785982300, 786263850, 786545450, 786827100, 787108800, 787390550, 787672350, 787954200, 788236100, 788518050, 788800050, 789082100, 789364200, 789646350, 789928550, 790210800, 790493100, 790775450, 791057850, 791340300, 791622800, 791905350, 792187950, 792470600, 792753300, 793036050, 793318850, 793601700, 793884600, 794167550, 794450550, 794733600, 795016700, 795299850, 795583050, 795866300, 796149600, 796432950, 796716350, 796999800, 797283300, 797566850, 797850450, 798134100, 798417800, 798701550, 798985350, 799269200, 799553100, 799837050, 800121050, 800405100, 800689200, 800973350, 801257550, 801541800, 801826100, 802110450, 802394850, 802679300, 802963800, 803248350, 803532950, 803817600, 804102300, 804387050, 804671850, 804956700, 805241600, 805526550, 805811550, 806096600, 806381700, 806666850, 806952050, 807237300, 807522600, 807807950, 808093350, 808378800, 808664300, 808949850, 809235450, 809521100, 809806800, 810092550, 810378350, 810664200, 810950100, 811236050, 811522050, 811808100, 812094200, 812380350, 812666550, 812952800, 813239100, 813525450, 813811850, 814098300, 814384800, 814671350, 814957950, 815244600, 815531300, 815818050, 816104850, 816391700, 816678600, 816965550, 817252550, 817539600, 817826700, 818113850, 818401050, 818688300, 818975600, 819262950, 819550350, 819837800, 820125300, 820412850, 820700450, 820988100, 821275800, 821563550, 821851350, 822139200, 822427100, 822715050, 823003050, 823291100, 823579200, 823867350, 824155550, 824443800, 824732100, 825020450, 825308850, 825597300, 825885800, 826174350, 826462950, 826751600, 827040300, 827329050, 827617850, 827906700, 828195600, 828484550, 828773550, 829062600, 829351700, 829640850, 829930050, 830219300, 830508600, 830797950, 831087350, 831376800, 831666300, 831955850, 832245450, 832535100, 832824800, 833114550, 833404350, 833694200, 833984100, 834274050, 834564050, 834854100, 835144200, 835434350, 835724550, 836014800, 836305100, 836595450, 836885850, 837176300, 837466800, 837757350, 838047950, 838338600, 838629300, 838920050, 839210850, 839501700, 839792600, 840083550, 840374550, 840665600, 840956700, 841247850, 841539050, 841830300, 842121600, 842412950, 842704350, 842995800, 843287300, 843578850, 843870450, 844162100, 844453800, 844745550, 845037350, 845329200, 845621100, 845913050, 846205050, 846497100, 846789200, 847081350, 847373550, 847665800, 847958100, 848250450, 848542850, 848835300, 849127800, 849420350, 849712950, 850005600, 850298300, 850591050, 850883850, 851176700, 851469600, 851762550, 852055550, 852348600, 852641700, 852934850, 853228050, 853521300, 853814600, 854107950, 854401350, 854694800, 854988300, 855281850, 855575450, 855869100, 856162800, 856456550, 856750350, 857044200, 857338100, 857632050, 857926050, 858220100, 858514200, 858808350, 859102550, 859396800, 859691100, 859985450, 860279850, 860574300, 860868800, 861163350, 861457950, 861752600, 862047300, 862342050, 862636850, 862931700, 863226600, 863521550, 863816550, 864111600, 864406700, 864701850, 864997050, 865292300, 865587600, 865882950, 866178350, 866473800, 866769300, 867064850, 867360450, 867656100, 867951800, 868247550, 868543350, 868839200, 869135100, 869431050, 869727050, 870023100, 870319200, 870615350, 870911550, 871207800, 871504100, 871800450, 872096850, 872393300, 872689800, 872986350, 873282950, 873579600, 873876300, 874173050, 874469850, 874766700, 875063600, 875360550, 875657550, 875954600, 876251700, 876548850, 876846050, 877143300, 877440600, 877737950, 878035350, 878332800, 878630300, 878927850, 879225450, 879523100, 879820800, 880118550, 880416350, 880714200, 881012100, 881310050, 881608050, 881906100, 882204200, 882502350, 882800550, 883098800, 883397100, 883695450, 883993850, 884292300, 884590800, 884889350, 885187950, 885486600, 885785300, 886084050, 886382850, 886681700, 886980600, 887279550, 887578550, 887877600, 888176700, 888475850, 888775050, 889074300, 889373600, 889672950, 889972350, 890271800, 890571300, 890870850, 891170450, 891470100, 891769800, 892069550, 892369350, 892669200, 892969100, 893269050, 893569050, 893869100, 894169200, 894469350, 894769550, 895069800, 895370100, 895670450, 895970850, 896271300, 896571800, 896872350, 897172950, 897473600, 897774300, 898075050, 898375850, 898676700, 898977600, 899278550, 899579550, 899880600, 900181700, 900482850, 900784050, 901085300, 901386600, 901687950, 901989350, 902290800, 902592300, 902893850, 903195450, 903497100, 903798800, 904100550, 904402350, 904704200, 905006100, 905308050, 905610050, 905912100, 906214200, 906516350, 906818550, 907120800, 907423100, 907725450, 908027850, 908330300, 908632800, 908935350, 909237950, 909540600, 909843300, 910146050, 910448850, 910751700, 911054600, 911357550, 911660550, 911963600, 912266700, 912569850, 912873050, 913176300, 913479600, 913782950, 914086350, 914389800, 914693300, 914996850, 915300450, 915604100, 915907800, 916211550, 916515350, 916819200, 917123100, 917427050, 917731050, 918035100, 918339200, 918643350, 918947550, 919251800, 919556100, 919860450, 920164850, 920469300, 920773800, 921078350, 921382950, 921687600, 921992300, 922297050, 922601850, 922906700, 923211600, 923516550, 923821550, 924126600, 924431700, 924736850, 925042050, 925347300, 925652600, 925957950, 926263350, 926568800, 926874300, 927179850, 927485450, 927791100, 928096800, 928402550, 928708350, 929014200, 929320100, 929626050, 929932050, 930238100, 930544200, 930850350, 931156550, 931462800, 931769100, 932075450, 932381850, 932688300, 932994800, 933301350, 933607950, 933914600, 934221300, 934528050, 934834850, 935141700, 935448600, 935755550, 936062550, 936369600, 936676700, 936983850, 937291050, 937598300, 937905600, 938212950, 938520350, 938827800, 939135300, 939442850, 939750450, 940058100, 940365800, 940673550, 940981350, 941289200, 941597100, 941905050, 942213050, 942521100, 942829200, 943137350, 943445550, 943753800, 944062100, 944370450, 944678850, 944987300, 945295800, 945604350, 945912950, 946221600, 946530300, 946839050, 947147850, 947456700, 947765600, 948074550, 948383550, 948692600, 949001700, 949310850, 949620050, 949929300, 950238600, 950547950, 950857350, 951166800, 951476300, 951785850, 952095450, 952405100, 952714800, 953024550, 953334350, 953644200, 953954100, 954264050, 954574050, 954884100, 955194200, 955504350, 955814550, 956124800, 956435100, 956745450, 957055850, 957366300, 957676800, 957987350, 958297950, 958608600, 958919300, 959230050, 959540850, 959851700, 960162600, 960473550, 960784550, 961095600, 961406700, 961717850, 962029050, 962340300, 962651600, 962962950, 963274350, 963585800, 963897300, 964208850, 964520450, 964832100, 965143800, 965455550, 965767350, 966079200, 966391100, 966703050, 967015050, 967327100, 967639200, 967951350, 968263550, 968575800, 968888100, 969200450, 969512850, 969825300, 970137800, 970450350, 970762950, 971075600, 971388300, 971701050, 972013850, 972326700, 972639600, 972952550, 973265550, 973578600, 973891700, 974204850, 974518050, 974831300, 975144600, 975457950, 975771350, 976084800, 976398300, 976711850, 977025450, 977339100, 977652800, 977966550, 978280350, 978594200, 978908100, 979222050, 979536050, 979850100, 980164200, 980478350, 980792550, 981106800, 981421100, 981735450, 982049850, 982364300, 982678800, 982993350, 983307950, 983622600, 983937300, 984252050, 984566850, 984881700, 985196600, 985511550, 985826550, 986141600, 986456700, 986771850, 987087050, 987402300, 987717600, 988032950, 988348350, 988663800, 988979300, 989294850, 989610450, 989926100, 990241800, 990557550, 990873350, 991189200, 991505100, 991821050, 992137050, 992453100, 992769200, 993085350, 993401550, 993717800, 994034100, 994350450, 994666850, 994983300, 995299800, 995616350, 995932950, 996249600, 996566300, 996883050, 997199850, 997516700, 997833600, 998150550, 998467550, 998784600, 999101700, 999418850, 999736050, 1000053300, 1000370600, 1000687950, 1001005350, 1001322800, 1001640300, 1001957850, 1002275450, 1002593100, 1002910800, 1003228550, 1003546350, 1003864200, 1004182100, 1004500050, 1004818050, 1005136100, 1005454200, 1005772350, 1006090550, 1006408800, 1006727100, 1007045450, 1007363850, 1007682300, 1008000800, 1008319350, 1008637950, 1008956600, 1009275300, 1009594050, 1009912850, 1010231700, 1010550600, 1010869550, 1011188550, 1011507600, 1011826700, 1012145850, 1012465050, 1012784300, 1013103600, 1013422950, 1013742350, 1014061800, 1014381300, 1014700850, 1015020450, 1015340100, 1015659800, 1015979550, 1016299350, 1016619200, 1016939100, 1017259050, 1017579050, 1017899100, 1018219200, 1018539350, 1018859550, 1019179800, 1019500100, 1019820450, 1020140850, 1020461300, 1020781800, 1021102350, 1021422950, 1021743600, 1022064300, 1022385050, 1022705850, 1023026700, 1023347600, 1023668550, 1023989550, 1024310600, 1024631700, 1024952850, 1025274050, 1025595300, 1025916600, 1026237950, 1026559350, 1026880800, 1027202300, 1027523850, 1027845450, 1028167100, 1028488800, 1028810550, 1029132350, 1029454200, 1029776100, 1030098050, 1030420050, 1030742100, 1031064200, 1031386350, 1031708550, 1032030800, 1032353100, 1032675450, 1032997850, 1033320300, 1033642800, 1033965350, 1034287950, 1034610600, 1034933300, 1035256050, 1035578850, 1035901700, 1036224600, 1036547550, 1036870550, 1037193600, 1037516700, 1037839850, 1038163050, 1038486300, 1038809600, 1039132950, 1039456350, 1039779800, 1040103300, 1040426850, 1040750450, 1041074100, 1041397800, 1041721550, 1042045350, 1042369200, 1042693100, 1043017050, 1043341050, 1043665100, 1043989200, 1044313350, 1044637550, 1044961800, 1045286100, 1045610450, 1045934850, 1046259300, 1046583800, 1046908350, 1047232950, 1047557600, 1047882300, 1048207050, 1048531850, 1048856700, 1049181600, 1049506550, 1049831550, 1050156600, 1050481700, 1050806850, 1051132050, 1051457300, 1051782600, 1052107950, 1052433350, 1052758800, 1053084300, 1053409850, 1053735450, 1054061100, 1054386800, 1054712550, 1055038350, 1055364200, 1055690100, 1056016050, 1056342050, 1056668100, 1056994200, 1057320350, 1057646550, 1057972800, 1058299100, 1058625450, 1058951850, 1059278300, 1059604800, 1059931350, 1060257950, 1060584600, 1060911300, 1061238050, 1061564850, 1061891700, 1062218600, 1062545550, 1062872550, 1063199600, 1063526700, 1063853850, 1064181050, 1064508300, 1064835600, 1065162950, 1065490350, 1065817800, 1066145300, 1066472850, 1066800450, 1067128100, 1067455800, 1067783550, 1068111350, 1068439200, 1068767100, 1069095050, 1069423050, 1069751100, 1070079200, 1070407350, 1070735550, 1071063800, 1071392100, 1071720450, 1072048850, 1072377300, 1072705800, 1073034350, 1073362950, 1073691600, 1074020300, 1074349050, 1074677850, 1075006700, 1075335600, 1075664550, 1075993550, 1076322600, 1076651700, 1076980850, 1077310050, 1077639300, 1077968600, 1078297950, 1078627350, 1078956800, 1079286300, 1079615850, 1079945450, 1080275100, 1080604800, 1080934550, 1081264350, 1081594200, 1081924100, 1082254050, 1082584050, 1082914100, 1083244200, 1083574350, 1083904550, 1084234800, 1084565100, 1084895450, 1085225850, 1085556300, 1085886800, 1086217350, 1086547950, 1086878600, 1087209300, 1087540050, 1087870850, 1088201700, 1088532600, 1088863550, 1089194550, 1089525600, 1089856700, 1090187850, 1090519050, 1090850300, 1091181600, 1091512950, 1091844350, 1092175800, 1092507300, 1092838850, 1093170450, 1093502100, 1093833800, 1094165550, 1094497350, 1094829200, 1095161100, 1095493050, 1095825050, 1096157100, 1096489200, 1096821350, 1097153550, 1097485800, 1097818100, 1098150450, 1098482850, 1098815300, 1099147800, 1099480350, 1099812950, 1100145600, 1100478300, 1100811050, 1101143850, 1101476700, 1101809600, 1102142550, 1102475550, 1102808600, 1103141700, 1103474850, 1103808050, 1104141300, 1104474600, 1104807950, 1105141350, 1105474800, 1105808300, 1106141850, 1106475450, 1106809100, 1107142800, 1107476550, 1107810350, 1108144200, 1108478100, 1108812050, 1109146050, 1109480100, 1109814200, 1110148350, 1110482550, 1110816800, 1111151100, 1111485450, 1111819850, 1112154300, 1112488800, 1112823350, 1113157950, 1113492600, 1113827300, 1114162050, 1114496850, 1114831700, 1115166600, 1115501550, 1115836550, 1116171600, 1116506700, 1116841850, 1117177050, 1117512300, 1117847600, 1118182950, 1118518350, 1118853800, 1119189300, 1119524850, 1119860450, 1120196100, 1120531800, 1120867550, 1121203350, 1121539200, 1121875100, 1122211050, 1122547050, 1122883100, 1123219200, 1123555350, 1123891550, 1124227800, 1124564100, 1124900450, 1125236850, 1125573300, 1125909800, 1126246350, 1126582950, 1126919600, 1127256300, 1127593050, 1127929850, 1128266700, 1128603600, 1128940550, 1129277550, 1129614600, 1129951700, 1130288850, 1130626050, 1130963300, 1131300600, 1131637950, 1131975350, 1132312800, 1132650300, 1132987850, 1133325450, 1133663100, 1134000800, 1134338550, 1134676350, 1135014200, 1135352100, 1135690050, 1136028050, 1136366100, 1136704200, 1137042350, 1137380550, 1137718800, 1138057100, 1138395450, 1138733850, 1139072300, 1139410800, 1139749350, 1140087950, 1140426600, 1140765300, 1141104050, 1141442850, 1141781700, 1142120600, 1142459550, 1142798550, 1143137600, 1143476700, 1143815850, 1144155050, 1144494300, 1144833600, 1145172950, 1145512350, 1145851800, 1146191300, 1146530850, 1146870450, 1147210100, 1147549800, 1147889550, 1148229350, 1148569200, 1148909100, 1149249050, 1149589050, 1149929100, 1150269200, 1150609350, 1150949550, 1151289800, 1151630100, 1151970450, 1152310850, 1152651300, 1152991800, 1153332350, 1153672950, 1154013600, 1154354300, 1154695050, 1155035850, 1155376700, 1155717600, 1156058550, 1156399550, 1156740600, 1157081700, 1157422850, 1157764050, 1158105300, 1158446600, 1158787950, 1159129350, 1159470800, 1159812300, 1160153850, 1160495450, 1160837100, 1161178800, 1161520550, 1161862350, 1162204200, 1162546100, 1162888050, 1163230050, 1163572100, 1163914200, 1164256350, 1164598550, 1164940800, 1165283100, 1165625450, 1165967850, 1166310300, 1166652800, 1166995350, 1167337950, 1167680600, 1168023300, 1168366050, 1168708850, 1169051700, 1169394600, 1169737550, 1170080550, 1170423600, 1170766700, 1171109850, 1171453050, 1171796300, 1172139600, 1172482950, 1172826350, 1173169800, 1173513300, 1173856850, 1174200450, 1174544100, 1174887800, 1175231550, 1175575350, 1175919200, 1176263100, 1176607050, 1176951050, 1177295100, 1177639200, 1177983350, 1178327550, 1178671800, 1179016100, 1179360450, 1179704850, 1180049300, 1180393800, 1180738350, 1181082950, 1181427600, 1181772300, 1182117050, 1182461850, 1182806700, 1183151600, 1183496550, 1183841550, 1184186600, 1184531700, 1184876850, 1185222050, 1185567300, 1185912600, 1186257950, 1186603350, 1186948800, 1187294300, 1187639850, 1187985450, 1188331100, 1188676800, 1189022550, 1189368350, 1189714200, 1190060100, 1190406050, 1190752050, 1191098100, 1191444200, 1191790350, 1192136550, 1192482800, 1192829100, 1193175450, 1193521850, 1193868300, 1194214800, 1194561350, 1194907950, 1195254600, 1195601300, 1195948050, 1196294850, 1196641700, 1196988600, 1197335550, 1197682550, 1198029600, 1198376700, 1198723850, 1199071050, 1199418300, 1199765600, 1200112950, 1200460350, 1200807800, 1201155300, 1201502850, 1201850450, 1202198100, 1202545800, 1202893550, 1203241350, 1203589200, 1203937100, 1204285050, 1204633050, 1204981100, 1205329200, 1205677350, 1206025550, 1206373800, 1206722100, 1207070450, 1207418850, 1207767300, 1208115800, 1208464350, 1208812950, 1209161600, 1209510300, 1209859050, 1210207850, 1210556700, 1210905600, 1211254550, 1211603550, 1211952600, 1212301700, 1212650850, 1213000050, 1213349300, 1213698600, 1214047950, 1214397350, 1214746800, 1215096300, 1215445850, 1215795450, 1216145100, 1216494800, 1216844550, 1217194350, 1217544200, 1217894100, 1218244050, 1218594050, 1218944100, 1219294200, 1219644350, 1219994550, 1220344800, 1220695100, 1221045450, 1221395850, 1221746300, 1222096800, 1222447350, 1222797950, 1223148600, 1223499300, 1223850050, 1224200850, 1224551700, 1224902600, 1225253550, 1225604550, 1225955600, 1226306700, 1226657850, 1227009050, 1227360300, 1227711600, 1228062950, 1228414350, 1228765800, 1229117300, 1229468850, 1229820450, 1230172100, 1230523800, 1230875550, 1231227350, 1231579200, 1231931100, 1232283050, 1232635050, 1232987100, 1233339200, 1233691350, 1234043550, 1234395800, 1234748100, 1235100450, 1235452850, 1235805300, 1236157800, 1236510350, 1236862950, 1237215600, 1237568300, 1237921050, 1238273850, 1238626700, 1238979600, 1239332550, 1239685550, 1240038600, 1240391700, 1240744850, 1241098050, 1241451300, 1241804600, 1242157950, 1242511350, 1242864800, 1243218300, 1243571850, 1243925450, 1244279100, 1244632800, 1244986550, 1245340350, 1245694200, 1246048100, 1246402050, 1246756050, 1247110100, 1247464200, 1247818350, 1248172550, 1248526800, 1248881100, 1249235450, 1249589850, 1249944300, 1250298800, 1250653350, 1251007950, 1251362600, 1251717300, 1252072050, 1252426850, 1252781700, 1253136600, 1253491550, 1253846550, 1254201600, 1254556700, 1254911850, 1255267050, 1255622300, 1255977600, 1256332950, 1256688350, 1257043800, 1257399300, 1257754850, 1258110450, 1258466100, 1258821800, 1259177550, 1259533350, 1259889200, 1260245100, 1260601050, 1260957050, 1261313100, 1261669200, 1262025350, 1262381550, 1262737800, 1263094100, 1263450450, 1263806850, 1264163300, 1264519800, 1264876350, 1265232950, 1265589600, 1265946300, 1266303050, 1266659850, 1267016700, 1267373600, 1267730550, 1268087550, 1268444600, 1268801700, 1269158850, 1269516050, 1269873300, 1270230600, 1270587950, 1270945350, 1271302800, 1271660300, 1272017850, 1272375450, 1272733100, 1273090800, 1273448550, 1273806350, 1274164200, 1274522100, 1274880050, 1275238050, 1275596100, 1275954200, 1276312350, 1276670550, 1277028800, 1277387100, 1277745450, 1278103850, 1278462300, 1278820800, 1279179350, 1279537950, 1279896600, 1280255300, 1280614050, 1280972850, 1281331700, 1281690600, 1282049550, 1282408550, 1282767600, 1283126700, 1283485850, 1283845050, 1284204300, 1284563600, 1284922950, 1285282350, 1285641800, 1286001300, 1286360850, 1286720450, 1287080100, 1287439800, 1287799550, 1288159350, 1288519200, 1288879100, 1289239050, 1289599050, 1289959100, 1290319200, 1290679350, 1291039550, 1291399800, 1291760100, 1292120450, 1292480850, 1292841300, 1293201800, 1293562350, 1293922950, 1294283600, 1294644300, 1295005050, 1295365850, 1295726700, 1296087600, 1296448550, 1296809550, 1297170600, 1297531700, 1297892850, 1298254050, 1298615300, 1298976600, 1299337950, 1299699350, 1300060800, 1300422300, 1300783850, 1301145450, 1301507100, 1301868800, 1302230550, 1302592350, 1302954200, 1303316100, 1303678050, 1304040050, 1304402100, 1304764200, 1305126350, 1305488550, 1305850800, 1306213100, 1306575450, 1306937850, 1307300300, 1307662800, 1308025350, 1308387950, 1308750600, 1309113300, 1309476050, 1309838850, 1310201700, 1310564600, 1310927550, 1311290550, 1311653600, 1312016700, 1312379850, 1312743050, 1313106300, 1313469600, 1313832950, 1314196350, 1314559800, 1314923300, 1315286850, 1315650450, 1316014100, 1316377800, 1316741550, 1317105350, 1317469200, 1317833100, 1318197050, 1318561050, 1318925100, 1319289200, 1319653350, 1320017550, 1320381800, 1320746100, 1321110450, 1321474850, 1321839300, 1322203800, 1322568350, 1322932950, 1323297600, 1323662300, 1324027050, 1324391850, 1324756700, 1325121600, 1325486550, 1325851550, 1326216600, 1326581700, 1326946850, 1327312050, 1327677300, 1328042600, 1328407950, 1328773350, 1329138800, 1329504300, 1329869850, 1330235450, 1330601100, 1330966800, 1331332550, 1331698350, 1332064200, 1332430100, 1332796050, 1333162050, 1333528100, 1333894200, 1334260350, 1334626550, 1334992800, 1335359100, 1335725450, 1336091850, 1336458300, 1336824800, 1337191350, 1337557950, 1337924600, 1338291300, 1338658050, 1339024850, 1339391700, 1339758600, 1340125550, 1340492550, 1340859600, 1341226700, 1341593850, 1341961050, 1342328300, 1342695600, 1343062950, 1343430350, 1343797800, 1344165300, 1344532850, 1344900450, 1345268100, 1345635800, 1346003550, 1346371350, 1346739200, 1347107100, 1347475050, 1347843050, 1348211100, 1348579200, 1348947350, 1349315550, 1349683800, 1350052100, 1350420450, 1350788850, 1351157300, 1351525800, 1351894350, 1352262950, 1352631600, 1353000300, 1353369050, 1353737850, 1354106700, 1354475600, 1354844550, 1355213550, 1355582600, 1355951700, 1356320850, 1356690050, 1357059300, 1357428600, 1357797950, 1358167350, 1358536800, 1358906300, 1359275850, 1359645450, 1360015100, 1360384800, 1360754550, 1361124350, 1361494200, 1361864100, 1362234050, 1362604050, 1362974100, 1363344200, 1363714350, 1364084550, 1364454800, 1364825100, 1365195450, 1365565850, 1365936300, 1366306800, 1366677350, 1367047950, 1367418600, 1367789300, 1368160050, 1368530850, 1368901700, 1369272600, 1369643550, 1370014550, 1370385600, 1370756700, 1371127850, 1371499050, 1371870300, 1372241600, 1372612950, 1372984350, 1373355800, 1373727300, 1374098850, 1374470450, 1374842100, 1375213800, 1375585550, 1375957350, 1376329200, 1376701100, 1377073050, 1377445050, 1377817100, 1378189200, 1378561350, 1378933550, 1379305800, 1379678100, 1380050450, 1380422850, 1380795300, 1381167800, 1381540350, 1381912950, 1382285600, 1382658300, 1383031050, 1383403850, 1383776700, 1384149600, 1384522550, 1384895550, 1385268600, 1385641700, 1386014850, 1386388050, 1386761300, 1387134600, 1387507950, 1387881350, 1388254800, 1388628300, 1389001850, 1389375450, 1389749100, 1390122800, 1390496550, 1390870350, 1391244200, 1391618100, 1391992050, 1392366050, 1392740100, 1393114200, 1393488350, 1393862550, 1394236800, 1394611100, 1394985450, 1395359850, 1395734300, 1396108800, 1396483350, 1396857950, 1397232600, 1397607300, 1397982050, 1398356850, 1398731700, 1399106600, 1399481550, 1399856550, 1400231600, 1400606700, 1400981850, 1401357050, 1401732300, 1402107600, 1402482950, 1402858350, 1403233800, 1403609300, 1403984850, 1404360450, 1404736100, 1405111800, 1405487550, 1405863350, 1406239200, 1406615100, 1406991050, 1407367050, 1407743100, 1408119200, 1408495350, 1408871550, 1409247800, 1409624100, 1410000450, 1410376850, 1410753300, 1411129800, 1411506350, 1411882950, 1412259600, 1412636300, 1413013050, 1413389850, 1413766700, 1414143600, 1414520550, 1414897550, 1415274600, 1415651700, 1416028850, 1416406050, 1416783300, 1417160600, 1417537950, 1417915350, 1418292800, 1418670300, 1419047850, 1419425450, 1419803100, 1420180800, 1420558550, 1420936350, 1421314200, 1421692100, 1422070050, 1422448050, 1422826100, 1423204200, 1423582350, 1423960550, 1424338800, 1424717100, 1425095450, 1425473850, 1425852300, 1426230800, 1426609350, 1426987950, 1427366600, 1427745300, 1428124050, 1428502850, 1428881700, 1429260600, 1429639550, 1430018550, 1430397600, 1430776700, 1431155850, 1431535050, 1431914300, 1432293600, 1432672950, 1433052350, 1433431800, 1433811300, 1434190850, 1434570450, 1434950100, 1435329800, 1435709550, 1436089350, 1436469200, 1436849100, 1437229050, 1437609050, 1437989100, 1438369200, 1438749350, 1439129550, 1439509800, 1439890100, 1440270450, 1440650850, 1441031300, 1441411800, 1441792350, 1442172950, 1442553600, 1442934300, 1443315050, 1443695850, 1444076700, 1444457600, 1444838550, 1445219550, 1445600600, 1445981700, 1446362850, 1446744050, 1447125300, 1447506600, 1447887950, 1448269350, 1448650800, 1449032300, 1449413850, 1449795450, 1450177100, 1450558800, 1450940550, 1451322350, 1451704200, 1452086100, 1452468050, 1452850050, 1453232100, 1453614200, 1453996350, 1454378550, 1454760800, 1455143100, 1455525450, 1455907850, 1456290300, 1456672800, 1457055350, 1457437950, 1457820600, 1458203300, 1458586050, 1458968850, 1459351700, 1459734600, 1460117550, 1460500550, 1460883600, 1461266700, 1461649850, 1462033050, 1462416300, 1462799600, 1463182950, 1463566350, 1463949800, 1464333300, 1464716850, 1465100450, 1465484100, 1465867800, 1466251550, 1466635350, 1467019200, 1467403100, 1467787050, 1468171050, 1468555100, 1468939200, 1469323350, 1469707550, 1470091800, 1470476100, 1470860450, 1471244850, 1471629300, 1472013800, 1472398350, 1472782950, 1473167600, 1473552300, 1473937050, 1474321850, 1474706700, 1475091600, 1475476550, 1475861550, 1476246600, 1476631700, 1477016850, 1477402050, 1477787300, 1478172600, 1478557950, 1478943350, 1479328800, 1479714300, 1480099850, 1480485450, 1480871100, 1481256800, 1481642550, 1482028350, 1482414200, 1482800100, 1483186050, 1483572050, 1483958100, 1484344200, 1484730350, 1485116550, 1485502800, 1485889100, 1486275450, 1486661850, 1487048300, 1487434800, 1487821350, 1488207950, 1488594600, 1488981300, 1489368050, 1489754850, 1490141700, 1490528600, 1490915550, 1491302550, 1491689600, 1492076700, 1492463850, 1492851050, 1493238300, 1493625600, 1494012950, 1494400350, 1494787800, 1495175300, 1495562850, 1495950450, 1496338100, 1496725800, 1497113550, 1497501350, 1497889200, 1498277100, 1498665050, 1499053050, 1499441100, 1499829200, 1500217350, 1500605550, 1500993800, 1501382100, 1501770450, 1502158850, 1502547300, 1502935800, 1503324350, 1503712950, 1504101600, 1504490300, 1504879050, 1505267850, 1505656700, 1506045600, 1506434550, 1506823550, 1507212600, 1507601700, 1507990850, 1508380050, 1508769300, 1509158600, 1509547950, 1509937350, 1510326800, 1510716300, 1511105850, 1511495450, 1511885100, 1512274800, 1512664550, 1513054350, 1513444200, 1513834100, 1514224050, 1514614050, 1515004100, 1515394200, 1515784350, 1516174550, 1516564800, 1516955100, 1517345450, 1517735850, 1518126300, 1518516800, 1518907350, 1519297950, 1519688600, 1520079300, 1520470050, 1520860850, 1521251700, 1521642600, 1522033550, 1522424550, 1522815600, 1523206700, 1523597850, 1523989050, 1524380300, 1524771600, 1525162950, 1525554350, 1525945800, 1526337300, 1526728850, 1527120450, 1527512100, 1527903800, 1528295550, 1528687350, 1529079200, 1529471100, 1529863050, 1530255050, 1530647100, 1531039200, 1531431350, 1531823550, 1532215800, 1532608100, 1533000450, 1533392850, 1533785300, 1534177800, 1534570350, 1534962950, 1535355600, 1535748300, 1536141050, 1536533850, 1536926700, 1537319600, 1537712550, 1538105550, 1538498600, 1538891700, 1539284850, 1539678050, 1540071300, 1540464600, 1540857950, 1541251350, 1541644800, 1542038300, 1542431850, 1542825450, 1543219100, 1543612800, 1544006550, 1544400350, 1544794200, 1545188100, 1545582050, 1545976050, 1546370100, 1546764200, 1547158350, 1547552550, 1547946800, 1548341100, 1548735450, 1549129850, 1549524300, 1549918800, 1550313350, 1550707950, 1551102600, 1551497300, 1551892050, 1552286850, 1552681700, 1553076600, 1553471550, 1553866550, 1554261600, 1554656700, 1555051850, 1555447050, 1555842300, 1556237600, 1556632950, 1557028350, 1557423800, 1557819300, 1558214850, 1558610450, 1559006100, 1559401800, 1559797550, 1560193350, 1560589200, 1560985100, 1561381050, 1561777050, 1562173100, 1562569200, 1562965350, 1563361550, 1563757800, 1564154100, 1564550450, 1564946850, 1565343300, 1565739800, 1566136350, 1566532950, 1566929600, 1567326300, 1567723050, 1568119850, 1568516700, 1568913600, 1569310550, 1569707550, 1570104600, 1570501700, 1570898850, 1571296050, 1571693300, 1572090600, 1572487950, 1572885350, 1573282800, 1573680300, 1574077850, 1574475450, 1574873100, 1575270800, 1575668550, 1576066350, 1576464200, 1576862100, 1577260050, 1577658050, 1578056100, 1578454200, 1578852350, 1579250550, 1579648800, 1580047100, 1580445450, 1580843850, 1581242300, 1581640800, 1582039350, 1582437950, 1582836600, 1583235300, 1583634050, 1584032850, 1584431700, 1584830600, 1585229550, 1585628550, 1586027600, 1586426700, 1586825850, 1587225050, 1587624300, 1588023600, 1588422950, 1588822350, 1589221800, 1589621300, 1590020850, 1590420450, 1590820100, 1591219800, 1591619550, 1592019350, 1592419200, 1592819100, 1593219050, 1593619050, 1594019100, 1594419200, 1594819350, 1595219550, 1595619800, 1596020100, 1596420450, 1596820850, 1597221300, 1597621800, 1598022350, 1598422950, 1598823600, 1599224300, 1599625050, 1600025850, 1600426700, 1600827600, 1601228550, 1601629550, 1602030600, 1602431700, 1602832850, 1603234050, 1603635300, 1604036600, 1604437950, 1604839350, 1605240800, 1605642300, 1606043850, 1606445450, 1606847100, 1607248800, 1607650550, 1608052350, 1608454200, 1608856100, 1609258050, 1609660050, 1610062100, 1610464200, 1610866350, 1611268550, 1611670800, 1612073100, 1612475450, 1612877850, 1613280300, 1613682800, 1614085350, 1614487950, 1614890600, 1615293300, 1615696050, 1616098850, 1616501700, 1616904600, 1617307550, 1617710550, 1618113600, 1618516700, 1618919850, 1619323050, 1619726300, 1620129600, 1620532950, 1620936350, 1621339800, 1621743300, 1622146850, 1622550450, 1622954100, 1623357800, 1623761550, 1624165350, 1624569200, 1624973100, 1625377050, 1625781050, 1626185100, 1626589200, 1626993350, 1627397550, 1627801800, 1628206100, 1628610450, 1629014850, 1629419300, 1629823800, 1630228350, 1630632950, 1631037600, 1631442300, 1631847050, 1632251850, 1632656700, 1633061600, 1633466550, 1633871550, 1634276600, 1634681700, 1635086850, 1635492050, 1635897300, 1636302600, 1636707950, 1637113350, 1637518800, 1637924300, 1638329850, 1638735450, 1639141100, 1639546800, 1639952550, 1640358350, 1640764200, 1641170100, 1641576050, 1641982050, 1642388100, 1642794200, 1643200350, 1643606550, 1644012800, 1644419100, 1644825450, 1645231850, 1645638300, 1646044800, 1646451350, 1646857950, 1647264600, 1647671300, 1648078050, 1648484850, 1648891700, 1649298600, 1649705550, 1650112550, 1650519600, 1650926700, 1651333850, 1651741050, 1652148300, 1652555600, 1652962950, 1653370350, 1653777800, 1654185300, 1654592850, 1655000450, 1655408100, 1655815800, 1656223550, 1656631350, 1657039200, 1657447100, 1657855050, 1658263050, 1658671100, 1659079200, 1659487350, 1659895550, 1660303800, 1660712100, 1661120450, 1661528850, 1661937300, 1662345800, 1662754350, 1663162950, 1663571600, 1663980300, 1664389050, 1664797850, 1665206700, 1665615600, 1666024550, 1666433550, 1666842600, 1667251700, 1667660850, 1668070050, 1668479300, 1668888600, 1669297950, 1669707350, 1670116800, 1670526300, 1670935850, 1671345450, 1671755100, 1672164800, 1672574550, 1672984350, 1673394200, 1673804100, 1674214050, 1674624050, 1675034100, 1675444200, 1675854350, 1676264550, 1676674800, 1677085100, 1677495450, 1677905850, 1678316300, 1678726800, 1679137350, 1679547950, 1679958600, 1680369300, 1680780050, 1681190850, 1681601700, 1682012600, 1682423550, 1682834550, 1683245600, 1683656700, 1684067850, 1684479050, 1684890300, 1685301600, 1685712950, 1686124350, 1686535800, 1686947300, 1687358850, 1687770450, 1688182100, 1688593800, 1689005550, 1689417350, 1689829200, 1690241100, 1690653050, 1691065050, 1691477100, 1691889200, 1692301350, 1692713550, 1693125800, 1693538100, 1693950450, 1694362850, 1694775300, 1695187800, 1695600350, 1696012950, 1696425600, 1696838300, 1697251050, 1697663850, 1698076700, 1698489600, 1698902550, 1699315550, 1699728600, 1700141700, 1700554850, 1700968050, 1701381300, 1701794600, 1702207950, 1702621350, 1703034800, 1703448300, 1703861850, 1704275450, 1704689100, 1705102800, 1705516550, 1705930350, 1706344200, 1706758100, 1707172050, 1707586050, 1708000100, 1708414200, 1708828350, 1709242550, 1709656800, 1710071100, 1710485450, 1710899850, 1711314300, 1711728800, 1712143350, 1712557950, 1712972600, 1713387300, 1713802050, 1714216850, 1714631700, 1715046600, 1715461550, 1715876550, 1716291600, 1716706700, 1717121850, 1717537050, 1717952300, 1718367600, 1718782950, 1719198350, 1719613800, 1720029300, 1720444850, 1720860450, 1721276100, 1721691800, 1722107550, 1722523350, 1722939200, 1723355100, 1723771050, 1724187050, 1724603100, 1725019200, 1725435350, 1725851550, 1726267800, 1726684100, 1727100450, 1727516850, 1727933300, 1728349800, 1728766350, 1729182950, 1729599600, 1730016300, 1730433050, 1730849850, 1731266700, 1731683600, 1732100550, 1732517550, 1732934600, 1733351700, 1733768850, 1734186050, 1734603300, 1735020600, 1735437950, 1735855350, 1736272800, 1736690300, 1737107850, 1737525450, 1737943100, 1738360800, 1738778550, 1739196350, 1739614200, 1740032100, 1740450050, 1740868050, 1741286100, 1741704200, 1742122350, 1742540550, 1742958800, 1743377100, 1743795450, 1744213850, 1744632300, 1745050800, 1745469350, 1745887950, 1746306600, 1746725300, 1747144050, 1747562850, 1747981700, 1748400600, 1748819550, 1749238550, 1749657600, 1750076700, 1750495850, 1750915050, 1751334300, 1751753600, 1752172950, 1752592350, 1753011800, 1753431300, 1753850850, 1754270450, 1754690100, 1755109800, 1755529550, 1755949350, 1756369200, 1756789100, 1757209050, 1757629050, 1758049100, 1758469200, 1758889350, 1759309550, 1759729800, 1760150100, 1760570450, 1760990850, 1761411300, 1761831800, 1762252350, 1762672950, 1763093600, 1763514300, 1763935050, 1764355850, 1764776700, 1765197600, 1765618550, 1766039550, 1766460600, 1766881700, 1767302850, 1767724050, 1768145300, 1768566600, 1768987950, 1769409350, 1769830800, 1770252300, 1770673850, 1771095450, 1771517100, 1771938800, 1772360550, 1772782350, 1773204200, 1773626100, 1774048050, 1774470050, 1774892100, 1775314200, 1775736350, 1776158550, 1776580800, 1777003100, 1777425450, 1777847850, 1778270300, 1778692800, 1779115350, 1779537950, 1779960600, 1780383300, 1780806050, 1781228850, 1781651700, 1782074600, 1782497550, 1782920550, 1783343600, 1783766700, 1784189850, 1784613050, 1785036300, 1785459600, 1785882950, 1786306350, 1786729800, 1787153300, 1787576850 };



//Self Money Drop
bool Features::savenewdrop = false;
void Features::cashdrop(bool toggle) {


	Ped iPed = PLAYER::PLAYER_PED_ID();

	int amount = 39999;

	if ((timeGetTime() - Features::TimePD1) > 400) // Time between drops
	{
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_01);
		if (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_01)) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(PICKUP_MONEY_CASE, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f, 0, amount, PROP_MONEY_BAG_01, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_01);

			Features::TimePD1 = timeGetTime();

		}
	}

}





bool Features::savenewdrop21 = false;
void Features::cashdrop21(bool toggle)
{
	if (toggle = true)
	{
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_01);
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Features::Online::selectedPlayer, 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);

		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_01);
		while (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_01))
			if (STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_01))
			{
				int amount = 2000;
				OBJECT::pockup(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, PROP_MONEY_BAG_01, false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_01);
			}
	}
}
bool Features::rainself = false;
void Features::Rainself(bool toggle)
{
	if (toggle = true)
	{
		Ped iPed = PLAYER::PLAYER_PED_ID();
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_01);
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(iPed, 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);

		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_01);
		while (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_01))
			if (STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_01))
			{
				int amount = 2000;
				OBJECT::pockup(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, PROP_MONEY_BAG_01, false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_01);
			}
	}
}
bool Features::savenewdrop3 = false;
void Features::cashdrop3(bool toggle)
{

	Ped iPed = PLAYER::PLAYER_PED_ID();

	int amount = 2500; //i have test it but not working

	if ((timeGetTime() - Features::TimePD1) > 400) // Time between drops
	{
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
		if (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02)) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(PICKUP_MONEY_CASE, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f, 0, amount, PROP_MONEY_BAG_02, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);

			Features::TimePD1 = timeGetTime();
		}
	}
}

//Money Drop Other Players 2.5k
bool Features::savenewdrop31 = false;
void Features::cashdrop31(bool toggle)
{

	if ((timeGetTime() - Features::TimePD2) > 400) // Time between drops
	{


		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_acc_guitar_01"));
		if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_acc_guitar_01"))) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f / 10, 0, 2000, GAMEPLAY::GET_HASH_KEY("prop_acc_guitar_01"), FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_acc_guitar_01"));
		}

		Features::TimePD2 = timeGetTime();

	}
}
int Features::rt = 255;
int Features::rrt = 255;
int Features::rrrt = 255;


//Money Drop Other Players 2.5k
bool Features::savenewdrop7 = false;
void Features::cashdrop7(bool toggle)
{

	if ((timeGetTime() - Features::TimePD2) > 400) // Time between drops
	{


		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"));
		if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"))) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f / 10, 0, 200, GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"), FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"));
		}

		Features::TimePD2 = timeGetTime();

	}
}

//Money Drop Other Players 2.5k
bool Features::savenewdrop6 = false;
void Features::cashdrop6(bool toggle)
{

	if ((timeGetTime() - Features::TimePD2) > 400) // Time between drops
	{


		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"))) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f / 10, 0, 2000, GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"), FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		}

		Features::TimePD2 = timeGetTime();

	}
}

//Money Drop Other Players 2.5k
bool Features::savenewdrop5 = false;
void Features::cashdrop5(bool toggle)
{

	if ((timeGetTime() - Features::TimePD2) > 400) // Time between drops
	{

		int amount = 2500;
		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
		if (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02)) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(PICKUP_MONEY_CASE, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f, 0, amount, PROP_MONEY_BAG_02, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
		}

		Features::TimePD2 = timeGetTime();

	}
}

bool Features::GravGun = false;

void GET_CAMERA_DIRECTION(float *dirX, float *dirY, float *dirZ)
{
	float tX, tZ, num;
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);

	tZ = rot.z * 0.0174532924f;
	tX = rot.x * 0.0174532924f;
	num = abs(cos(tX));

	*dirX = (-sin(tZ)) * num;
	*dirY = (cos(tZ)) * num;
	*dirZ = sin(tX);
}

int entdistance = 4;
bool disallowNewEntity;
Entity gravityentity;
Entity shotentity;
Vehicle gravityvehicle;
bool grav_target_locked;

void Features::GravGunFunction() {
	Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 5;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	Player tempPed = PLAYER::PLAYER_ID();
	if (grav_target_locked)
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
		{
			Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
			if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
			{
				EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
			}

			RequestControlOfEnt(EntityTarget);

			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
				ENTITY::SET_ENTITY_HEADING(
					EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", EntityTarget, "docks_heist_finale_2a_sounds", 0, 0);
				ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
					0.0f, 0, 0, 1, 1, 0, 1);
				grav_target_locked = false;
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
			}
		}
	}
	if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{
		grav_target_locked = true;
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
	}
}

bool Features::tpp = false;
void Features::Teleportprotec(bool toggle)
{
	globalHandle(1382674).At(499).As<bool>() = toggle;
}

bool Features::savenewdrop4 = false;
void Features::cashdrop4(bool toggle)
{
	if (toggle = true)
	{
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Features::Online::selectedPlayer, 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);


		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
		while (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
			WAIT(0);
		if (STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
		{
			int amount = 2500;
			OBJECT::pockup(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, PROP_MONEY_BAG_02, false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
		}
	}
}

bool Features::phonedisable = false; 
void Features::disablephone() {
	MOBILE::DESTROY_MOBILE_PHONE();
}

bool Features::CeoBanProtection;
void Features::CEOBanp(bool toggle)
{
	globalHandle(1382674).At(558).As<bool>() = 558;
}

bool Features::SendToJobProtection;
void Features::STJp(bool toggle)
{
	globalHandle(1382674).At(295).As<bool>() = 295;
}

bool Features::rain2 = false;
void Features::Rain2(bool toggle)
{
	if (toggle = true)
	{

		Ped iPed = PLAYER::PLAYER_PED_ID();
		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
		Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(iPed, 0.0, 0.0, 10.0);
		int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
		int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);


		STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
		while (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
			WAIT(0);
		if (STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
		{
			int amount = 2500;
			OBJECT::pockup(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, PROP_MONEY_BAG_02, false, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
		}
	}
}

bool Features::RPLoop = false;
int Features::RPLoopDelay = 5;
int Rptick2 = 0;
int Rptick = 0;
void Features::rpLoop(bool toggle) {
	if (Features::RPLoop)
	{
		Rptick++;
		if (Rptick > Features::RPLoopDelay) {
			Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 5);
			Rptick2++;
			if (Rptick2 > Features::RPLoopDelay) {
				Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, 0);
				Rptick = 0;
				Rptick2 = 0;
			}
		}
	}
	else
	{
		Memory::set_value<int>({ (2 * 4 * 2) / 2, 4 * 1000 + 280, 500 * 4 - 70 + 70 + 72 }, false);

	}
}




void Features::StealthDrop(int amount)
{
	Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
	UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 312105838, 1445302971, amount, 1);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
}

void Features::MoneyDelete(bool toggle)
{
	Any id = 0;
	UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&id, 0x57DE404E, 0x129A5B6E, 0x562592BB, 10000000 - amount, true ? 4 : 1);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(id);
}

void Features::StealthDrop2(int amount) {
	Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
	UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 312105838, 1445302971, amount, 4);
	UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
}

bool Features::StealthLooptoggle = false;
void Features::StealthLoop(bool toggle) {
	if ((timeGetTime() - Features::TimePD3) > 500)
	{
		Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 312105838, 1445302971, 10000000, 1);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);

		Features::TimePD3 = timeGetTime();
	}
}

bool Features::DeleteVehicle = false;
void Features::Deletevehicle(bool toggle) {
	if (DeleteVehicle)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, false))
		{
			int Vehicle = PED::GET_VEHICLE_PED_IS_USING(playerPed);
			if (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle))
				while (!NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle));

			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, 1, 1);
			VEHICLE::DELETE_VEHICLE(&Vehicle);
		}
		
	}
}

bool Features::StealthLooptoggle2 = false;
void Features::StealthLoop2(bool toggle) {
	if ((timeGetTime() - Features::TimePD4) > 500)
	{
		Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 312105838, 1445302971, 10000000, 4);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
		Features::TimePD4 = timeGetTime();
	}
}

int Features::attachobj[100];
int Features::nuattach = 1;
void Features::attachobjects2(char* object)
{
	bool custom = false;
	int hash = 0;
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), true);
	hash = GAMEPLAY::GET_HASH_KEY(object);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
	{
		if (STREAMING::IS_MODEL_VALID(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
			if (STREAMING::HAS_MODEL_LOADED(hash))
			{
				Features::attachobj[Features::nuattach] = OBJECT::CREATE_OBJECT(hash, pos.x, pos.y, pos.z, 1, 1, 1);
				if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj[Features::nuattach]))
				{
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Features::attachobj[Features::nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
					nuattach++;
					if (nuattach >= 101) { nuattach = 1; }
				}
			}
		}
	}
}


//int Features::testweh1 = 200;
//bool Features::okokoko = false;
//void Features::fearureqeq(bool toggle)
//{
//
//	if (toggle)
//	{
//		Ped playerped = PLAYER::PLAYER_PED_ID();
//		Player kek = PLAYER::GET_VEHICLE_MODEL_WIDTH(playerped, 0, 0);
//		PLAYER::SET_VEHICLE_MODEL_WIDTH(kek, Features::testweh1);
//
//	}
//	while (toggle = FALSE)
//	{
//
//		Ped playerped = PLAYER::PLAYER_PED_ID();
//		Player kek1 = PLAYER::GET_VEHICLE_MODEL_HEIGHT(playerped, 0, 0);
//		PLAYER::SET_VEHICLE_MODEL_HEIGHT(kek1, Features::testweh1);
//
//
//	}
//}

bool RequestNetworkControl(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}

void Features::DeleteEntity(int Handle)
{
	RequestNetworkControl(Handle);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Handle, 1, 1);
	ENTITY::DELETE_ENTITY(&Handle);
}

bool Features::bikeNoFall = false;
void Features::nofallbike() {
	PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), bikeNoFall);
}

bool Features::dowbool = false;
void Features::DriveOnWater() {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float height = 0;
	WATER::_SET_CURRENT_INTENSITY(height);
	if ((!(VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) {
			Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, 0, 0, 0, 1);
			ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
			Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, 1);
			if (pos.z < containerCoords.z) {
				if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
					ENTITY::SET_ENTITY_COORDS(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
				else {
					RequestControlOfEnt(veh);
					Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, 1);
					ENTITY::SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
			}
		}
		else {
			Hash model = GAMEPLAY::GET_HASH_KEY("prop_container_ld2");
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model))
				container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
			RequestControlOfEnt(container);
			ENTITY::FREEZE_ENTITY_POSITION(container, 1);
			ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
			ENTITY::SET_ENTITY_VISIBLE(container, 0, 0);
		}
	}
	else {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
			WAIT(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::_RESET_CURRENT_INTENSITY();
		}
	}
}




bool Features::boostbool = false;
void Features::carboost(bool toggle) {
	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
	{

		Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
		GRAPHICS::_START_SCREEN_EFFECT("RaceTurbo", 0, 0);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, Features::Horndelay);
		}
	}
}

int Features::attachobj22[100];
int Features::nuattach22 = 1;
void Features::attachobjects222(char* object)
{
	for (int i = 0; i < 32; i++)
	{
		int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
		{

			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			bool custom = false;
			int hash = 0;
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			hash = GAMEPLAY::GET_HASH_KEY(object);
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
			{
				if (STREAMING::IS_MODEL_VALID(hash))
				{
					STREAMING::REQUEST_MODEL(hash);
					if (STREAMING::HAS_MODEL_LOADED(hash))
					{
						Features::attachobj[Features::nuattach] = OBJECT::CREATE_OBJECT(hash, playerPosition.x, playerPosition.y, playerPosition.z, 1, 1, 1);
						if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj[Features::nuattach]))
						{
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Features::attachobj[Features::nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 31086, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
							nuattach++;
							if (nuattach22 >= 101) { nuattach = 1; }
						}
					}
				}

			}
		}
	}
}

bool Features::fixfire = false;
void Features::firefix(bool toggle)
{
	if (fixfire)
	{
		if (IsPedShooting(PLAYER::PLAYER_PED_ID())) {
			float Tmp[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), (Vector3*)Tmp);
			if (Tmp[0] != 0 || Tmp[2] != 0 || Tmp[4] != 0)
			{
				FIRE::ADD_EXPLOSION(Tmp[0], Tmp[2], Tmp[4], 3, 0, true, false, 0);
			}
		}
	}
}

bool Features::Explodegunn = false;
void Features::explodegunn(bool toggle)
{
	if (Explodegunn)
	{
		if (IsPedShooting(PLAYER::PLAYER_PED_ID())) {
			float Tmp[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), (Vector3*)Tmp);
			if (Tmp[0] != 0 || Tmp[2] != 0 || Tmp[4] != 0)
			{
				FIRE::ADD_EXPLOSION(Tmp[0], Tmp[2], Tmp[4], Features::Explosionfick, Features::ficksize, true, false, 0);
			}
		}
	}
}



bool Features::ChaosMode = false;
void Features::Chaos(bool toggle)
{
	const int numElements = 15;
	const int arrSize = numElements * 2 + 2;
	Ped peds[arrSize];
	peds[0] = numElements;
	int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

	// Nearby Peds
	for (int i = 0; i < count; ++i)
	{
		int offsettedID = i * 2 + 2;
		if (ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]) && peds[offsettedID] != PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX()))
		{
			ENTITY::SET_ENTITY_HAS_GRAVITY(peds[offsettedID], false);
			Vector3 velocity = ENTITY::GET_ENTITY_VELOCITY(peds[offsettedID]);
			velocity.z = 2.f;
			if (ENTITY::IS_ENTITY_A_PED(peds[offsettedID]) && !PED::IS_PED_RAGDOLL(peds[offsettedID]))
			{
				PED::SET_PED_TO_RAGDOLL(peds[offsettedID], 2000, 0, 2, false, false, false);
				velocity.z = 5.f;
				ENTITY::APPLY_FORCE_TO_ENTITY(peds[offsettedID], 1, 0, 0, ENTITY::IS_ENTITY_A_PED(peds[offsettedID]) ? 10.f : 5.f, 0, 0, 0, 1, 1, 1, 1, 1, 1);
			}
			ENTITY::SET_ENTITY_VELOCITY(peds[offsettedID], velocity.x, velocity.y, velocity.z);
		}
	}

	// Nearby Vehicles
	const int numElements2 = 15;
	const int arrSize2 = numElements2 * 2 + 2;
	Vehicle veh[arrSize2];
	veh[0] = numElements2;
	int count2 = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		for (int i = 0; i < count2; i++)
		{
			int offsettedID = i * 2 + 2;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]) && veh[offsettedID] != PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::GET_PLAYER_INDEX())))
			{
				ENTITY::SET_ENTITY_HAS_GRAVITY(veh[offsettedID], false);
				Vector3 velocity = ENTITY::GET_ENTITY_VELOCITY(veh[offsettedID]);
				velocity.z = 2.f;
				ENTITY::SET_ENTITY_VELOCITY(veh[offsettedID], velocity.x, velocity.y, velocity.z);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, ENTITY::IS_ENTITY_A_PED(veh[offsettedID]) ? 10.f : 5.f, 0, 0, 0, 1, 1, 1, 1, 1, 1);
			}
		}
	}

}

bool Features::Drift = false;
void Features::DriftMode(bool toggle)
{
	if (toggle == true)
	{
		VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1);
	}
	else {
		VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);
	}
	
}

bool Features::progen = false;
void Features::bribeAuthorities(bool toggle)
{
	if (toggle)
	{
		Player target = Features::Online::selectedPlayer;

		int time = NETWORK::GET_NETWORK_TIME();
		int handle = globalHandle(1625435).At(target, 560).At(491).As<int>();
		int handle1 = globalHandle(2524719).At(4545).As<int>();
		DWORD64 args[7] = { 1555129594, target, handle1, 0, time, 0, handle };
		SCRIPT::eventur(1, args, 7, 1 << target);
	}
}

//bool Features::dowbool = false;
void Features::DriveOnWater(bool toggle) {
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
	float height = 0;
	WATER::_SET_WAVES_INTENSITY(height);
	if ((!(VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(veh)))) && WATER::GET_WATER_HEIGHT_NO_WAVES(pos.x, pos.y, pos.z, &height)) {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container) && height > -50.0f) {
			Vector3 pRot = ENTITY::GET_ENTITY_ROTATION(playerPed, 0);
			if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 1)) pRot = ENTITY::GET_ENTITY_ROTATION(veh, 0);
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, pos.x, pos.y, height - 1.5f, 0, 0, 0, 1);
			ENTITY::SET_ENTITY_ROTATION(container, 0, 0, pRot.z, 0, 1);
			Vector3 containerCoords = ENTITY::GET_ENTITY_COORDS(container, 1);
			if (pos.z < containerCoords.z) {
				if (!PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
					ENTITY::SET_ENTITY_COORDS(playerPed, pos.x, pos.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
				else {
					RequestControlOfEnt(veh);
					Vector3 vehc = ENTITY::GET_ENTITY_COORDS(veh, 1);
					ENTITY::SET_ENTITY_COORDS(veh, vehc.x, vehc.y, containerCoords.z + 2.0f, 0, 0, 0, 1);
				}
			}
		}
		else {
			Hash model = GAMEPLAY::GET_HASH_KEY("prop_container_ld2");
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
			container = OBJECT::CREATE_OBJECT(model, pos.x, pos.y, pos.z, 1, 1, 0);
			RequestControlOfEnt(container);
			ENTITY::FREEZE_ENTITY_POSITION(container, 1);
			ENTITY::SET_ENTITY_ALPHA(container, 0, 1);
			ENTITY::SET_ENTITY_VISIBLE(container, 0, 0);
		}
	}
	else {
		Object container = OBJECT::GET_CLOSEST_OBJECT_OF_TYPE(pos.x, pos.y, pos.z, 4.0, GAMEPLAY::GET_HASH_KEY("prop_container_ld2"), 0, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, 0, 0, -1000.0f, 0, 0, 0, 1);
			WAIT(10);
			ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&container);
			ENTITY::DELETE_ENTITY(&container);
			WATER::_RESET_WAVES_INTENSITY();
		}
	}
}
bool Features::moneyDropProtection = false;

int Features::WaterIntense = 1;


bool Features::CLOWNGUN = false;
void Features::clowngun(bool toggle)
{
	if (IsPedShooting(PLAYER::PLAYER_PED_ID())) {
		STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
		while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("scr_rcbarry2")) WAIT(0);

		auto w = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(WEAPON::GET_SELECTED_PED_WEAPON(PLAYER::PLAYER_PED_ID()), &v0, &v1);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2");
		GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2("muz_clown", w, (v0.x - v1.x) / 2.0f + 0.7f, 0.f, 0.f, 0.f, 180.f, 0.f, 1.f, 1, 1, 1);
	}
}

bool Features::delop = false;
void Features::lolop(bool toggle)
{

	if ((timeGetTime() - Features::TimePD1) > 1000)
	{

		Ped iPed = PLAYER::PLAYER_PED_ID();

		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"))) {
			WAIT(0);
		}
		else {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE); // which method? moneybag prop on object spawn
			OBJECT::pockup(0xDE78F17E, pos.x, pos.y, pos.z + 20.0f / 10, 0, 0, GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"), FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		}

		Features::TimePD1 = timeGetTime();

	}

	if ((timeGetTime() - Features::TimePD5) > 1000) { // Delay
		Any var0 = 0ul;
		int var3 = 312105838;
		int bankVal = false ? 4 : 1;
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, 8000000, bankVal);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

		Features::TimePD5 = timeGetTime();

		int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1); notifyMap("~b~Click Numpad9!");


	}


}
static void addOwnedExplosion(Ped ped, float x, float y, float z, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake)
{
	auto nword = Memory::pattern("F3 0F 11 45 ? F3 0F 11 55 ? 89 5C 24 30 4C 89 75 9F 4C 89 75 AF 44 89 75 B7 48 C7 45").count(1).get(0).get<char>(120);
	nword += *reinterpret_cast<std::int32_t*>(nword);
	nword += sizeof(std::int32_t);

	*nword = 1;
	invoke<Void>(0x172AA1B624FA1013, ped, x, y, z, explosionType, damageScale, isAudible, isInvisible, cameraShake);
	*nword = 0;
}

void blame()
{
	Player player = Features::Online::selectedPlayer;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player);
	Player local = PLAYER::PLAYER_ID();

	for (int i = 0; i < 32; ++i)
	{
		if (i != local && i != player)
		{
			auto pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), true);
			addOwnedExplosion(ped, pos.x, pos.y, pos.z, 29, 20.f, true, false, 5.f);
		}
	}

}

bool Features::delopp = false;
void Features::lolopp(bool toggle)
{

	if ((timeGetTime() - Features::TimePD1) > 1000)
	{

		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"))) {
			WAIT(0);
		}
		else {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE); // which method? moneybag prop on object spawn
			OBJECT::pockup(0xDE78F17E, pos.x, pos.y, pos.z + 20.0f / 10, 0, 0, GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"), FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
		}

		Features::TimePD1 = timeGetTime();

	}

	if ((timeGetTime() - Features::TimePD5) > 1000) { // Delay
		Any var0 = 0ul;
		int var3 = 312105838;
		int bankVal = false ? 4 : 1;
		UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&var0, 1474183246, var3, 1445302971, 8000000, bankVal);
		UNK3::_NETWORK_SHOP_CHECKOUT_START(var0);

		Features::TimePD5 = timeGetTime();

		int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1); notifyMap("~b~Click Numpad9!");


	}


}

bool Features::fcbool = false;
void Features::FlyingCarLoop(bool toggle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		int Vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::APPLY_FORCE_TO_ENTITY(Vehid, 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);
		if (CONTROLS::IS_CONTROL_PRESSED(2, 67) == true) //Forward
		{
			float Speed = ENTITY::GET_ENTITY_SPEED(Vehid) + 0.5;
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(Vehid, 25);

		}

		if ((CONTROLS::IS_CONTROL_PRESSED(2, 196) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Left
		{
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			Rot.z = Rot.z + 1.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
		}

		if ((CONTROLS::IS_CONTROL_PRESSED(2, 197) == true) && (!VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Vehid))) //Right
		{
			Vector3 Rot = ENTITY::GET_ENTITY_ROTATION(Vehid, 2);
			Rot.z = Rot.z - 1.0;
			ENTITY::SET_ENTITY_ROTATION(Vehid, Rot.x, Rot.y, Rot.z, 2, 1);
		}
	}
}

bool Features::isInfBoost = false;
void Features::InfiniteBoost(bool toggle) {
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, 0x320 }, 6.f);
}
void Features::AmmoDrop()
{
	globalHandle(2519572).At(822).As<int>() = 1;
}

void Features::noreloadv(bool toggle) {
	Hash cur;
	if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &cur, 1))
	{
		if (WEAPON::IS_WEAPON_VALID(cur))
		{
			int maxAmmo;
			if (WEAPON::GET_MAX_AMMO(PLAYER::PLAYER_PED_ID(), cur, &maxAmmo))
			{
				WEAPON::SET_PED_AMMO(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);

				maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, 1);
				if (maxAmmo > 0)
					WEAPON::SET_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);
			}
		}
	}
}



//bool Features::orbool = false;
//void Features::OffRadar(bool toggle)
//{
//	globalHandle(2423801).At(PLAYER::PLAYER_ID(), 413).At(200).As<int>() = 1;
//	globalHandle(2437022).At(70).As<int>() = NETWORK::GET_NETWORK_TIME();
//
//}

bool Features::orbooll = false;
void Features::OffRadarr(bool toggle)
{
	std::uint64_t args[7] = { 1344161996, Features::Online::selectedPlayer, NETWORK::GET_NETWORK_TIME() + (60000 * 59) + 1, NETWORK::GET_NETWORK_TIME(), 1, 1, globalHandle(1625435 + 1 + Features::Online::selectedPlayer * 560 + 491).As<std::uint64_t>() };
	SCRIPT::eventur(1, args, 7, 1 << Features::Online::selectedPlayer);

}

bool Features::ControlInfo = false;
void Features::Control(bool toggle)
{
	Menu::drawInstructions();
}

bool Features::moneyGunBagfakepl = false;
void Features::moneyGunBagfakeplall(bool toggle) {
	auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	if (IsPedShooting(ped))
	{
		Vector3 pos;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(ped, &pos))
		{
			OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"), pos.x, pos.y, pos.z, true, 1, 0);
		}
	}
}

int Features::rbr = 255;
int Features::rbd = 255;
int Features::rbs = 255;
bool Features::Color = false;
void Features::color(bool toggle)
{
	if ((timeGetTime() - Features::TimePD12) > 100) // Time between drops
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, Features::rbr, Features::rbd, Features::rbs);
		Features::TimePD5 = timeGetTime();
	}
}

int Features::rbrr = 255;
int Features::rbdd = 255;
int Features::rbss = 255;
bool Features::Colorr = false;
void Features::colorr(bool toggle)
{
	if ((timeGetTime() - Features::TimePD10) > 100) // Time between drops
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, Features::rbrr, Features::rbdd, Features::rbss);
		Features::TimePD5 = timeGetTime();
	}
}

bool Features::ride_container;
void Features::container_rider(bool toggle) {
	static Object container;
	auto selfVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 min, max;
	Vector3 cmin, cmax;
	Vector3 c = ENTITY::GET_ENTITY_COORDS(selfVeh, 1);

	GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(selfVeh), &min, &max);
	GAMEPLAY::GET_MODEL_DIMENSIONS($("prop_container_01a"), &cmin, &cmax);

	if (!PED::IS_PED_ON_ANY_BIKE(PLAYER::PLAYER_PED_ID())) {
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
			notifyBottom("~r~Container rider requires a bike.");
			return;
		}
	}

	if (!STREAMING::HAS_MODEL_LOADED($("prop_container_01a")))
		STREAMING::REQUEST_MODEL($("prop_container_01a"));

	if (!ENTITY::DOES_ENTITY_EXIST(container) || !VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(selfVeh)) {
		static auto tickeer = GetTickCount();
		if ((GetTickCount() - tickeer) >= 1000) {
			if (CONTROLS::IS_CONTROL_PRESSED(2, INPUT_VEH_FLY_PITCH_UP_ONLY)) {
				tickeer = GetTickCount();
				ENTITY::APPLY_FORCE_TO_ENTITY(selfVeh, 0, 0, 0, 1.5, 0, 0, 0, 0, 1, 1, 1, 0, 1);
			}
		}
		static auto ticker = GetTickCount();
		if (ENTITY::DOES_ENTITY_EXIST(container)) {
			RequestControlOfEnt(container);
			ENTITY::SET_ENTITY_COORDS(container, 0.f, 0.f, 0.f, 1, 1, 1, 0);
			ENTITY::DELETE_ENTITY(&container);
			OBJECT::DELETE_OBJECT(&container);
		}
		container = OBJECT::CREATE_OBJECT($("prop_container_01a"), c.x, c.y, c.z - ((max.z / 2) + cmax.z), 1, 1, 0);
		ENTITY::SET_ENTITY_ROTATION(container, ENTITY::GET_ENTITY_PITCH(selfVeh), 0.f, ENTITY::GET_ENTITY_HEADING(selfVeh), 0, 0);
	}
}

int Features::rbrrr = 255;
int Features::rbddd = 255;
int Features::rbsss = 255;
bool Features::Colorrr = false;
void Features::colorrr(bool toggle)
{
	if ((timeGetTime() - Features::TimePD11) > 100) // Time between drops
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, Features::rbrrr, Features::rbddd, Features::rbsss);
		Features::TimePD5 = timeGetTime();
	}
}

bool Features::rlbool = false;
void Features::HasPaintLoop(bool toggle)
{
	if ((timeGetTime() - Features::TimePD5) > 100) // Time between drops
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		Features::TimePD5 = timeGetTime();
	}
}

bool Features::Bounty;
void Features::Bountyy(bool toggle)
{
	globalHandle(1382674).At(67).As<bool>() = toggle;

}

bool Features::SoundSpamProtection;
void Features::Spamp(bool toggle)
{
	globalHandle(1382674).At(33).As<bool>() = 33;
}

bool Features::Transaction;
void Features::Transaktion(bool toggle)
{
	auto unkKek1 = globalHandle(1624079 + 1 + Features::Online::selectedPlayer * 558 + 491).As<std::uint64_t>();
	auto unkKek2 = globalHandle(1641937 + 9).As<std::uint64_t>();
	std::uint64_t args[8] = {
		-1241703753,
		Features::Online::selectedPlayer,
		10000, // amount
		0,
		0,
		unkKek1, unkKek2, unkKek2
	};
	SCRIPT::eventur(1, args, 8, 1 << Features::Online::selectedPlayer);
}

bool Features::sounderrorall = false;
void Features::sound55errorall(bool toggle)
{

	for (int i = 0; i < 32; i++)
	{
		int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
		{

			auto unkKek1 = globalHandle(1625435 + 1 + i * 560 + 491).As<std::uint64_t>();
			auto unkKek2 = globalHandle(1643357 + 9).As<std::uint64_t>();
			std::uint64_t args[8] = {
				-1920290846,
				i,
				10000, // amount
				0,
				0,
				unkKek1, unkKek2, unkKek2
			};
			SCRIPT::eventur(1, args, 8, 1 << i);

		}

	}
}





bool Features::annupla = false;
char * Features::nu1 = "x";
char * Features::nu2 = "x";
char * Features::nu3 = "x";
char * Features::nu4 = "x";
bool Features::animatednum = false;
int aniloopnum = 1;
void Features::numbani(bool toggle) {

	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), nu1);
}

bool Features::mobileRadio = false;
void Features::mobilevoid(bool toggle) {
	if (mobilevoid)
	{
		Hooking::mobilerneger(mobileRadio);
	}

}



void Features::ramWithVeh(Player target)
{
	Hash model = $("trophytruck2");
	if (STREAMING::IS_MODEL_VALID(model))
	{
		for (int i = 0; i < 3; i++)
		{
			STREAMING::REQUEST_MODEL(model);
			while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
			Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
			float forward = 10.f;
			float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
			float xVector = forward * sin(degToRad(heading)) * -1.f;
			float yVector = forward * cos(degToRad(heading));
			Vehicle veh = VEHICLE::erstelle_fahr(model, ourCoords.x - xVector, ourCoords.y - yVector, ourCoords.z, heading, true, true);
			RequestControlOfEnt(veh);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 250);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
		}
	}
}

bool Features::sounderror[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::sound55error(Player target)
{
	auto unkKek1 = globalHandle(1625435 + 1 + Features::Online::selectedPlayer * 560 + 491).As<std::uint64_t>();
	auto unkKek2 = globalHandle(1643357 + 9).As<std::uint64_t>();
	std::uint64_t args[8] = {
		-1920290846,
		Features::Online::selectedPlayer,
		10000, // amount
		0,
		0,
		unkKek1, unkKek2, unkKek2
	};
	SCRIPT::eventur(1, args, 8, 1 << Features::Online::selectedPlayer);
}

bool Features::flybool = false;
void Features::playerflyer(bool toggle) {

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(playerPed, false);
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	if (GetAsyncKeyState(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 268)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x -= xVec, pos.y -= yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 269)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		float xVec = fivef * sin(degToRad(heading)) * -1.0f;
		float yVec = fivef * cos(degToRad(heading));
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.x += xVec, pos.y += yVec;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 266)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading + 0.5f);
	}
	if (GetAsyncKeyState(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, 271)) {
		float fivef = .5f;
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading - 0.5f);
	}
	if (GetAsyncKeyState(VK_SHIFT) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z -= 0.5;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}
	if (GetAsyncKeyState(VK_SPACE) || CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendLb)) {
		float heading = ENTITY::GET_ENTITY_HEADING(playerPed);
		ENTITY::SET_ENTITY_HEADING(playerPed, heading);

		pos.z += 0.5;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(playerPed, pos.x, pos.y, pos.z, false, false, false);
	}

}

//void Features::addBunkerBusinessProfit(int value)
//{
//	char* profit = *reinterpret_cast<char**>((char*)GetModuleHandleA(NULL) + 0x2C9EB78);
//	if (profit == nullptr)
//		profit = *reinterpret_cast<char**>((char*)GetModuleHandleA(NULL) + 0x2C995A8);
//	char* profit1 = *reinterpret_cast<char**>(profit + 0x1180);
//	int* bunkerProfit = reinterpret_cast<int*>(profit1 + 0x4088);
//	*bunkerProfit = value;
//}

void Features::RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void Features::RequestingControl(Entity e)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
	if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e))
		WAIT(0);
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(e);
}

void Features::playAnimationPlayer(Player player, bool loop, char * dict, char * anim)
{
	LoadAnim(dict);
	int a = -1;
	int b = 1;

	if (!loop)
	{
		a = 1;
		b = 0;
	}

	AI::TASK_PLAY_ANIM(player, dict, anim, 10000.0f, -1.5f, a, b, 0.445f, false, false, false);

}

void Features::animatePlayer(Player target, char* dict, char* anim)
{
	Ped targ_ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);//seleted player
	STREAMING::REQUEST_ANIM_DICT(dict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(targ_ped, 0.0, 0.0, 0.0);//since get_coord is patched i found this native
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 120, 0, 100, 0);/*i changed any to char* i provide the native below(modificated)*/
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);//will start the animation
	}
}

bool Features::cargodmodebool = false;
void Features::cargodmode()
{

	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
	{
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		ENTITY::SET_ENTITY_INVINCIBLE(vehicle, Features::cargodmodebool);
		ENTITY::SET_ENTITY_PROOFS(vehicle, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool, Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, false);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(vehicle, Features::cargodmodebool);
		VEHICLE::SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(vehicle, Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(vehicle, !Features::cargodmodebool);
		VEHICLE::SET_VEHICLE_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_DAMAGE(vehicle, 0.f, 0.f, 0.f, 0.f, 200.f, true);
		VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehicle);
		VEHICLE::SET_VEHICLE_ENVEFF_SCALE(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicle, 0.f);
		VEHICLE::SET_VEHICLE_BODY_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 1000.f);
		VEHICLE::SET_VEHICLE_PETROL_TANK_HEALTH(vehicle, 1000.f);
		if (VEHICLE::_IS_VEHICLE_DAMAGED(vehicle))
		{
			for (int i = 0; i < 10; i++)
			{
				try {
					VEHICLE::SET_VEHICLE_TYRE_FIXED(vehicle, i);
				}
				catch (...) {
					return;
				}
			}
		}
	}
}

bool Features::isCrouchPlayer = false;
void Features::crouchPlayer(bool toggle) {
	Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_INFO, 0x168 }, 5.f);
}

bool Features::enginealwaysonbool = false;
void Features::enginealwayson(bool toggle)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	VEHICLE::SET_VEHICLE_ENGINE_ON(veh, Features::enginealwaysonbool, Features::enginealwaysonbool, Features::enginealwaysonbool);
	VEHICLE::SET_VEHICLE_LIGHTS(veh, 0);
	VEHICLE::_SET_VEHICLE_LIGHTS_MODE(veh, 2);
}

bool Features::new1 = false;
void Features::new11(bool toggle)
{
	globalHandle(1382674).At(2).As<int>() = 2;
}

bool Features::new2 = false;
void Features::new22(bool toggle)
{
	globalHandle(1382674).At(61).As<int>() = 61;
}

bool Features::new3 = false;
void Features::new33(bool toggle)
{
	globalHandle(1382674).At(0).As<int>() = 0;
}

bool Features::kickp = false;
void Features::Kickprotec(bool toggle)
{
	globalHandle(1382674).At(609).As<int>() = 609;
}


void Features::flipup()
{
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
}

void Features::repairnearbyvehicles()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			for (int i = 0; i < 50; i++)
			{
				VEHICLE::SET_VEHICLE_FIXED(vehs[OffsetID]);
				VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(vehs[OffsetID]);
				VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehs[OffsetID], 0);
			}

		}
	}
}
int Features::offradard = 1000;
bool Features::orbool = false;
void Features::OffRadar(bool toggle)
{
	globalHandle(2423801).At(PLAYER::PLAYER_ID(), 413).At(200).As<int>() = 1;
	globalHandle(2437022).At(70).As<int>() = NETWORK::GET_NETWORK_TIME() + (Features::offradard * 59) + 1;

}

bool Features::isAntiAFK = false;
void Features::antiAFK(bool toggle) {
	if (Features::isAntiAFK) {
		globalHandle(262145).At(86).As<int>() = 999999;
		globalHandle(262145).At(87).As<int>() = 999999;
		globalHandle(262145).At(88).As<int>() = 999999;
		globalHandle(262145).At(89).As<int>() = 999999;
	}

	notifyMap("~w~Anti AFK Active");

}

void Features::DepositToBank()
{
	int32_t character;
	STATS::STAT_GET_INT($("MPPLY_LAST_MP_CHAR"), &character, 1);

	UNK3::_NETWORK_TRANSFER_WALLET_TO_BANK(character, Features::ammoutwithraw);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Transfer your Money to Bank");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("Textures", "CHAR_GUARD", 1, 8, "BLDR", "Recovery", 1, "", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}

int Features::ammoutwithraw = 0;
void Features::withdraw()
{
	int iVar0;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_LAST_MP_CHAR"), &iVar0, 1);
	UNK3::_NETWORK_TRANSFER_BANK_TO_WALLET(iVar0, Features::ammoutwithraw);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Transfer your Money to Wallet");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("Textures", "CHAR_GUARD", 1, 8, "BLDR", "Recovery", 1, "", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);
}

//
//void Features::koool(char* iol) {
//
//	WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), , 9999, 1);
//
//}



void Features::vf(char* guuk) {

	uint Me = PLAYER::PLAYER_PED_ID();
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 null; null.x = 0, null.y = 0; null.z = 0;
	Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
	Vector3 b; b.x = 0, b.y = 0, b.z = 0;
	Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
	Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
	Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
	Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
	Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
	Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
	Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
	Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
	Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
	int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
	int hash2 = GAMEPLAY::GET_HASH_KEY(guuk);
	int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
	int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
	int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
	STREAMING::REQUEST_MODEL(hash);
	STREAMING::REQUEST_MODEL(hash2);
	STREAMING::REQUEST_MODEL(hash3);
	STREAMING::REQUEST_MODEL(hash4);
	STREAMING::REQUEST_MODEL(hash5);
	if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
	{
		int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
		int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
		int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
		int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
			VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
			VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "Solitary");
			VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);
			ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

		}

	}


}

void Features::maxvehicle()
{
	Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
	VEHICLE::SET_VEHICLE_MOD_KIT(vehicle, 0);
	for (int i = 0; i < 50; i++)
	{
		VEHICLE::SET_VEHICLE_MOD(vehicle, i, VEHICLE::GET_NUM_VEHICLE_MODS(vehicle, i) - 1, false);
	}
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "BLDR");
}

bool Features::fuckedhandling[32] = { false };
void Features::fuckhandling(Player player)
{
	Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(player), false);
	RequestControlOfEnt(veh);
	VEHICLE::SET_VEHICLE_STEER_BIAS(veh, Features::fuckedhandling[player] ? 1.0f : 0.0f);
}





//bool Features::closedoors[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//void Features::doorsclose(Player target) {
//
//
//
//	Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
//	VEHICLE::SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER(PED::GET_VEHICLE_PED_IS_USING(selectedplayer), true, true);
//
//
//}

bool Features::trns = false;
void Features::remore(bool toggle)
{
	globalHandle(1382674).At(558).As<bool>() = toggle;
	globalHandle(1382674).At(491).As<bool>() = toggle;
}

bool Features::camshaker[32] = { false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false, };
void Features::shakecam(Player target)
{
	Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 4, 0.f, false, true, 1000.f);
}


bool Features::exploder[32] = { false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false, };
void Features::explodeloop(Player target)
{
	Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
	FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 0, 0.0f, true, false, 10.0f);
}


bool Features::nightvisionbool = false;
void Features::nightvision(bool toggle)
{
	GRAPHICS::SET_NIGHTVISION(Features::nightvisionbool);
}

void Features::deposit(long amount)
{
	int iVar0;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("mpply_last_mp_char"), &iVar0, -1);
	UNK3::_NETWORK_TRANSFER_WALLET_TO_BANK(iVar0, amount);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();
}



bool Features::ClownLoop = false;
bool Features::fireworkloop = false;
bool Features::alien1 = false;
bool Features::alien2 = false;
bool Features::electric = false;
bool Features::watereffect = false;
bool Features::electricberox = false;
bool Features::smokeeffect = false;
bool Features::bloodeffect = false;
bool Features::moneyeffect = false;
bool Features::moneyeffect10 = false;
bool Features::ghosterr = false;

void Features::withdraw(long amount)
{
	int iVar0;
	STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("mpply_last_mp_char"), &iVar0, 1);
	UNK3::_NETWORK_TRANSFER_BANK_TO_WALLET(iVar0, amount);
	UNK3::_NETWORK_SHOP_CASH_TRANSFER_SET_TELEMETRY_NONCE_SEED();
}

void Features::animation(char* anim, char* dict)
{
	Ped targ_ped = PLAYER::PLAYER_PED_ID();//seleted player
	STREAMING::REQUEST_ANIM_DICT(dict);
	if (STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(targ_ped, 0.0, 0.0, 0.0);//since get_coord is patched i found this native
		int sceneID = NETWORK::NETWORK_CREATE_SYNCHRONISED_SCENE(coords.x, coords.y, coords.z, 0, 0, 0, 2, 0, 1, 1.0f);
		NETWORK::NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(targ_ped, sceneID, dict, anim, 8.0f, -8.0f, 120, 0, 100, 0);/*i changed any to char* i provide the native below(modificated)*/
		NETWORK::NETWORK_START_SYNCHRONISED_SCENE(sceneID);//will start the animation

	}
}

void Features::clearanim()
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());

}

//bool Features::esper = false;
//void Features::esp(Player target)
//{
//	if (target != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
//	{
//		Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
//		Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
//		Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
//		Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
//		Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
//		Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
//		Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
//		Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
//		Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
//
//		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, 255, 0, 0, 255);
//
//		GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, 255, 0, 0, 255);
//
//		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, 255, 0, 0, 255);
//		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, 255, 0, 0, 255);
//
//		Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
//		Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
//		GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, 255, 0, 0, 255);
//	}
//}

static std::vector<DWORD64>	NameAddresses;

std::vector<DWORD64> getNameAdresses()
{
	return NameAddresses;
}

void Features::SpoofName(std::string name)
{
	name += ('\0');

	auto byteSize = name.length();

	for each (DWORD64 addr in getNameAdresses())
	{
		unsigned long OldProtection;
		VirtualProtect((LPVOID)(addr), byteSize, PAGE_EXECUTE_READWRITE, &OldProtection);
		RtlCopyMemory((LPVOID)addr, name.data(), byteSize);
		+VirtualProtect((LPVOID)(addr), byteSize, OldProtection, NULL);
	}

}


void Features::clearbala() {
	int playerMoney = NETWORKCASH::NETWORK_GET_VC_WALLET_BALANCE(0);
	while (playerMoney > 0)
	{
		Any izmon = 2147483647;
		if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&izmon, 1474183246, 312105838, 1445302971, 2147483647, 1)) {
			UNK3::_NETWORK_SHOP_CHECKOUT_START(izmon);
		}
	}
	int playerMoney2 = NETWORKCASH::NETWORK_GET_VC_BANK_BALANCE();
	while (playerMoney2 > 0)
	{
		Any izmon2 = 2147483647;
		if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&izmon2, 1474183246, 312105838, 1445302971, 2147483647, 4)) {
			UNK3::_NETWORK_SHOP_CHECKOUT_START(izmon2);
		}
	}
}



bool Features::betiny = false;
void Features::TinyPlayer(bool toggle)
{
	PED::SET_PED_CONFIG_FLAG(PLAYER::PLAYER_PED_ID(), 223, toggle);

}




void Features::changeplate()
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "", "", "", "", "", "", 64);
	std::string str = get_ingame_keyboard_result();
	if (str != "!!INVALID!!" && str != "")
	{
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), &str[0]);
	}
}


bool Features::spectate[32] = { false };
void Features::specter(Player target)
{
	if (Features::spectate[target] == true) {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(Features::spectate[target], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target));
	}
	else if (Features::spectate[target] == false) {
		NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, PLAYER::PLAYER_PED_ID());
	}
}
bool Features::hornnearbyvehiclesbool = false;
void Features::hornnearbyvehicles(bool toggle)
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle *vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			VEHICLE::START_VEHICLE_HORN(vehs[OffsetID], 5000, AUDIO::_GET_VEHICLE_HORN_HASH(vehs[OffsetID]), true);
		}
	}


}

bool Features::NameESP = false;
void Features::NameTagESP(bool toggle)
{
	Player playerPed = PLAYER::PLAYER_PED_ID();
	for (int i = 0; i < 32; i++)
	{
		Player playerHandle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);
		Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
		char* Name = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));

		if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
		{
			float x1;
			float y1;

			BOOL screenCoords = GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(handleCoords.x, handleCoords.y, handleCoords.z, &x1, &y1);

			std::string playerName = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));

			std::string nameSetupRed = "~HUD_COLOUR_RED~" + playerName;
			std::string nameSetupGreen = "~HUD_COLOUR_GREEN~" + playerName;

			char* playerInfoRed = new char[nameSetupRed.length() + 1];
			char* playerInfoGreen = new char[nameSetupGreen.length() + 1];

			std::strcpy(playerInfoRed, nameSetupRed.c_str());
			std::strcpy(playerInfoGreen, nameSetupGreen.c_str());

			UI::SET_TEXT_FONT(7);
			UI::SET_TEXT_SCALE(0.0, 0.40);
			UI::SET_TEXT_COLOUR(0, 255, 0, 255);
			UI::SET_TEXT_CENTRE(0);
			UI::SET_TEXT_DROPBLDR(0, 0, 0, 0, 0);
			UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
			UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
			if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerPed, playerHandle, 17))
			{
				UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoGreen);
			}
			else
			{
				UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(playerInfoRed);
			}
			UI::END_TEXT_COMMAND_DISPLAY_TEXT(x1, y1);
			UI::SET_TEXT_OUTLINE();
			UI::SET_TEXT_DROPBLDR(5, 0, 78, 255, 255);
		}
	}
}

bool Features::CarClownLoop;
bool Features::Carfireworkloop;
bool Features::Caralien1;
bool Features::Caralien2;
bool Features::Carelectric;
bool Features::CarLightning;
bool Features::moneyeffect15;
float Features::carPTFXsize = 0.4;


int  Features::amount405 = 10000000;
bool Features::stealthnewsafe = false;
void Features::newStealthLoop(bool toggle) {//Stealth Loop any amount
	if ((timeGetTime() - Features::TimePD5) > Features::stealthDelay405) { // Delay
		globalHandle(4262669).At(1).As <int>() = 2147483646;
		globalHandle(4262669).At(7).As <int>() = 2147483647;
		globalHandle(4262669).At(6).As <int>() = 0;
		globalHandle(4262669).At(5).As <int>() = 0;
		globalHandle(4262669).At(3).As <int>() = 312105838;
		globalHandle(4262669).At(2).As <int>() = Features::amount405; // Amount
		globalHandle(4262669).As <Any>() = 1;
		Features::TimePD5 = timeGetTime();

		notifyMap("~w~Add 10 Mil");

		/*int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);*/
	}
}

//bool Features::stealthnewsafee = false;
//void Features::newStealthLoopp(bool toggle) {//Stealth Loop any amount
//	if ((timeGetTime() - Features::TimePD5) > Features::stealthDelay405) { // Delay
//		globalHandle(4262669).At(1).As <int>() = 2147483646;
//		globalHandle(4262669).At(7).As <int>() = 2147483647;
//		globalHandle(4262669).At(6).As <int>() = 0;
//		globalHandle(4262669).At(5).As <int>() = 0;
//		globalHandle(4262669).At(3).As <int>() = 312105838;
//		globalHandle(4262669).At(2).As <int>() = Features::amount405; // Amount
//		globalHandle(4262669).As <Any>() = 1;
//		Features::TimePD5 = timeGetTime();
//
//		int iVar0;
//		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
//		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);
//	}
//}
bool Features::etiennejoelsex = false;
int  Features::amount5 = 0;
bool Features::remover = false;
void Features::RemoveR(bool toggle) {
	if ((timeGetTime() - TimePD9) > Features::stealthDelaydel)
		if (Features::StealthDropinte) {
			if (Features::remover)
			{
				if (Features::amount5 > 0) {
					Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
					UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 454359403, 537254313, Features::amount5, Features::remover ? 4 : 1);
					UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
				}
				else if (Features::amount5 < 0) {
					Any izmon = 2147483647;
					if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&izmon, 1474183246, 454359403, 537254313, Features::amount5, Features::remover ? 4 : 1)) {
						UNK3::_NETWORK_SHOP_CHECKOUT_START(izmon);
					}
				}
			}
			TimePD9 = timeGetTime();
		}
}

bool Features::sagtdegeiligeaufiwtion = false;
bool Features::isRevealPlayers = false;
void Features::revealPlayers(bool toggle) {
	if (toggle) {
		globalHandle(2423801).At(1).At(PLAYER::PLAYER_ID() * 413).At(203).As<bool>() = true;
		globalHandle(2437022).At(71).As<uint32_t>() = NETWORK::GET_NETWORK_TIME();
	}
	else {
		globalHandle(2423801).At(1).At(PLAYER::PLAYER_ID() * 413).At(203).As<bool>() = false;
	}
}

bool Features::blacls = false;
void Features::black(bool toggle)
{
	if (toggle == true)
	{
		SCRIPT::SET_PLAYER_WEATHER(1, 15, 76, 0);
	}
	else {
		SCRIPT::SET_PLAYER_WEATHER(1, 1, 76, 0);
	}
	SCRIPT::SET_PLAYER_WEATHER(1, 15, 76, 0);


}

bool Features::cargopall = false;
void Features::cargoPall(bool toggle)
{

	if (toggle)
	{

		for (int i = 0; i < 32; i++)
		{
			int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
			{
				int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
				Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
				Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
				Vehicle zentorno = Features::SpawnVehicle("CARGOPLANE", Ocoords, 0, 0.0f);
				ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);

			}

		}
	}

}

int  Features::amount55 = 0;
bool Features::removerr = false;
void Features::RemoveRR(bool toggle) {
	if ((timeGetTime() - TimePD14) > Features::stealthDelaydel)
		if (Features::StealthDropinte) {
			if (Features::remover)
			{
				int bankVal = false ? 4 : 1;
				if (Features::amount5 > 0) {
					Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
					UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 454359403, 537254313, Features::amount5, bankVal);
					UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
				}
				else if (Features::amount5 < 0) {
					Any izmon = 2147483647;
					if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&izmon, 1474183246, 454359403, 537254313, Features::amount5, bankVal)) {
						UNK3::_NETWORK_SHOP_CHECKOUT_START(izmon);
					}
				}
			}
			TimePD14 = timeGetTime();
		}
}

static std::vector<void*> EventPtr;
static char EventRestore[REVENT_END] = {};

void Features::patchEvent(eRockstarEvent e, bool b) {
	if (EventPtr.size() == 0) return;
	static const BYTE ret = 0xC3;
	BYTE* ptr = (BYTE*)EventPtr[e];
	if (b) {
		if (EventRestore[e] == 0) EventRestore[e] = ptr[0];
		*ptr = ret;
	}
	else if (EventRestore[e] != 0) *ptr = EventRestore[e];
}
void Features::defuseEvent(eRockstarEvent e, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[e];
	if (toggle)
	{
		if (EventRestore[e] == 0)
			EventRestore[e] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[e] != 0)
			*p = EventRestore[e];
	}
}

bool Features::bypass = false;
void Features::moneyBypass(bool toggle) 
{
	Features::patchEvent(REVENT_REQUEST_PICKUP_EVENT, true);
}

bool Features::NETWORKCRC = false;
void Features::NETWORK_CRC(bool toggle) 
{
	Features::patchEvent(REVENT_NETWORK_CRC_HASH_CHECK_EVENT, true);
}

bool Features::NETWORK = false;
void Features::INCREMENT(bool toggle) 
{
	Features::patchEvent(REVENT_NETWORK_INCREMENT_STAT_EVENT, true);
}

bool Features::TAUNT = false;
void Features::PLAYERTAUNT(bool toggle)
{
	Features::patchEvent(REVENT_PLAYER_TAUNT_EVENT, true);
}

bool Features::RAGDOLL = false;
void Features::REQUESTEVENT(bool toggle)
{
	Features::patchEvent(REVENT_RAGDOLL_REQUEST_EVENT, true);
}

bool Features::WANTED_LEVEL = false;
void Features::WANTEDLEVELL(bool toggle)
{
	Features::patchEvent(REVENT_ALTER_WANTED_LEVEL_EVENT, true);
}

bool Features::WANTED = false;
void Features::WANTEDLEVEL(bool toggle)
{
	Features::patchEvent(REVENT_ALTER_WANTED_LEVEL_EVENT, true);
}

bool Features::WEATHER = false;
void Features::WEATHERtacks(bool toggle)
{
	Features::patchEvent(REVENT_GAME_WEATHER_EVENT, true);
}

bool Features::att = false;
void Features::antiattacks(bool toggle)
{
	Features::patchEvent(REVENT_KICK_VOTES_EVENT, true);
}

bool Features::report = false;
void Features::reattacks(bool toggle)
{
	Features::patchEvent(REVENT_REPORT_MYSELF_EVENT, true);
}

bool Features::remote = false;
void Features::inforemote(bool toggle)
{
	Features::patchEvent(REVENT_REMOTE_SCRIPT_INFO_EVENT, true);
}

bool Features::revweapons = false;
void Features::remoweapons(bool toggle)
{
	Features::patchEvent(REVENT_REMOVE_ALL_WEAPONS_EVENT, true);
}

bool Features::profire = false;
void Features::antifire(bool toggle)
{
	Features::patchEvent(REVENT_FIRE_EVENT, true);
}

bool Features::explosion = false;
void Features::antiexplosion(bool toggle)
{
	Features::patchEvent(REVENT_EXPLOSION_EVENT, true);
}

bool Features::votes = false;
void Features::kickvotes(bool toggle)
{
	Features::patchEvent(REVENT_KICK_VOTES_EVENT, true);
}

void Features::trapcage(Ped ped)
{
	Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(ped, 0);
	Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
}

void Features::trapcagee(Ped ped)
{
	Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(ped, 0);
	Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01b"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
}

void Features::trapall() {
	for (int i = 1; i <= 32; i++) {
		if (PLAYER::PLAYER_ID() != i) {
			Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0);
			Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
		}
	}
}

namespace Features {
	float accelerationfloat = 1.f;
	float brakeforcefloat = 1.f;
	float tractionfloat = 1.f;
	float deformfloat = 1.f;
	float upshiftfloat = 1.f;
	float suspensionfloat = 1.f;
	void updatePhysics()
	{
		accelerationfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_ACCELERATION });
		brakeforcefloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_BRAKEFORCE });
		tractionfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MIN });
		deformfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING,  OFFSET_VEHICLE_HANDLING_DEFORM_MULTIPLIER });
		upshiftfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_UPSHIFT });
		suspensionfloat = Memory::get_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE });
	}
	void acceleration()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_ACCELERATION }, accelerationfloat);
	}
	void brakeforce()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_BRAKEFORCE }, brakeforcefloat);
	}
	void traction()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_TRACTION_CURVE_MIN }, tractionfloat);
	}
	void deform()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_DEFORM_MULTIPLIER }, deformfloat);
	}
	void upshift()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_UPSHIFT }, upshiftfloat);
	}
	void suspension()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_HANDLING, OFFSET_VEHICLE_HANDLING_SUSPENSION_FORCE }, suspensionfloat);

	}
	bool vehiclegravitybool = false;
	void vehiclegravity()
	{
		Memory::set_value<float>({ OFFSET_PLAYER, OFFSET_PLAYER_VEHICLE, OFFSET_VEHICLE_GRAVITY }, vehiclegravitybool ? 0.f : 9.8f);
	}
	bool killpedsbool = false;
	void killpeds()
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped *peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				PED::APPLY_DAMAGE_TO_PED(peds[OffsetID], 1000, false);
			}
		}

	}
	void doAnimation(char* anim, char* animid)
	{
		int pPlayer = PLAYER::PLAYER_PED_ID();
		RequestNetworkControl(pPlayer);
		STREAMING::REQUEST_ANIM_DICT(anim);
		if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
		{
			AI::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
		}
	}
	void PTFXCALL(char *call1, char *call2, char *name)
	{
		call1o = call1;
		call2o = call2;
		nameo = name;

		STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

	}
	void Features::PTFXPLAYER(char* asset2, char *asset, char *PTFX,  int name)
	{
		STREAMING::REQUEST_NAMED_PTFX_ASSET(asset);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(asset);
		if (STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(asset))
		{
			
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(name);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(Features::Online::selectedPlayer, true);
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(PTFX, playerPed, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1, false, false, false);
			
		}
	}

	
	
	void PTFXCALLO(char *call1, char *call2, char *name, Player target)
	{
		Ped user = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);

		call1o = call1;
		call2o = call2;
		nameo = name;
		PTLoopPed = user;

		STREAMING::REQUEST_NAMED_PTFX_ASSET(call1);
		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2);
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(name, user, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

	}

	

	
	bool explodepedsbool = false;
	void explodepeds()
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Ped *peds = new Ped[ArrSize];
		peds[0] = ElementAmount;

		int PedFound = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

		for (int i = 0; i < PedFound; i++)
		{
			int OffsetID = i * 2 + 2;
			RequestControlOfEnt(peds[OffsetID]);
			if (ENTITY::DOES_ENTITY_EXIST(peds[OffsetID]) && PLAYER::PLAYER_PED_ID() != peds[OffsetID])
			{
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(peds[OffsetID], false);
				FIRE::ADD_EXPLOSION(pos.x, pos.y, pos.z, 0, 1000.f, true, false, 0.f);
			}
		}

	}

	//bool Features::explodenearbytiresboolls[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//void Features::explodenearbytiresss(Player target)
	//{
	//	Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	//	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
	//	VEHICLE::SET_VEHICLE_TYRE_BURST(Pos.x, Pos.y, Pos.z, 12);
	//}

	bool Features::savenewdrop112 = false;
	void Features::cashdrop112(bool toggle)
	{

		if ((timeGetTime() - Features::TimePD1) > 600)
		{

			Ped iPed = PLAYER::PLAYER_PED_ID();

			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
			if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"))) {
				WAIT(0);
			}
			else {
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				
				for (int i = 0; i < Features::Bags; i++)
				{
				   OBJECT::pockup(0xDE78F17E, pos.x, pos.y, pos.z + 20.0f / 10, 0, 2500, GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"), FALSE, TRUE);
				}
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
			}

			Features::TimePD1 = timeGetTime();

		}
	}

	bool explodenearbyvehiclesbool = false;
	void explodenearbyvehicles()
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle *vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(vehs[OffsetID], false);
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 0.f);
			}
		}
		delete vehs;

	}


	bool deletenearbyvehiclesbool = false;
	void deletenearbyvehicles()
	{
		const int ElementAmount = 10;
		const int ArrSize = ElementAmount * 2 + 2;

		Vehicle *vehs = new Vehicle[ArrSize];
		vehs[0] = ElementAmount;
		int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

		for (int i = 0; i < VehFound; i++)
		{
			int OffsetID = i * 2 + 2;
			if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
			{
				RequestControlOfEnt(vehs[OffsetID]);
				ENTITY::SET_ENTITY_COORDS(vehs[OffsetID], 6400.f, 6400.f, 0.f, false, false, false, false);
			}
		}
		delete vehs;


	}
}

bool Features::Backboost = false;
void Features::backboost(bool toggle) {
	Features::boostbool = false;
	if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
	{
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~Press E!");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
		UI::_DRAW_NOTIFICATION(FALSE, FALSE);

		int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::APPLY_FORCE_TO_ENTITY(VehID, 1, 0, -10, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1);
	}
}

//bool Features::PTLoopedO[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
//void Features::PTLopperO(Player target)
//{
//
//	if ((timeGetTime() - Features::TimePD6) > 500) // Time between drops
//	{
//		STREAMING::REQUEST_NAMED_PTFX_ASSET(call1o);
//		GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(call2o);
//		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(nameo, PTLoopPed, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
//		Features::TimePD6 = timeGetTime();
//
//	}
//}




string Features::name = "";
string Features::pw = "";








bool Features::rapidfirer = false;
void Features::rapidmaker() {
	Player playerPed = PLAYER::PLAYER_PED_ID();
	if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
		Vector3 endCoords = addVector(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
		Hash weaponhash;
		WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
		if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
		}
	}
}

bool Features::VALKYIREROCKET = false;
void Features::valkyirerocket(bool toggle)
{
	static std::int32_t rocket, cam;
	static std::uint8_t y;
	static float bar;
	static bool init;
	if (IsPedShooting(PLAYER::PLAYER_PED_ID())) {
		if (!init) init = true;
	}
	if (init) {
		if (!ENTITY::DOES_ENTITY_EXIST(rocket)) {
			auto weapon = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
			auto c = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(weapon, 0.f, 1.f, 0.f);
			rocket = OBJECT::CREATE_OBJECT($("w_lr_rpg_rocket"), c.x, c.y, c.z, 1, 1, 0);
			CAM::DESTROY_ALL_CAMS(true);
			cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
			CAM::ATTACH_CAM_TO_ENTITY(cam, rocket, 0.f, 0.f, 0.f, 1);
			CAM::RENDER_SCRIPT_CAMS(1, true, 700, 1, 1);
			CAM::SET_CAM_ACTIVE(cam, 1);
			ENTITY::SET_ENTITY_VISIBLE(rocket, 0, 0);
			bar = .5f; y = 255;
		}
		else {
			CAM::SET_CAM_ROT(cam, CAM::GET_GAMEPLAY_CAM_ROT(0).x, CAM::GET_GAMEPLAY_CAM_ROT(0).y, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 0);
			ENTITY::SET_ENTITY_ROTATION(rocket, CAM::GET_GAMEPLAY_CAM_ROT(0).x, CAM::GET_GAMEPLAY_CAM_ROT(0).y, CAM::GET_GAMEPLAY_CAM_ROT(0).z, 0, 1);

			auto c = add(&ENTITY::GET_ENTITY_COORDS(rocket, 1), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), .8f));
			ENTITY::SET_ENTITY_COORDS(rocket, c.x, c.y, c.z, 0, 0, 0, 0);

			UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
			PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
			ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 1);
			UI::_BLOCK_WEAPON_WHEEL_THIS_FRAME();

			GRAPHICS::DRAW_RECT(0.5f, 0.5f - 0.025f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f, 0.5f + 0.025f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f - 0.025f, 0.5f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f + 0.025f, 0.5f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f + 0.05f, 0.5f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f - 0.05f, 0.5f, 0.050f, 0.002f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f, 0.5f + 0.05f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::DRAW_RECT(0.5f, 0.5f - 0.05f, 0.002f, 0.050f, 255, 255, 255, 255);
			GRAPHICS::SET_TIMECYCLE_MODIFIER("CAMERA_secuirity");

			GRAPHICS::DRAW_RECT(0.25f, 0.5f, 0.03f, 0.5f, 255, 255, 255, 255);
			static auto ticker = GetTickCount();
			if (GetTickCount() - ticker >= 100) {
				bar -= .01f; y -= 4; ticker = GetTickCount();
			}
			GRAPHICS::DRAW_RECT(0.25f, 0.75f - (bar / 2), 0.03f, bar, 255, y, 0, 255);

			float groundZ;
			GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(ENTITY::GET_ENTITY_COORDS(rocket, 1).x, ENTITY::GET_ENTITY_COORDS(rocket, 1).y, ENTITY::GET_ENTITY_COORDS(rocket, 1).z, &groundZ, 0);
			if (ENTITY::HAS_ENTITY_COLLIDED_WITH_ANYTHING(rocket) ||
				(std::abs(ENTITY::GET_ENTITY_COORDS(rocket, 1).z - groundZ) < .5f) ||
				bar <= 0.01) {
				auto impact_coord = ENTITY::GET_ENTITY_COORDS(rocket, 1); ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 0);
				FIRE::ADD_EXPLOSION(impact_coord.x, impact_coord.y, impact_coord.z, 0, 10.f, 1, 0, .4f);
				ENTITY::DELETE_ENTITY(&rocket);
				rocket = 0;
				PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
				CAM::RENDER_SCRIPT_CAMS(0, true, 700, 1, 1);
				CAM::DESTROY_CAM(cam, 1);
				GRAPHICS::SET_TIMECYCLE_MODIFIER("DEFAULT");
				init = false;
			}
		}
	}
	if (!VALKYIREROCKET) {
		CAM::DESTROY_CAM(cam, 1);
		PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 0);
		rocket = 0;
		bar = .10f;
		y = 255;
		ENTITY::FREEZE_ENTITY_POSITION(PLAYER::PLAYER_PED_ID(), 0);
	}
}

void Features::autovehi22(char* toSpawn) {

	for (int i = 0; i < 32; i++)
	{
		int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
		{

			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
			if (STREAMING::IS_MODEL_VALID(model))
			{
				STREAMING::REQUEST_MODEL(model);
				STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2"); GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2"); GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, false, false, false);

				while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
				Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
				float forward = 5.f;
				float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
				float xVector = forward * sin(degToRad(heading)) * -1.f;
				float yVector = forward * cos(degToRad(heading));
				Vehicle veh = VEHICLE::erstelle_fahr(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, false);
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
				DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
				if (Features::spawnincar)
				{
					if (Features::spawnincar22)
					{
						for (int i = 0; i < 32; i++)
						{
							int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
							if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
							{
								Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
								Ped playerPed = PLAYER::PLAYER_PED_ID();
								GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
								PED::SET_PED_INTO_VEHICLE(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), veh, -1);
							}
						}

					}
				}
				if (Features::spawnmaxed)
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
					for (int i = 0; i < 50; i++)
					{
						VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
					}

					WAIT(150);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
				}
			}
		}
    }
	
}



int Features::amount = 0;
bool Features::banked = false;
bool Features::giver = false;
void Features::StealthDropinte() {
	if ((timeGetTime() - Features::TimePD5) > 500)
	{
		if (amount > 0) {
			Any idk = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(1000000000, 2999999999);
			UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&idk, 1474183246, 312105838, 1445302971, Features::amount, Features::banked ? 4 : 1);
			UNK3::_NETWORK_SHOP_CHECKOUT_START(idk);
		}
		else if (amount < 0) {
			Any izmon = 2147483647;
			if (UNK3::_NETWORK_SHOP_BEGIN_SERVICE(&izmon, 1474183246, 312105838, 1445302971, Features::amount, Features::banked ? 4 : 1)) {
				UNK3::_NETWORK_SHOP_CHECKOUT_START(izmon);
			}
		}
		Features::TimePD5 = timeGetTime();
	}

}


bool Features::spawnincar = true;
bool Features::spawnincar22 = true;
bool Features::spawnmaxed = false;





int Features::amount2 = 50000;
int Features::amount3 = -100000;
float Get3DDistance(Vector3 a, Vector3 b) {
	float x = pow((a.x - b.x), 2);
	float y = pow((a.y - b.y), 2);
	float z = pow((a.z - b.z), 2);
	return sqrt(x + y + z);
}
void Features::LoadPlayerInfo(char* playerName, Player p) {

	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);

	RequestControlOfEnt(ped);

	int money = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>(); // i need think okk, wait 1 minute please, be right back
	int rp = globalHandle(1589747).At(p, 790).At(211).At(5).As<int>();
	int earnings = globalHandle(1589747).At(p, 790).At(211).At(56).As<int>();
	int rank = globalHandle(1589747).At(p, 790).At(211).At(6).As<int>();
	int kills = globalHandle(1589747).At(p, 790).At(211).At(28).As<int>();
	int handle = globalHandle(1589747).At(p, 790).At(211).At(56).As<int>();
	int handle2 = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>();
	int bankMoney = handle - 10 - handle2 + (5 * 1 + 3 + 2);
	int deaths = globalHandle(1589747).At(p, 790).At(211).At(29).As<int>();
	int tempMoney = globalHandle(1589747).At(p, 790).At(211).At(3).As<int>();
	int death = globalHandle(1589747).At(p, 790).At(211).At(20).As<int>();
	int deathlost = globalHandle(1589747).At(p, 790).At(211).At(21).As<int>();
	int races = globalHandle(1589747).At(p, 790).At(211).At(15).As<int>();
	int raceslost = globalHandle(1589747).At(p, 790).At(211).At(16).As<int>();
	float kd = globalHandle(1589747).At(p, 790).At(211).At(26).As<float>();  // so i use for stealth money the transactions globals from benny garage , after used stealth benny garage not work anymorehm can i look?
	ostringstream Money, RP, Rank, Kills, Deaths, KD, Earnings, Money1, Moneybank, Golf, EXP, Races, Raceslost, Miss, Death, Deathlost;

	Vector3 __coords = ENTITY::GET_ENTITY_COORDS(ped, 0);
	char buf[0x80]; snprintf(buf, sizeof(buf), "X: ~g~%f", __coords.x);
	char buf1[0x80]; snprintf(buf1, sizeof(buf1), "~s~Y: ~g~%f", __coords.y);
	char buf2[0x80]; snprintf(buf2, sizeof(buf2), "~s~Z: ~g~%f", __coords.z);

	string money2 = to_string(tempMoney);
	int insertPosition = money2.length() - 3;
	while (insertPosition > 0) {
		money2.insert(insertPosition, ",");
		insertPosition -= 3;
	}

	if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(p)) {
		Money << "~w~Cash:~s~ N/A";
		Money1 << "~w~Cash:~s~ $";
		Moneybank << "~w~Bank Cash:~s~ $";
		RP << "~w~RP:~s~ N/A";
		Rank << "~w~Rank:~s~ N/A";
		Kills << "~w~Kills:~s~ N/A";
		Deaths << "~w~Deaths:~s~ N/A";
		KD << "~w~KD Ratio:~s~ N/A";
		Earnings << "~w~Total Earnings:~s~ N/A";
		Races << "~w~Total Races Won:~s~~b~ N/A";
		Raceslost << "~w~Total Races Lost:~s~~b~ N/A";
		Death << "~w~Total Deathmatch Won:~s~~b~ N/A";
		Deathlost << "~w~Total Deathmatch Lost:~s~~b~ N/A";
		//  //__ipbuf << "~w~ IP::~s~ N/A";
		// 
	}
	else {
		Money << "~w~Cash:~s~ $" << money;
		Money1 << "~w~Cash:~s~ $" << money2;
		Moneybank << "~w~Bank Cash:~s~ $" << bankMoney;
		RP << "~w~RP:~s~ " << rp;
		Rank << "~w~Rank:~s~ " << rank;
		Kills << "~w~Kills:~s~ " << kills;
		Deaths << "~w~Deaths:~s~ " << deaths;
		KD << "~w~KD Ratio:~s~ " << kd;
		Earnings << "~t~Total Earnings:~s~ $" << earnings;
		Races << "~w~Total Races Won:~s~~b~ " << races;
		Raceslost << "~w~Total Races Lost:~s~~b~" << raceslost;
		Death << "~w~Total Deathmatch Won:~s~~b~" << death;
		Deathlost << "~w~Total Deathmatch Lost:~s~~b~" << deathlost;

	}



	float health = ENTITY::GET_ENTITY_HEALTH(ped);
	float maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
	float healthPercent = health * 100 / maxHealth;
	ostringstream Health; Health << "Health:~s~ " << healthPercent;
	float armor = PED::GET_PED_ARMOUR(ped);
	float maxArmor = PLAYER::GET_PLAYER_MAX_ARMOUR(p);
	float armorPercent = armor * 100 / maxArmor;
	ostringstream Armor; Armor << "Armor:~s~ " << armorPercent;
	bool alive = !PED::IS_PED_DEAD_OR_DYING(ped, 1);
	char* aliveStatus;
	if (alive) aliveStatus = "Yes"; else aliveStatus = "No";
	ostringstream Alive; Alive << "Alive:~s~ " << aliveStatus;
	bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
	ostringstream VehicleModel; VehicleModel << "Vehicle:~s~ ";
	ostringstream Speed; Speed << "Speed:~s~ ";
	ostringstream IsInAVehicle; IsInAVehicle << "In Vehicle:~s~ ";
	if (inVehicle) {
		IsInAVehicle << "Yes";
		Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		VehicleModel << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
		float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		float vehSpeedConverted;
		vehSpeedConverted = round(vehSpeed * 1.6);
		Speed << vehSpeedConverted << " KM/H";
	}
	else {
		IsInAVehicle << "No";
		float speed = round(ENTITY::GET_ENTITY_SPEED(ped) * 100) / 100;
		Speed << speed << " M/S";
		VehicleModel << "--------";
	}

	ostringstream WantedLevel; WantedLevel << "Wanted Level:~s~ " << PLAYER::GET_PLAYER_WANTED_LEVEL(p);
	ostringstream Weapon; Weapon << "Weapon: ~s~";
	Hash weaponHash;
	if (WEAPON::GET_CURRENT_PED_WEAPON(ped, &weaponHash, 1)) {
		char* weaponName;
		if (weaponHash == 2725352035) {
			weaponName = "Unarmed";
		}
		else if (weaponHash == 2578778090) {
			weaponName = "Knife";
		}
		else if (weaponHash == 0x678B81B1) {
			weaponName = "Nightstick";
		}
		else if (weaponHash == 0x4E875F73) {
			weaponName = "Hammer";
		}
		else if (weaponHash == 0x958A4A8F) {
			weaponName = "Bat";
		}
		else if (weaponHash == 0x440E4788) {
			weaponName = "GolfClub";
		}
		else if (weaponHash == 0x84BD7BFD) {
			weaponName = "Crowbar";
		}
		else if (weaponHash == 0x1B06D571) {
			weaponName = "Pistol";
		}
		else if (weaponHash == 0x5EF9FEC4) {
			weaponName = "Combat Pistol";
		}
		else if (weaponHash == 0x22D8FE39) {
			weaponName = "AP Pistol";
		}
		else if (weaponHash == 0x99AEEB3B) {
			weaponName = "Pistol 50";
		}
		else if (weaponHash == 0x13532244) {
			weaponName = "Micro SMG";
		}
		else if (weaponHash == 0x2BE6766B) {
			weaponName = "SMG";
		}
		else if (weaponHash == 0xEFE7E2DF) {
			weaponName = "Assault SMG";
		}
		else if (weaponHash == 0xBFEFFF6D) {
			weaponName = "Assault Riffle";
		}
		else if (weaponHash == 0x83BF0278) {
			weaponName = "Carbine Riffle";
		}
		else if (weaponHash == 0xAF113F99) {
			weaponName = "Advanced Riffle";
		}
		else if (weaponHash == 0x9D07F764) {
			weaponName = "MG";
		}
		else if (weaponHash == 0x7FD62962) {
			weaponName = "Combat MG";
		}
		else if (weaponHash == 0x1D073A89) {
			weaponName = "Pump Shotgun";
		}
		else if (weaponHash == 0x7846A318) {
			weaponName = "Sawed-Off Shotgun";
		}
		else if (weaponHash == 0xE284C527) {
			weaponName = "Assault Shotgun";
		}
		else if (weaponHash == 0x9D61E50F) {
			weaponName = "Bullpup Shotgun";
		}
		else if (weaponHash == 0x3656C8C1) {
			weaponName = "Stun Gun";
		}
		else if (weaponHash == 0x05FC3C11) {
			weaponName = "Sniper Rifle";
		}
		else if (weaponHash == 0x0C472FE2) {
			weaponName = "Heavy Sniper";
		}
		else if (weaponHash == 0xA284510B) {
			weaponName = "Grenade Launcher";
		}
		else if (weaponHash == 0x4DD2DC56) {
			weaponName = "Smoke Grenade Launcher";
		}
		else if (weaponHash == 0xB1CA77B1) {
			weaponName = "RPG";
		}
		else if (weaponHash == 0x42BF8A85) {
			weaponName = "Minigun";
		}
		else if (weaponHash == 0x93E220BD) {
			weaponName = "Grenade";
		}
		else if (weaponHash == 0x2C3731D9) {
			weaponName = "Sticky Bomb";
		}
		else if (weaponHash == 0xFDBC8A50) {
			weaponName = "Smoke Grenade";
		}
		else if (weaponHash == 0xA0973D5E) {
			weaponName = "BZGas";
		}
		else if (weaponHash == 0x24B17070) {
			weaponName = "Molotov";
		}
		else if (weaponHash == 0x060EC506) {
			weaponName = "Fire Extinguisher";
		}
		else if (weaponHash == 0x34A67B97) {
			weaponName = "Petrol Can";
		}
		else if (weaponHash == 0xFDBADCED) {
			weaponName = "Digital scanner";
		}
		else if (weaponHash == 0x88C78EB7) {
			weaponName = "Briefcase";
		}
		else if (weaponHash == 0x23C9F95C) {
			weaponName = "Ball";
		}
		else if (weaponHash == 0x497FACC3) {
			weaponName = "Flare";
		}
		else if (weaponHash == 0xF9E6AA4B) {
			weaponName = "Bottle";
		}
		else if (weaponHash == 0x61012683) {
			weaponName = "Gusenberg";
		}
		else if (weaponHash == 0xC0A3098D) {
			weaponName = "Special Carabine";
		}
		else if (weaponHash == 0xD205520E) {
			weaponName = "Heavy Pistol";
		}
		else if (weaponHash == 0xBFD21232) {
			weaponName = "SNS Pistol";
		}
		else if (weaponHash == 0x7F229F94) {
			weaponName = "Bullpup Rifle";
		}
		else if (weaponHash == 0x92A27487) {
			weaponName = "Dagger";
		}
		else if (weaponHash == 0x083839C4) {
			weaponName = "Vintage Pistol";
		}
		else if (weaponHash == 0x7F7497E5) {
			weaponName = "Firework";
		}
		else if (weaponHash == 0xA89CB99E) {
			weaponName = "Musket";
		}
		else if (weaponHash == 0x3AABBBAA) {
			weaponName = "Heavy Shotgun";
		}
		else if (weaponHash == 0xC734385A) {
			weaponName = "Marksman Rifle";
		}
		else if (weaponHash == 0x63AB0442) {
			weaponName = "Homing Launcher";
		}
		else if (weaponHash == 0xAB564B93) {
			weaponName = "Proximity Mine";
		}
		else if (weaponHash == 0x787F0BB) {
			weaponName = "Snowball";
		}
		else if (weaponHash == 0x47757124) {
			weaponName = "Flare Gun";
		}
		else if (weaponHash == 0xE232C28C) {
			weaponName = "Garbage Bag";
		}
		else if (weaponHash == 0xD04C944D) {
			weaponName = "Handcuffs";
		}
		else if (weaponHash == 0x0A3D4D34) {
			weaponName = "Combat PDW";
		}
		else if (weaponHash == 0xDC4DB296) {
			weaponName = "Marksman Pistol";
		}
		else if (weaponHash == 0xD8DF3C3C) {
			weaponName = "Brass Knuckles";
		}
		else if (weaponHash == 0x6D544C99) {
			weaponName = "Railgun";
		}
		else {
			weaponName = "Unarmed";
		}
		Weapon << weaponName;


	}
	else Weapon << "Unarmed";
	/*Vector3 myCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);*/
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(ped, 1);
	ostringstream Zone; Zone << "Zone: ~s~" << UI::_GET_LABEL_TEXT(ZONE::GET_NAME_OF_ZONE(coords.x, coords.y, coords.z));
	/*Hash streetName, crossingRoad;
	PATHFIND::GET_STREET_NAME_AT_COORD(coords.x, coords.y, coords.z, &streetName, &crossingRoad);*/
	/*ostringstream Street; Street << "Street: ~s~" << UI::GET_STREET_NAME_FROM_HASH_KEY(streetName);*/
	/*float distance = Get3DDistance(coords, myCoords);*/
	/*ostringstream Distance; Distance << "Distance: ~s~";*/

	/*if (distance > 1000) {
		distance = round((distance / 1000) * 100) / 100;
		Distance << distance << " Kilometers";
	}
	else {
		distance = round(distance * 1000) / 100;
		Distance << distance << " Meters";
	}*/
	/*struct IPAddress
	{
		union
		{
			struct
			{
				std::uint8_t four;
				std::uint8_t three;
				std::uint8_t two;
				std::uint8_t one;
			} fields;

			std::uint32_t packed;
		};
	};*/

	/*
	char* addr = Hooking::get_player_name(ped);
	unsigned char ip1 = *(int*)(addr - 0x48);
	unsigned char ip2 = *(int*)(addr - 0x47);
	unsigned char ip3 = *(int*)(addr - 0x46);
	unsigned char ip4 = *(int*)(addr - 0x45);
	char __ipbuf[4000];
	sprintf(__ipbuf, "IP: %o.%i.%i.%i", ip4, ip3, ip2, ip1);
	*/

	/*unsigned char ip11 = *(int*)(addr1 - 0x34);
	unsigned char ip22 = *(int*)(addr1 - 0x35);
	unsigned char ip33 = *(int*)(addr1 - 0x36);*/
	/*char* addr1 = Hooking::get_player_name(ped);
	unsigned char ip44 = *(int*)(addr1 - 0x34);

	char __ipbuf1[4000];
	sprintf(__ipbuf1, "PORT: %o", ip44);*/




	char ipBuf[32] = {};
	static auto nigNog = (std::uintptr_t(*)(int))(Memory::pattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C").count(1).get(0).get<void>(0));
	auto nigger = nigNog(p);



	if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(p)) {

		for (int i = 0; i < 3; i++)
		{
			if (nigger)
			{
				auto faggot = *(uintptr_t*)(nigger + 0x10b8);
				if (faggot)
				{


					auto ip = (BYTE*)(faggot + 0x44);
					std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~r~IP: ~s~Hide", i);

				}
			}

		}

	}
	else {

		if (nigger)
		{
			auto faggot = *(uintptr_t*)(nigger + 0x10b8);
			if (faggot)
			{
				auto ip = (BYTE*)(faggot + 0x44);
				std::snprintf(ipBuf, sizeof(ipBuf) - 1, "~r~IP: %u.%u.%u.%u", ip[3], ip[2], ip[1], *ip);

			}
		}

	}







	Menu::AddSmallTitle(playerName);
	Menu::AddSmallInfo((char*)Health.str().c_str(), 0);
	Menu::AddSmallInfo((char*)Armor.str().c_str(), 1);
	Menu::AddSmallInfo((char*)Alive.str().c_str(), 2);
	Menu::AddSmallInfo((char*)IsInAVehicle.str().c_str(), 3);
	Menu::AddSmallInfo((char*)VehicleModel.str().c_str(), 4);
	Menu::AddSmallInfo((char*)Speed.str().c_str(), 5);
	Menu::AddSmallInfo((char*)WantedLevel.str().c_str(), 6);
	Menu::AddSmallInfo((char*)Weapon.str().c_str(), 7);
	Menu::AddSmallInfo((char*)Zone.str().c_str(), 8);
	Menu::AddSmallInfo((char*)Money.str().c_str(), 9);
	Menu::AddSmallInfo((char*)Moneybank.str().c_str(), 10);
	Menu::AddSmallInfo((char*)RP.str().c_str(), 11);
	Menu::AddSmallInfo((char*)Rank.str().c_str(), 12);
	Menu::AddSmallInfo((char*)Kills.str().c_str(), 13);
	Menu::AddSmallInfo((char*)Deaths.str().c_str(), 14);
	Menu::AddSmallInfo((char*)KD.str().c_str(), 15);
	Menu::AddSmallInfo(ipBuf, 16);
	Menu::AddSmallInfo(buf, 17);
	Menu::AddSmallInfo(buf1, 18);
	Menu::AddSmallInfo(buf2, 19);
	Menu::AddSmallInfo((char*)Earnings.str().c_str(), 20);
	Menu::AddSmallInfo((char*)Money1.str().c_str(), 21);
	Menu::AddSmallInfo((char*)Death.str().c_str(), 22);
	Menu::AddSmallInfo((char*)Deathlost.str().c_str(), 23);
	Menu::AddSmallInfo((char*)Races.str().c_str(), 24);
	Menu::AddSmallInfo((char*)Raceslost.str().c_str(), 25);

	/*Menu::Option(reportstringkek.c_str());*/

	// try now, i saw one big mistake
	//Menu::AddSmallInfo(buf_ip2, 17);

}

bool Features::Forcefield = false;
bool Features::shootcash = false;
Vehicle Features::SpawnVehicle(char* modelg, Vector3 coords, bool tpinto = 0, float heading = 0.0f) {
	DWORD model = GAMEPLAY::GET_HASH_KEY(modelg);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vehicle veh = VEHICLE::erstelle_fahr(model, coords.x, coords.y, coords.z, heading, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		VEHICLE::SET_VEHICLE_IS_STOLEN(veh, 0);
		return veh;
		DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	}

}

bool Features::isPlayerFriend(Player player, bool & result)
{
	int NETWORK_HANDLE[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &NETWORK_HANDLE[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&NETWORK_HANDLE[0], 13))
	{
		result = NETWORK::NETWORK_IS_FRIEND(&NETWORK_HANDLE[0]);
		return true;
	}
	return false;
}

float Features::gameCamZoomInt = 1.0f;
bool Features::gameCamZoom = false;
void Features::zoomCam() {
	CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(Features::gameCamZoomInt, Features::gameCamZoomInt);
}

void Features::RequestControlOfid(DWORD netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 12)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}


void Features::anti1(bool toggle)
{
	WAIT(0);
}
void Features::anti2(bool toggle)
{
	WAIT(0);
}
void Features::anti3(bool toggle)
{
	WAIT(0);
}
void Features::anti4(bool toggle)
{
	WAIT(0);
}
void Features::anti5(bool toggle)
{
	WAIT(0);
}
void Features::anti(bool toggle)
{
	WAIT(0);
}
DWORD featureWeaponVehShootLastTime = 0;
bool Features::ShootMini = false;
void Features::ShootMiniGun(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_PLAYER_BULLET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

bool Features::ShootZZen = false;
void Features::ShootZZentorno(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("Zentorno");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::ShootFlare = false;
void Features::Shootflare(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_FLARE");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

//float Features::gameCamZoomInt = 1.0f;
//bool Features::gameCamZoom = false;
//void Features::zoomCam() {
//	CAM::_ANIMATE_GAMEPLAY_CAM_ZOOM(Features::gameCamZoomIntt, Features::gameCamZoomIntt);
//}

bool Features::is_file_exist(const char *fileName) {
	ifstream infile(fileName);
	return infile.good();
}


bool Features::hasXenon = true;
bool Features::hasNeons = true;
void Features::ToggleXenon(int VehID)
{
	if (hasXenon)
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 22, 0);
		hasXenon = false;
	}
	else
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 22, 1);
		hasXenon = true;
	}
}
void Features::ToggleNeons(int VehID)
{
	if (hasNeons)
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 22, 0);
		hasNeons = false;
	}
	else
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 22, 1);
		hasNeons = true;
	}
}

bool Features::flxneav = false;
void Features::nearbflx(bool toggle)
{


	const int numElements = 10;
	const int arrSize = numElements * 2 + 2;
	Vehicle veh[arrSize];
	veh[0] = numElements;
	//setAnimation("rcmpaparazzo_4", "lift_hands_in_air_loop");
	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
	if (veh != NULL)
	{
		for (int i = 1; i <= count; i++)
		{
			int offsettedID = i;
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);

			}
		}
	}


}

bool Features::Superr = false;
void Features::SuperDooper(bool toggle)
{
	if (GetAsyncKeyState(VK_NUMPAD9))
	{
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		Vehicle veh[arrSize];
		veh[0] = numElements;
		//setAnimation("rcmpaparazzo_4", "lift_hands_in_air_loop");
		int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
		if (veh != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);
					STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_trevor1");
					GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_trevor1");
					GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
					GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_trev1_trailer_boosh", veh[offsettedID], 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);

					notifyMap("~w~Press Num9");
				}
			}
		}
	}
}
bool Features::Molitov = false;
void Features::molitov(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_MOLOTOV");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::ShootBall = false;
void Features::ShootBalls(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_BALL");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::Laser = false;
void Features::laser(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_PLAYER_LASER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::leagun = false;
void Features::leaWgun(bool toggle) {

	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_ENEMY_LASER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::Raser = false;
void Features::raser(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;
	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_PLAYER_LAZER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::Vehgunafter = false;
void Features::vehgunafter(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		const int Veh[] = { 0xEDA4ED97,
			0xFCC2F483,
			0x79DD18AE,
			0x73F4110E,
			0x7B54A9D3,
			0xE6E967F8,
			0x149BD32A,
			0x6290F15B,
			0xD9F0503D,
			0x0D17099D,
			0x1324E960,
			0x64DE07A1,
			0x1DD4C0FF,
			0x897AFC65 };
		int vehicle;
		int random = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 14);
		int Player = PLAYER::PLAYER_PED_ID();
		Hash vehmodel = Veh[random];
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::RLaser = false;
void Features::Rlaser(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_ENEMY_LASER ");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::WaterCannon = false;
void Features::Watercannon(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_WATER_CANNON");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::ShootAnimals = false;
void Features::shootanimal(bool toggle)
{
	Player player = PLAYER::PLAYER_ID(); 
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_ANIMAL");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::StickyGranata = false;
void Features::stickygranata(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_STICKYBOMB");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}
bool Features::ShootTankR = false;
void Features::ShootTankRounds(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_TANK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}

int Features::espr = 255;
int Features::espg = 255;
int Features::espb = 255;
bool Features::esper = false;
void Features::esp(Player target)
{
	if (target != PLAYER::PLAYER_ID() && ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target)))
	{
		Vector3 entitylocation = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 top1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 top4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z + .8f, NULL };
		Vector3 bottom1world = { entitylocation.x + 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom2world = { entitylocation.x - 0.3f, NULL, entitylocation.y + 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom3world = { entitylocation.x + 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
		Vector3 bottom4world = { entitylocation.x - 0.3f, NULL, entitylocation.y - 0.3f, NULL, entitylocation.z - .8f, NULL };
		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top2world.x, top2world.y, top2world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, top4world.x, top4world.y, top4world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, top3world.x, top3world.y, top3world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, top3world.x, top3world.y, top3world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(bottom1world.x, bottom1world.y, bottom1world.z, bottom2world.x, bottom2world.y, bottom2world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(bottom2world.x, bottom2world.y, bottom2world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(bottom3world.x, bottom3world.y, bottom3world.z, bottom1world.x, bottom1world.y, bottom1world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(top1world.x, top1world.y, top1world.z, bottom1world.x, bottom1world.y, bottom1world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(top2world.x, top2world.y, top2world.z, bottom2world.x, bottom2world.y, bottom2world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(top3world.x, top3world.y, top3world.z, bottom3world.x, bottom3world.y, bottom3world.z, Features::espr, Features::espg, Features::espb, 255);
		GRAPHICS::DRAW_LINE(top4world.x, top4world.y, top4world.z, bottom4world.x, bottom4world.y, bottom4world.z, Features::espr, Features::espg, Features::espb, 255);
		Vector3 locationOne = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target), false);
		Vector3 locationTwo = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		GRAPHICS::DRAW_LINE(locationOne.x, locationOne.y, locationOne.z, locationTwo.x, locationTwo.y, locationTwo.z, Features::espr, Features::espg, Features::espb, 255);
	}
}


bool Features::camshaker112 = false;
void Features::shakecam11(bool toggle)
{
	for (int i = 0; i < 32; i++)
	{
		int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
		{


			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Vector3 targetCords = ENTITY::GET_ENTITY_COORDS(iPed, false);
			FIRE::ADD_EXPLOSION(targetCords.x, targetCords.y, targetCords.z, 4, 0.f, false, true, 1000.f);


		}
	}
}

bool Features::ghostrider = false;
void Features::firerider(bool toggle)
{
	if (toggle == true)
	{
		WheelPTFX("scr_rcbarry1", "scr_alien_teleport");
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0x796e);
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0x8cbd);
		PTFXCALLBoneless("scr_rcbarry1", "scr_rcbarry1", "scr_alien_teleport", 0xdead);

	}
	else
	{
		Vehicle Vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Vehicle);
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Vehicle, 0, 1);
		VEHICLE::DELETE_VEHICLE(&Vehicle);
	}
}

bool Features::ShootT = false;
void Features::ShootTanks(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_FIREWORK");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}
}


bool Features::Speedometerbool = false;
void Features::Speedometer(bool toggle) {

	Ped ped = PLAYER::PLAYER_PED_ID();
	RequestControlOfEnt(ped);



	bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
	std::ostringstream VehicleModel; VehicleModel << "Vehicle:~s~ ";

	std::ostringstream Speed; Speed << "Speed:~s~ ";
	std::ostringstream IsInAVehicle; IsInAVehicle << "In Vehicle:~s~ ";
	if (inVehicle) {
		IsInAVehicle << "Yes";
		Hash vehHash = ENTITY::GET_ENTITY_MODEL(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		VehicleModel << UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash));
		float vehSpeed = ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(ped, 0));
		float vehSpeedConverted;
		vehSpeedConverted = round(vehSpeed *3.6);

		Speed << vehSpeedConverted << " ~r~KM/H";

		Menu::AddSmallInfo2((char*)Speed.str().c_str(), 5);
	}

}

bool Features::cyrclenew = false;
void Features::CyrcleNew(bool toggle)
{

	Ped playerselected = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	if ((timeGetTime() - Features::TimePD1) > Features::DropDelay)
	{
		STREAMING::REQUEST_MODEL(Features::bagHash);
		if (!STREAMING::HAS_MODEL_LOADED(Features::bagHash)) {
			WAIT(0);
		}
		else {
			Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(playerselected, FALSE);
			OBJECT::CREATE_MONEY_PICKUPS(playerPosition.x, playerPosition.y, playerPosition.z, Features::DropAmount, 1, Features::bagHash);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Features::bagHash);

			Features::TimePD1 = timeGetTime();

		}
	}//done wait
}

bool Features::Teleport = true;
void Features::teleport() {

	if (IsKeyPressed(VK_F5))
	{
		teleport_to_marker();
	}
}

bool Features::logi = true;
void Features::logg() {

	if (IsKeyPressed(VK_F6))
	{
		loggi();
	}
}

bool Features::stopp = true;
void Features::stoppii() {

	if (IsKeyPressed(VK_SPACE))
	{
		stoppi();
	}
}


void stoppi()
{
	VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);

}

void loggi()
{
Ped ped = PLAYER::PLAYER_PED_ID();

	if (PED::IS_PED_IN_ANY_VEHICLE(ped, 0))
	{
		Vehicle Veh = PED::GET_VEHICLE_PED_IS_USING(ped);
		Hash Model = ENTITY::GET_ENTITY_MODEL(Veh);

		Blip vBlip = UI::ADD_BLIP_FOR_ENTITY(Veh);
		UI::SET_BLIP_SCALE(vBlip, 1);
		if (VEHICLE::IS_THIS_MODEL_A_CAR(Model))
			UI::SET_BLIP_SPRITE(vBlip, 225);
		else if (VEHICLE::IS_THIS_MODEL_A_HELI(Model))
			UI::SET_BLIP_SPRITE(vBlip, 64);
		else if (VEHICLE::IS_THIS_MODEL_A_PLANE(Model))
			UI::SET_BLIP_SPRITE(vBlip, 16);
		else if (VEHICLE::IS_THIS_MODEL_A_BIKE(Model))
			UI::SET_BLIP_SPRITE(vBlip, 226);
		else
			UI::SET_BLIP_SPRITE(vBlip, 225);

		UI::SET_BLIP_NAME_FROM_TEXT_FILE(vBlip, "Pinned Vehicle");
		UI::SET_BLIP_COLOUR(vBlip, 0);
		UI::SET_BLIP_FLASHES(vBlip, false);
		UI::SET_BLIP_DISPLAY(vBlip, 2);
		UI::SET_BLIP_CATEGORY(vBlip, 1);
		UI::BEGIN_TEXT_COMMAND_SET_BLIP_NAME("Alliance's Vehicle");
		UI::END_TEXT_COMMAND_SET_BLIP_NAME(vBlip);
	}
	else notifyMap("~r~You are not in any vehicle!");
}


bool Features::ichwichsedireintommy = false;
bool Features::ichliebedich = true;
bool Features::ALARM = false;
void Features::alarm(bool toggle)
{
	VEHICLE::START_VEHICLE_ALARM;
}
bool Features::Drunk = false;
void Features::drunk(bool toggle)
{
	AUDIO::SET_PED_IS_DRUNK;
} 
bool Features::Light = false;
void Features::light(bool toggle)
{
	GAMEPLAY::_CREATE_LIGHTNING_THUNDER();
}
bool Features::cped = false;
void Features::cpedd(bool toggle)
{
	GAMEPLAY::CLEAR_AREA_OF_PEDS;
}
bool Features::GameStop = false;
void Features::gamestop(bool toggle)
{
	GAMEPLAY::SET_GAME_PAUSED;
}
bool Features::ShootR = false;
void Features::ShootRocket(bool toggle)
{
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~g~press +!");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 8, "~w~BLDR", "~w~Prime", 1, "UnlockAll", 9, 0);
	UI::_DRAW_NOTIFICATION(FALSE, FALSE);

	bool bSelect = GetAsyncKeyState(0x6B); // num plus
	if (bSelect && featureWeaponVehShootLastTime + 150 < GetTickCount() &&
		PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);

		Vector3 v0, v1;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(veh), &v0, &v1);

		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_VEHICLE_ROCKET");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, 0);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);

		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z,
			coords0to.x, coords0to.y, coords0to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z,
			coords1to.x, coords1to.y, coords1to.z,
			250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		featureWeaponVehShootLastTime = GetTickCount();

	}

}
bool Features::FIREBREATH = false;
void Features::firebreath(bool toggle)
{
	float XPos = 0.02, YPos = 0.2, ZPos = 0.0, XOff = 90.0, YOff = -100.0, ZOff = 90.0;

	STREAMING::REQUEST_NAMED_PTFX_ASSET("core");
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("core");
	if ((timeGetTime() - Features::TimePD5) > 200)
	{
		int ptfx = GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2("ent_sht_flame", PLAYER::PLAYER_PED_ID(), XPos, YPos, ZPos,
			XOff, YOff, ZOff, SKEL_Head, 1, 1, 1, 1);
		Features::TimePD5 = timeGetTime();
	}
	STREAMING::REMOVE_PTFX_ASSET();
}
bool Features::isAutoRegHealth = false;
void Features::AutoRegHealth(bool toggle) {
	if (Features::isAutoRegHealth)
	{
		float fHealth = Memory::get_value<float>({ 0x08 , 0x280 });
		float fHealthMax = Memory::get_value<float>({ 0x08 , 0x2A0 });
		float value = 20.f;

		if ((timeGetTime() - Features::TimePD9) > 400) {
			value += fHealth;
			if (fHealth < fHealthMax) {
				fHealth = value;
				Memory::set_value<float>({ 0x08 , 0x280 }, value);
			}
			if (fHealth == fHealthMax) {
				fHealth = fHealthMax;
			}
			Features::TimePD9 = timeGetTime();
		}
	}
}

bool Features::isAutoRegArmour = false;
void Features::AutoRegArmour(bool toggle) {

	if (Features::isAutoRegArmour)
	{
		if ((timeGetTime() - Features::TimePD10) > 400) {
			if (PED::GET_PED_ARMOUR(PLAYER::PLAYER_PED_ID()) < PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID())) {
				PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 20);
			}
			Features::TimePD10 = timeGetTime();
		}
	}

}

bool Features::ShootHydra = false;
void Features::Shootthehydra(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("HYDRA");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
void setupdraw()
{
	UI::SET_TEXT_FONT(0);
	UI::SET_TEXT_SCALE(0.4f, 0.4f);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(0);
	UI::SET_TEXT_DROPBLDR(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
}
void drawstring(char* text, float X, float Y)
{
	UI::_SET_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_DRAW_TEXT(X, Y);
}
bool Features::DisplayFPS = false;
void Features::featureDisplayFPS(bool toggle)
{
	float LastFrameTime = GAMEPLAY::GET_FRAME_TIME();
	int getFPS = (1.0f / LastFrameTime);
	char FPStext[60];
	snprintf(FPStext, sizeof(FPStext), "FPS: ~r~ %d", getFPS);
	setupdraw();
	UI::SET_TEXT_FONT(6);
	UI::SET_TEXT_SCALE(0.5f, 0.5f);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_CENTRE(0);
	drawstring(FPStext, 0.020f, 0.010f);
}

//2B Stealth Method

bool Features::editmoney = false;
void Features::MoneyEdit(bool toggle) {

	int towallet;
	int tobank;
	int iVar2 = INT_MAX;

	if (globalHandle(2599118).As<int>() == -1) {
		globalHandle(2599118) = NETWORKCASH::NETWORK_GET_VC_BANK_BALANCE();
	}
	if (globalHandle(2599119).As<int>() == -1) {
		globalHandle(2599119) = NETWORKCASH::NETWORK_GET_VC_WALLET_BALANCE(-1);
	}
	towallet = 0;
	tobank = 0;
	if (globalHandle(2599118).Get<int>() > 0) {
		if (globalHandle(2599118).Get<int>() >= &iVar2) {
			tobank = iVar2;
		}
		else {
			tobank = iVar2 - (iVar2 - globalHandle(2599118).As<int>());
		}
		iVar2 -= tobank;
	}
	if (iVar2 > 0) {
		if (globalHandle(2599119).Get<int>() > 0) {
			if (globalHandle(2599119).Get<int>() >= &iVar2) {
				towallet = iVar2;
			}
			else {
				towallet = iVar2 - (iVar2 - globalHandle(2599119).As<int>());
			}
			iVar2 -= towallet;
		}
	}
	invoke<Void>(536737010038877744, towallet, tobank);
	globalHandle(2599118) = towallet;
	globalHandle(2599119) = tobank;

	notifyMap("~w~Add 2 Bilion");
}
bool Features::ShootWeaponT = false;
void Features::ShootWeaponTank(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("RHINO");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::AMBUL = false;
void Features::AMBULANCE(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("AMBULANCE");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::Air = false;
void Features::air(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
			WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
				WAIT(0);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
		}
	}
}
bool Features::Fake = false;
void Features::fake(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		Vector3 pos;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &pos))
		{
			OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("prop_money_bag_01"), pos.x, pos.y, pos.z, true, 1, 0);
		}
	}
}
bool Features::Vehgun = false;
void Features::vehgun(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		const int Veh[] = { 0xB779A091,
			0x00ABB0C0,
			0xD756460C,
			0xEDD516C6,
			0x2BEC3CBE,
			0x7074F39D,
			0x9AE6DDA1,
			0xAFBB2CA4,
			0xC9E8FF76,
			0x98171BD3,
			0x353B561D,
			0x437CF2A0,
			0x53174EEF,
			0xD577C962,
			0x2F03547B,
			0x2C75F0DD,
			0x44623884,
			0xDFF0594C,
			0x6FD95F68,
			0x067BC037,
			0x00ABB0C0,
			0x15F27762,
			0xC3FBA120,
			0xCB44B1CA,
			0x3D6AAA9B,
			0x0AFD22A6,
			0x810369E2,
			0x04CE68AC };
		int vehicle;
		int random = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 28);
		int Player = PLAYER::PLAYER_PED_ID();
		Hash vehmodel = Veh[random];
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::VehgunP[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::vehgunp(Player target)
{
	auto playerselected = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	if (IsPedShooting(playerselected))
	{
		float offset;
		const int Veh[] = { 0xB779A091,
			0x00ABB0C0,
			0xD756460C,
			0xEDD516C6,
			0x2BEC3CBE,
			0x7074F39D,
			0x9AE6DDA1,
			0xAFBB2CA4,
			0xC9E8FF76,
			0x98171BD3,
			0x353B561D,
			0x437CF2A0,
			0x53174EEF,
			0xD577C962,
			0x2F03547B,
			0x2C75F0DD,
			0x44623884,
			0xDFF0594C,
			0x6FD95F68,
			0x067BC037,
			0x00ABB0C0,
			0x15F27762,
			0xC3FBA120,
			0xCB44B1CA,
			0x3D6AAA9B,
			0x0AFD22A6,
			0x810369E2,
			0x04CE68AC };
		int vehicle;
		int random = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 28);
		int Player = PLAYER::PLAYER_PED_ID();
		Hash vehmodel = Veh[random];
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerselected);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerselected, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerselected, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::TITAN = false;
void Features::TITANT(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("TITAN");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::SHAMAL = false;
void Features::SHAM(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("SHAMAL");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::MILJET = false;
void Features::MIL(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("¥MILJET");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::ShootDump = false;
void Features::ShootDumpTruck(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("DUMP");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::ShootZen = false;
void Features::ShootZentorno(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("ZENTORNO");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::ShootSWI = false;
void Features::ShootSWIFT(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("SWIFT");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::ShootBo = false;
void Features::ShootBoar(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("A_C_Boar");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
bool Features::ShootCo = false;
void Features::ShootCow(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("A_C_Cow");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}

bool Features::ShootBuz = false;
void Features::ShootBuzzard(bool toggle)
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (IsPedShooting(playerPed))
	{
		float offset;
		int vehmodel = GAMEPLAY::GET_HASH_KEY("BUZZARD2");
		STREAMING::REQUEST_MODEL(vehmodel);

		while (!STREAMING::HAS_MODEL_LOADED(vehmodel)) WAIT(0);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 5.0, 0.0);

		if (STREAMING::IS_MODEL_IN_CDIMAGE(vehmodel) && STREAMING::IS_MODEL_A_VEHICLE(vehmodel))
		{
			Vector3 dim1, dim2;
			GAMEPLAY::GET_MODEL_DIMENSIONS(vehmodel, &dim1, &dim2);

			offset = dim2.y * 1.6;
		}

		Vector3 dir = ENTITY::GET_ENTITY_FORWARD_VECTOR(playerPed);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 1);
		float rot = (ENTITY::GET_ENTITY_ROTATION(playerPed, 0)).z;
		Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
		Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
		Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 10)));
		Vector3 endCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 500.0f)));

		Vehicle veh = VEHICLE::erstelle_fahr(vehmodel, pCoords.x + (dir.x * offset), pCoords.y + (dir.y * offset), startCoords.z, rot, 1, 1);
		ENTITY::SET_ENTITY_VISIBLE(veh, false, false);

		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0f, 500.0f, 2.0f + endCoords.z, 0.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);
		ENTITY::SET_VEHICLE_AS_NO_LONGER_NEEDED(&veh);
	}
}
void RequestControl(Entity input)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);

	int tick = 0;
	while (tick <= 50)
	{
		if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(input))
			WAIT(0);
		else
			return;
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);
		tick++;
	}
}

bool Features::Testgun = false;
void Features::testgun(bool toggle)
{
	Vector3 iCoord;
	if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
	{
		int VehID = VEHICLE::GET_CLOSEST_VEHICLE(iCoord.x, iCoord.y, iCoord.z, 100.0f, 0, 71);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
	}
}

bool Features::Mapweck = false;
void Features::mapweck(bool toggle)
{
	if (Mapweck) {
		UI::DISPLAY_RADAR(false);
	}
	else {
		UI::DISPLAY_RADAR(true);
	}
}

bool Features::CEOKickProtection;
void Features::CEOKickp(bool toggle)
{
	globalHandle(1382674).At(536).As<bool>() = 536;
}


bool Features::GravityGun = false;
void Features::gravitygun(bool toggle) {

	Entity EntityTarget;
	DWORD equippedWeapon;
	WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
	Player player = PLAYER::PLAYER_ID();
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
	Vector3 dir = rot_to_direction(&rot);
	Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	float spawnDistance = get_distance(&camPosition, &playerPosition);
	spawnDistance += 6;
	Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


	Player tempPed = PLAYER::PLAYER_ID();

	if (grav_target_locked)
	{
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
		{
			Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
			if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
			{
				EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
			}

			RequestNetworkControl(EntityTarget);

			if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
				ENTITY::SET_ENTITY_HEADING(
					EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

			if (GetAsyncKeyState(VK_LBUTTON))
			{
				AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", EntityTarget, "docks_heist_finale_2a_sounds", 0, 0);
				ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
				ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
					0.0f, 0, 0, 1, 1, 0, 1);
				grav_target_locked = false;
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
			}
		}
	}
	if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
	{
		grav_target_locked = true;
		PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
	}


}
void shootAtPed(Player selectedPlayer)
{
	Vector3 Mouth = PED::GET_PED_BONE_COORDS(selectedPlayer, SKEL_Head, 0.1f, 0.0f, 0.0f);
	PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
}
bool Features::Trigger = false;
void Features::TriggerAim(bool toggle)
{
	if (TriggerAim)
	{
		Entity AimedAtEntity;
		if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &AimedAtEntity))
		{
			if (ENTITY::IS_ENTITY_A_PED(AimedAtEntity) && !ENTITY::IS_ENTITY_DEAD(AimedAtEntity) && PED::IS_PED_A_PLAYER(AimedAtEntity) && ENTITY::GET_ENTITY_ALPHA(AimedAtEntity) == 255)
			{
				shootAtPed(AimedAtEntity);
			}
		}
	}
}

bool Features::Orbital = false;
void Features::Orbi(bool toggle) {
	if (Orbi)
	{
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_ORBITAL_CANNON_COOLDOWN"), 0, 0);
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP1_ORBITAL_CANNON_COOLDOWN"), 0, 0);
	}

	notifyMap("~w~Orbital Cannon~g~Reset");
}

bool Features::Sell = false;
void Features::Sel(bool toggle) {
	if (Sel)
	{
		STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_SELL_TIME"), 0, 1);
	}

	notifyMap("~g~Reset sales limit");
}

bool Features::waterGun = false;
void Features::WaterGun(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (IsPedShooting(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 13, 10.0f, false, false, false);
		}

	}
}

bool Features::explodeGun = false;
void Features::ExplodeGun(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (IsPedShooting(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 10.0f, false, false, false);
		}

	}
}

bool Features::pedGun = false;
void Features::PedGun(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (IsPedShooting(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			PED::CREATE_RANDOM_PED(coords.x, coords.y, coords.z);
		}

	}
}

bool Features::RPG = false;
void Features::rpg(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;

	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_RPG");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::Flare = false;
void Features::flare(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;

	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_FLARE");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::Grenade = false;
void Features::grenade(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;

	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}



bool Features::MOLOTOV = false;
void Features::molotov(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;

	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_MOLOTOV");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::BALL = false;
void Features::ball(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;

	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_BALL");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::WATER = false;
void Features::water(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;

	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_HIT_BY_WATER_CANNON");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::Smoke = false;
void Features::smoke(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
	startDistance += 5.25;
	endDistance += 1000.0;

	if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
	{
		Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("WEAPON_GRENADELAUNCHER_SMOKE");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
				WAIT(0);
		}
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
	}
}

bool Features::fireGun = false;
void Features::FireGun(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (IsPedShooting(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 12, 10.0f, false, false, false);
		}

	}
}

bool Features::expAmmo = false;
void Features::expAmmos(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (IsPedShooting(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 10.0f, false, false, false);
		}

	}
}

bool Features::rider = false;
void Features::ghost(bool toggle) {
	
  Features::PTFXCALL("scr_agencyheist", "scr_agencyheist", "scr_fbi_dd_breach_smoke");

}



bool Features::moneyGun = false;
void Features::MoneyGun(bool toggle) {
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	if (IsPedShooting(playerPed))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
		{
			STREAMING::REQUEST_MODEL(0x9CA6F755);
			if (!STREAMING::HAS_MODEL_LOADED(0x9CA6F755)) {
				WAIT(0);
			}
			else {

				OBJECT::pockup(0xDE78F17E, coords.x, coords.y, coords.z, 0, 2500, 0x9CA6F755, FALSE, TRUE);

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x9CA6F755);
			}
		}

	}
}
void Features::SetMultipliers() {

}


void Features::addVisOption(char *option, char *model, char *notification)
{
	Menu::Option(option);
	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed)
	{
		GRAPHICS::SET_TIMECYCLE_MODIFIER(model);
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(notification);
		UI::_DRAW_NOTIFICATION(FALSE, FALSE);
	}
}
void  Features::ClearVisions(char *option, char *notification)
{
	Menu::Option(option);
	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed)
	{
		GRAPHICS::CLEAR_TIMECYCLE_MODIFIER();
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(notification);
		UI::_DRAW_NOTIFICATION(FALSE, FALSE);
	}
}

bool Features::rainMoney[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::rainMoney2(Player target)
{
	STREAMING::REQUEST_MODEL(0x9CA6F755);
	Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 10.0);
	int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-15, 15);
	int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-15, 15);

	STREAMING::REQUEST_MODEL(0x9CA6F755);
	while (!STREAMING::HAS_MODEL_LOADED(0x9CA6F755))
		WAIT(0);
	if (STREAMING::HAS_MODEL_LOADED(0x9CA6F755))
	{
		OBJECT::pockup(0xDE78F17E, pp.x + offset1, pp.y + offset2, pp.z, 0, 2500, 0x9CA6F755, false, true);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x9CA6F755);
	}
}

bool Features::savenewdrop2444[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::cashdrop2444(bool toggle)
{

	if ((timeGetTime() - Features::TimePD2) > Features::DropDelay)
	{

		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		STREAMING::REQUEST_MODEL(Features::bagHash);
		if (!STREAMING::HAS_MODEL_LOADED(Features::bagHash)) {
			WAIT(0);
		}
		else {
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
			OBJECT::pockup(0xDE78F17E, pos.x, pos.y, pos.z + 20.0f / 10, 0, Features::DropAmount, Features::bagHash, FALSE, TRUE);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Features::bagHash);
		}

		Features::TimePD2 = timeGetTime();

	}
}

bool Features::moneyguntoggles[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::OtherPlayerMoneyGun(Player target) {


	auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	if (IsPedShooting(ped))
	{
		Vector3 coords;
		if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(ped, &coords))
		{
			STREAMING::REQUEST_MODEL(Features::bagHash);
			if (!STREAMING::HAS_MODEL_LOADED(Features::bagHash)) {
				WAIT(0);
			}
			else {

				OBJECT::pockup(0x1E9A99F8, coords.x, coords.y, coords.z, 0, Features::DropAmount3, Features::bagHash, FALSE, TRUE);

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Features::bagHash);
			}
		}

	}
}

bool Features::alldrop = false;
void Features::AllDrop(bool toggle)
{ // all player 2k
	if (alldrop)
	{

		if ((timeGetTime() - Features::TimePD2) > Features::DropDelay)
		{
			for (int i = 0; i < 32; i++)
			{
				int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
				{
					Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					STREAMING::REQUEST_MODEL(Features::bagHash);
					if (!STREAMING::HAS_MODEL_LOADED(Features::bagHash)) {
						WAIT(0);
					}
					else {
						Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
						OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + Features::DropHeight / 10, 0, Features::DropAmount, Features::bagHash, FALSE, TRUE);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Features::bagHash);
					}
					Features::TimePD2 = timeGetTime();
				}
			}

		}
	}
}

bool Features::MYDROP = false;
void Features::mydrop(bool toggle)
{ // all player 2k
	if (MYDROP)
	{

		if ((timeGetTime() - Features::TimePD2) > Features::DropDelay)
		{
			
				    Ped iPed = PLAYER::PLAYER_PED_ID();
					STREAMING::REQUEST_MODEL(Features::bagHash);
					if (!STREAMING::HAS_MODEL_LOADED(Features::bagHash)) {
						WAIT(0);
					}
					else {
						Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
						
						for (int i = 0; i < Features::Bags; i++)
						{
						   OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + Features::DropHeight / 10, 0, Features::DropAmount, Features::bagHash, FALSE, TRUE);
						}
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Features::bagHash);
					}
					Features::TimePD2 = timeGetTime();
				
			

		}
	}
}
int Features::Explosionfick = 38;
int Features::Explosionfickkkk = 38;

int Features::Explosionfickk = 38;
int Features::ficksizee = 10;
int Features::maker = 43;
int Features::ficksize = 10;
int Features::DropHeight = 35; 
int Features::DropAmount = 2500;
int Features::DropAmount3 = 2500;
int Features::stealthdelay = 500;
int Features::delstealthdelay = 1000000000;
int Features::DropDelay = 500;
int Features::stealthDelay405 = 500;
int Features::stealthDelay1 = 800;
int Features::Horndelay = 50;
int Features::Bags = 2;
int Features::Rundelay = 50; 
int Features::bandelay = 300;
int Features::stealthDelaydel = 1000000000;
Hash Features::bagHash = 0x9CA6F755;
Hash Features::bagHash557 = 0x9CA6F755;
bool Features::cashdrop69Toggle[32];
int drop_ticker = GetTickCount();
void Features::cashdrop69(Player target)
{

	if ((GetTickCount() - drop_ticker) >= Features::DropDelay)
	{
		Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);

		STREAMING::REQUEST_MODEL(Features::bagHash);
		while (!STREAMING::HAS_MODEL_LOADED(Features::bagHash)) WAIT(0);

		Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);


		for (int i = 0; i < Features::Bags; i++)
		{
		       OBJECT::pockup(0xDE78F17E, pos.x, pos.y, pos.z + Features::DropHeight / 10, 0, Features::DropAmount, Features::bagHash, FALSE, TRUE);
		}
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Features::bagHash);

		
		drop_ticker = GetTickCount();
	}
}

bool Features::randommon = false;
void Features::randommonnn(bool toggle) {//Stealth Loop any amount
	if ((timeGetTime() - Features::TimePD13) > Features::stealthDelay405) { // Delay
		globalHandle(4262669).At(1).As <int>() = 2147483646;
		globalHandle(4262669).At(7).As <int>() = 2147483647;
		globalHandle(4262669).At(6).As <int>() = 0;
		globalHandle(4262669).At(5).As <int>() = 0;
		globalHandle(4262669).At(3).As <int>() = 312105838;
		globalHandle(4262669).At(2).As <int>() = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(15466, 10000000); // Amount
		globalHandle(4262669).As <Any>() = 1;
		Features::TimePD13 = timeGetTime();

		int iVar0;
		STATS::STAT_GET_INT(GAMEPLAY::GET_HASH_KEY("MP0_MONEY_EARN_JOBS"), &iVar0, -1);
		STATS::STAT_SET_INT($("MP0_MONEY_EARN_JOBS"), iVar0 + Features::amount405, 1);

		notifyMap("~w~Add Random Money");
	}
}

bool Features::cargop[35] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
void Features::cargoP(Player target)
{

	if (cargoP)
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(Handle);
		Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
		Vector3 Ocoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Handle, 0.0, 5.0, 0.0);
		Vehicle zentorno = Features::SpawnVehicle("CARGOPLANE", Ocoords, 0, 0.0f);
		ENTITY::SET_ENTITY_INVINCIBLE(zentorno, 0);
	}






}

NativeVector3 getGroundCoords(Vector2 coords, int tries)
{
	float groundZ;

	for (int handle = 0; handle < tries; ++handle)
	{
		if (handle)
		{
			for (float zCoord = 1000.f; zCoord >= 0.f; zCoord -= 100.f)
			{
				STREAMING::REQUEST_COLLISION_AT_COORD(coords.x, coords.y, zCoord);

				WAIT(0);

			}
		}

		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, 1000.f, &groundZ, 0))
		{
			return NativeVector3(coords.x, coords.y, groundZ + 2);
		}
	}

	return NativeVector3(coords.x, coords.y, 1000.f);
}

bool Features::rankspoofpl = true;
void Features::spoofRankpl(bool toggle)
{
	Player player = Features::Online::selectedPlayer;
	globalHandle(1589747).At(player, 790).At(211).At(6).As<int>() = Menu::Settings::setspoofrankpl;
}

void Features::teleportToWaypoint() {
	Vector2 position;
	if (Hooking::get_waypoint_pos(&position))
	{
		Ped ped = PLAYER::PLAYER_PED_ID();
		Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(ped, false);
		auto inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, false) == TRUE;
		auto coords = getGroundCoords(position, 20);

		if (inVehicle)
		{
			NativeVector3 closestRoad;
			if (PATHFIND::GET_CLOSEST_ROAD(coords.x, coords.y, coords.z, 1.f, 1, &closestRoad, &closestRoad, 0, 0, 0, 0))
			{
				coords = closestRoad;
			}
		}

		ENTITY::SET_ENTITY_COORDS(inVehicle ? veh : ped, coords.x, coords.y, coords.z, 0, 0, 0, 1);
	}
}

void Features::set_session_time(int h, int m, int s) {
	Hooking::ClockTime->hour = Menu::Settings::Hourfick;
	Hooking::ClockTime->minute = Menu::Settings::Minufick;
	Hooking::ClockTime->second = s;
	Hooking::set_session_time_info(4, 0);
}



void unlockUpAtomizerSkin()
{
	globalHandle(96093).As<int>() = 90;
}

void unlockWireframeTshirts()
{
	globalHandle(0x40001).At(22758).As<int>() = 1;
	globalHandle(0x40001).At(22759).As<int>() = 1;
	globalHandle(0x40001).At(22760).As<int>() = 1;
	globalHandle(0x40001).At(22761).As<int>() = 1;
	globalHandle(0x40001).At(22762).As<int>() = 1;
}

void resetMentalState()
{
	globalHandle(0x40001).At(7130).As<int>() = -100;
}

void unlockHeistClothes()
{
	globalHandle(0x40001).At(9016).As<int>() = 1;
	globalHandle(0x40001).At(9017).As<int>() = 1;
	globalHandle(0x40001).At(9018).As<int>() = 1;
	globalHandle(0x40001).At(9019).As<int>() = 1;
	globalHandle(0x40001).At(9020).As<int>() = 1;
}