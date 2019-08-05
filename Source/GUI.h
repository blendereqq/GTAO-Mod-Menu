#pragma once

/*enum SubMenus { //Add Sub Menus in here
	NOMENU,
	mainmenu,
	lsc,
	senas,
	PTFX,
	PTFXO,
	playermenu,
	recover,
	moneyoptions,
	weapon,
	objectoptions,
	onlinemenu_playerlist,
	onlinemenu_selected,
	miscoptions,
	settings,
	credit,
	exitgta,
	settingstheme,
	themeloader,
	settingstitlerect,
	settingsscroller,
	settingsoptiontext,
	font,
	allplayers,
	anim,
	teleports,
	ipl,
	teleportso,
	teleportsoa,
	plateoptions,
	protection,
	modelchanger,
	tpother,
	weatheroptions,
	vehicle,
	vehspawner,
	attachoptions,
	forcean,
	forceanall,
	Doomsday,
	Super,
	Sports,
	SportClassic,
	Offroad,
	Sedans,
	Coupes,
	Muscle,
	Boats,
	Commercial,
	Compacts,
	Cycles,
	Emergency,
	Helicopters,
	Industrial,
	Military,
	Motorcycles,
	Planes,
	Service,
	SUV,
	Trailer,
	Trains,
	Utility,
	Vans,

};*/


extern enum SubMenus;
void scrollbar();
extern float xxxxx;
typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
typedef struct RGBA {
	int r, g, b, a;
};
typedef struct RGB {
	int r, g, b;
};
extern float fx;
extern float fxx;
extern float fxxx;
extern float fxxxx;
namespace Menu {
	void drawInstructions();
	
	namespace Drawing {
		void Hitler();
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Text(const char * text, RGBAF rgbaf, VECTOR2 position, float size);

		void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		//void Title2(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	}
	namespace Settings {
		/*bool MenuPlayer(const char* option, SubMenus newSub, int player);
		bool MenuPlayer(const char* option, SubMenus newSub, int player, std::function<void()> function);*/
		extern bool selectPressed;
		extern bool leftPressed;
		//extern bool setspoofrankpl;
		extern bool schwesselfick;
		extern bool schwesselfickk;
		extern bool rightPressed;
		extern bool amount405;
		extern bool center;
		extern int titleRectTexture;
		extern bool headerlist;
		extern int alpha;
		extern int setspoofrankpl;
		extern int LVL;
		extern bool controllerinput;
		extern int gayStealth;
		extern int stealthDelay405;
		extern int run;
		extern bool GlareOnOff;
		extern float GlareXPos;
		extern bool DrawGradientRect;
		extern float bulletp;
		extern float camerra;
		extern float bulletppp;
		extern int bullet;
		extern int notoirff;
		extern int offradard;
		extern bool Authcheckder2;
		extern int Hourfick;
		extern int Minufick;
		extern int secfick;
		extern bool Virustroll;
		extern bool Authcheck;
		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;
		extern int alpha2;

		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];

		extern float menuX;
		extern float menuY;
		extern RGBA titleEnd;
		extern RGBA text;
		extern RGBA Scrollergradient;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBAF PremiumTitle;
		extern RGBAF SelectedText;
		extern RGBA titleline;
		extern RGBA scrollerr;
		extern RGBAF integre;
		extern RGBA title_sprite;
		extern RGBA title_sprite2;
		extern RGBAF title_end;
		extern RGBAF integre2;
		extern RGBAF titleText3;
		extern RGBAF titleText2;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBAF optionText;
		extern RGBAF optionTextt;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF arrow2;
		extern RGBAF arrowww;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA optionRectt;
		extern RGBA scroller;
		extern RGBA scroller_pos_now;
		extern RGBA line;
		extern RGBA Endrect;
		extern RGBA linego;
		extern RGBA primary;
		extern RGBA secondary;
		extern RGBA Endrectlol;
		extern RGBA Endrectloll;
		extern RGBA Endrectloool;
		extern RGBA titleEndd;
		//extern RGBA HUD_COLOUR_PAUSE_BGR;
		//extern RGBA HUD_COLOUR_WAYPOINTR;
		//extern RGBA HUD_COLOUR_MICHAELR;
		//extern RGBA HUD_COLOUR_FRANKLINR;
		//extern RGBA HUD_COLOUR_TREVORR;
		//extern RGBA HUD_COLOUR_FREEMODER;



		extern RGBA endarrow;
		extern bool DrawTextOutline;
		extern bool displayEnd;

		extern int keyPressDelay;
		extern int keyPressPreviousTick;
		extern int keyPressDelay2;
		extern int keyPressPreviousTick2;
		extern int keyPressDelay3;
		extern int keyPressPreviousTick3;
		extern int openKey;
		extern int backKey;
		extern int upKey;
		extern int downKey;
		extern int leftKey;
		extern int rightKey;
		extern int selectKey;
		extern int arrowupKey;
		extern int arrowdownKey;
		extern int arrowleftKey;
		extern int arrowrightKey;
		extern int enterKey;
		extern int deleteKey;
		extern int openpress;
		extern int downpress;
		extern int uppress;
		extern int backpress;
		extern int click;
		extern int leftpress;
		extern int rightpress;


	}
	namespace MenuLevelHandler {
		void MoveMenu(SubMenus menu);
		void BackMenu();
	}
	namespace Checks {
		void Controlls();
		void Keys();
	}
	namespace Tools {
		char* StringToChar(std::string string);
	}
	namespace Files {
		void WriteStringToIni(std::string string, std::string file, std::string app, std::string key);
		std::string ReadStringFromIni(std::string file, std::string app, std::string key);
		void WriteIntToIni(int intValue, std::string file, std::string app, std::string key);
		int ReadIntFromIni(std::string file, std::string app, std::string key);
		void WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key);
		float ReadFloatFromIni(std::string file, std::string app, std::string key);
		void WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key);
		bool ReadBoolFromIni(std::string file, std::string app, std::string key);
		namespace StyleSaver {
			void SaveStyles();
			void LoadStyles();

		}
	}
	bool MenuPlayer(const char * option, std::string headShot, SubMenus newSub, int player);
	bool MenuPlayer(const char* option, std::string headShot, SubMenus newSub, int player, std::function<void()> function);
	void DrawGlare(float pX, float pY, float scaleX, float scaleY, int red, int green, int blue, int alpha);
	void render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g, const int b);
	void DRAW_TEXTURE(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	void Title(const char* title);
	void Subtitle(const char * title);
	void info(const char * title);
	void PlayerInfoTitle(char* text);
	void PlayerInfoLine(char* text, short line);
	void PremiumTitle(const char * title);
	void Vehicle(std::string texture1, std::string texture2);
	void Vehicle2(std::string texture1, std::string texture2);
	void Vehicle(std::string texture1, std::string texture2);
	//void Speedometer(char* text);
	//void fps(char* text);
	void AddSmallTitle(char* text);
	void Colorbox(std::string texture1, std::string texture2, RGBA rgba);
	void Colorbox2(std::string texture1, std::string texture2, int r, int g, int b, int a);
	void AddSmallInfo(char* text, short line);
	void AddSmallTitle2(char* text);
	void AddSmallInfo2(char* text, short line);
	//void AddSmallTitle3(char* text);
	void AddSmallInfo3(char* text, short line);
	bool Break(const char* option);
	bool Float(const char* option, float& _float, int min, int max);
	bool Float(const char* option, float& _float, int min, int max, int step);
	bool Option(const char* option);
	bool Optionn(const char* option);
	bool Option(const char* option, std::function<void()> function);
	bool MenuOption(const char* option, SubMenus newSub);
	bool MenuOptionn(const char* option, SubMenus newSub);
	bool MenuOption(const char* option, SubMenus newSub, std::function<void()> function);
	bool MenuOptionn(const char* option, SubMenus newSub, std::function<void()> function);
	bool Toggle(const char* option, bool& b00l);
	bool Toggle(const char* option, bool& b00l, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max);
	bool Int(const char* option, int& _int, int min, int max, int step);
	bool Int(const char* option, int& _int, int min, int max, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max, int step, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max);
	//bool Float(const char * option, float & _float, float min, float max);
	bool Float(const char* option, float& _float, int min, int max, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max, int step);
	bool Float(const char* option, float& _float, int min, int max, int step, std::function<void()> function);
	bool IntVector(const char* option, std::vector<int> Vector, int& position);
	bool IntVector(const char* option, std::vector<int> Vector, int& position, std::function<void()> function);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position, std::function<void()> function);
	//bool StringVector(const char* option, std::string Vector, int& position);
	//bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	//bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	//bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	//bool StringVector(const char * option, std::vector<std::string> Vector, int & position);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	//bool Teleport(const char* option, Vector3 coords);
	//bool Teleport(const char* option, Vector3 coords, std::function<void()> function);

	bool ListVector(const char * option, std::vector<char*> Vector, int & position);
	void End(const char * title);
}
