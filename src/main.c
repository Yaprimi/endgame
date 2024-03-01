#include "header.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
// start or restart a timer with a specific lifetime


void StartTimer(Timer* timer, float lifetime)
{
    if (timer != NULL)
        timer->Lifetime = lifetime;
}

// update a timer with the current frame time
void UpdateTimer(Timer* timer)
{
    // subtract this frame from the timer if it's not allready expired
    if (timer != NULL && timer->Lifetime > 0)
        timer->Lifetime -= GetFrameTime();
}

// check if a timer is done.
bool TimerDone(Timer* timer)
{
    if (timer != NULL)
        return timer->Lifetime <= 0;

	return false;
}
int main(void)
{
    characters main;
    main.x = 741;
    main.y = 526;
    main.size.x = 30;
    main.size.y = 54;
    Rectangle main_size = {main.x,main.y, main.size.x,main.size.y};
    Rectangle main_char_col = { main.x, main.y, main.size.x,main.size.y };

    srand (time(NULL));
    int currentFrame = 0;
    int currentFrame_p = 0;
    int currentFrame_c = 0;
    int framesCounter_g = 0;
    int framesCounter_p = 0;
    int frameCounter_c = 0;
    int framesCounter = 0;
    int framesSpeed = 8;  
    bool pause = false;
    bool exitWindowRequested = false;   // Flag to request window to exit
    bool exitWindow = false;
    bool showRectangle = false;
    bool btnActive = false;
    int boxASpeedX = 4;
    bool col_met[3] = {false, false, false};
    float speed = 8;
    bool col_black = false;
    bool restart = false;
    bool colision_wall_check[26] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
    bool colision_rune_check[6] = {false,false,false,false,false,false};
    Timer Cutscena = { 2 };
    Timer Cutscena_1 = { 2 };
    float timer_1 = 3.3 ;
    float timer = 1;
    Timer BlackHole = { 2 };
    float Time = 45.0f;
    float array_col [4] = {0,0,0,0};
    bool stop_move = false;
    bool executed = false;
    bool array_draw_rune [6] = {false,false,false,false,false,false};
    bool settings = false;
    float volume = 1;
    float scrollSpeed = 0.1;
    bool settings_load = false;
    float time_music_len = 0;
    bool rune_1_b = false; 
    bool rune_2_b = false; 
    bool rune_3_b = false; 
    bool rune_4_b = false; 
    bool rune_5_b = false; 
    bool rune_6_b = false; 
    bool portal_b = false;

    SetRandomSeed(255);
    InitWindow(screenWidth, screenHeight, "Cosmic Chronicles");
    InitAudioDevice(); // Audio initialization

    GameScreen currentScreen = LOGO;
    Button currentbutton = Button_resume;

    SetExitKey(KEY_NULL); 

    Sound jump = LoadSound("resource/sounds/jump.wav");
    Music track = LoadMusicStream("resource/music/03 Clockwise Operetta.mp3");
    Music main_menu_track  = LoadMusicStream("resource/music/sacred-garden-10377.mp3");
    Music level1 = LoadMusicStream("resource/music/warrior_medium-192841.mp3");
    Music level2 = LoadMusicStream("resource/music/medieval-fantasy-142837.mp3");
    Music black_hole_sound = LoadMusicStream("resource/music/Black_hole_sound.mp3");
    Sound shine = LoadSound("resource/music/shine_sound.mp3");
    Sound portal_sound = LoadSound("resource/music/portal_sound.mp3");
   
    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D Josef_walk_right = LoadTexture("resource/characters/Character_anim_right.png"); 
    Texture2D Josef_walk_left = LoadTexture("resource/characters/Character_anim_left.png");
    Texture2D main_char = LoadTexture("resource/characters/character.png");
    Texture2D map = LoadTexture("resource/textures/Space_background1.png");
    Texture2D title= LoadTexture("resource/textures/Title.png");
    Texture2D button = LoadTexture("resource/textures/button.png");
    Texture2D button_main_menu = LoadTexture("resource/textures/button_main_menu.png");
    Texture2D Portal = LoadTexture("resource/textures/Portal.png");
    Texture2D Portal_blue = LoadTexture("resource/textures/portal_blue.png");
    Texture2D Portal_red = LoadTexture("resource/textures/portal_red.png");
    Texture2D Menu_background = LoadTexture("resource/textures/Menu_background.png");
    Texture2D button_resume = LoadTexture("resource/textures/button_resume.png");
    Texture2D button_quit = LoadTexture("resource/textures/button_quit.png");
    Texture2D button_settings = LoadTexture("resource/textures/button_settings.png");
    Texture2D spaceship = LoadTexture("resource/textures/Rocket_2.png");
    Texture2D meteorite = LoadTexture("resource/textures/Meterorite.png");
    Texture2D black_hole = LoadTexture("resource/textures/Black_Hole.png");
    Texture2D white_hole = LoadTexture("resource/textures/White_Hole.png");
    Texture2D dune_map = LoadTexture("resource/textures/Dune_map_2D.png");
    Texture2D rune_1 = LoadTexture("resource/textures/Runa_1.png");
    Texture2D rune_2 = LoadTexture("resource/textures/Runa_2.png");
    Texture2D rune_3 = LoadTexture("resource/textures/Runa_3.png");
    Texture2D rune_4 = LoadTexture("resource/textures/Runa_4.png");
    Texture2D rune_5 = LoadTexture("resource/textures/Runa_5.png");
    Texture2D rune_6 = LoadTexture("resource/textures/Runa_6.png");
    Texture2D dune_map_cutsc = LoadTexture("resource/textures/dune_map_cutsc.png");
    Texture2D rune_shine_1 = LoadTexture("resource/textures/Runa_shine_1.png");
    Texture2D rune_shine_2 = LoadTexture("resource/textures/Runa_shine_2.png");
    Texture2D rune_shine_3 = LoadTexture("resource/textures/Runa_shine_3.png");
    Texture2D rune_shine_4 = LoadTexture("resource/textures/Runa_shine_4.png");
    Texture2D rune_shine_5 = LoadTexture("resource/textures/Runa_shine_5.png");
    Texture2D rune_shine_6 = LoadTexture("resource/textures/Runa_shine_6.png");
    Texture2D back_settings = LoadTexture("resource/textures/Settings_back.png");
    Texture2D rocket_anim = LoadTexture("resource/textures/Rocket_2_anim.png");
    Texture2D logo = LoadTexture("resource/textures/Logo.png");

    float scrollingBack = 0.0f;

    characters spaceship_c;
    spaceship_c.x = 0;
    spaceship_c.y = screenHeight / 2;
    spaceship_c.size.x = spaceship.width;
    spaceship_c.size.y = spaceship.height;
    Rectangle spaceship_col = {spaceship_c.x, spaceship_c.y, spaceship.width,spaceship.height};
    Rectangle black_hole_col = {screenWidth - black_hole.width,screenHeight / 2 - black_hole.height/2,black_hole.width - 20, black_hole.height};
    Rectangle wall1 = {604,396,342,72};
    Rectangle wall2 = {875,330,405,71};
    Rectangle wall3 = {604,207,72,189};
    Rectangle wall4 = {537,12,67,260};
    Rectangle wall5 = {267,12,270,67};
    Rectangle wall6 = {267,79,71,194};
    Rectangle wall7 = {135,201,132,70};
    Rectangle wall8 = {135,273,72,135};
    Rectangle wall9 = {1,338,135,70};
    Rectangle wall10 = {1,408,69,189};
    Rectangle wall11 = {70,527,198,71};
    Rectangle wall12 = {268,526,71,194};
    Rectangle wall13 = {340,662,404,58};
    Rectangle wall14 = {670,526,71,137};
    Rectangle wall15 = {741,590,539,71};
    Rectangle wall16 = {807,520,139,70};
    Rectangle wall17 = {1209,401,70,189};
    Rectangle wall18 = {267,329,72,139};
    Rectangle wall19 = {403,329,143,140};
    Rectangle wall20 = {402,528,207,72};
    Rectangle col_wall = {0,0,0,0};
    Rectangle col_rune = {0,0,0,0};
    Rectangle rune_col = {0,0,0,0};
    Rectangle portal_red = {1152,407,55,55};
    Rectangle portal_blue = {1152,535,55,55};


    Rectangle array_wall[20] = {wall1,wall2,wall3,wall4,wall5,wall6,wall7,wall8,wall9,wall10,wall11,wall12,wall13,wall14,wall15,wall16,wall17,wall18,wall19,wall20};
    //Colision//////////////////////////////////////////////////
     //platform
     GameObject meteorite_o_1;
     meteorite_o_1.destRec.width = meteorite.width;
     meteorite_o_1.destRec.height = meteorite.height;
     meteorite_o_1.destRec.x = screenWidth - meteorite.width;
     meteorite_o_1.destRec.y = screenHeight - meteorite.height - 200;

     meteorite_o_1.sourceRec.height = 0.0f;
     meteorite_o_1.sourceRec.width = 0.0f;
     meteorite_o_1.sourceRec.x = (float)meteorite.width;
     meteorite_o_1.sourceRec.y = (float)meteorite.height;

     meteorite_o_1.origin.x = 0;
     meteorite_o_1.origin.y = 0;


     GameObject meteorite_o_2;
     meteorite_o_2.destRec.width = meteorite.width;
     meteorite_o_2.destRec.height = meteorite.height;
     meteorite_o_2.destRec.x = screenWidth - meteorite.width - 150;
     meteorite_o_2.destRec.y = screenHeight - meteorite.height - 400;

     meteorite_o_2.sourceRec.height = 0.0f;
     meteorite_o_2.sourceRec.width = 0.0f;
     meteorite_o_2.sourceRec.x = (float)meteorite.width;
     meteorite_o_2.sourceRec.y = (float)meteorite.height;

     meteorite_o_2.origin.x = 0;
     meteorite_o_2.origin.y = 0;

    GameObject meteorite_o_3;
     meteorite_o_3.destRec.width = meteorite.width;
     meteorite_o_3.destRec.height = meteorite.height;
     meteorite_o_3.destRec.x = screenWidth - meteorite.width - 100;
     meteorite_o_3.destRec.y = screenHeight - meteorite.height - 550;

     meteorite_o_3.sourceRec.height = 0.0f;
     meteorite_o_3.sourceRec.width = 0.0f;
     meteorite_o_3.sourceRec.x = (float)meteorite.width;
     meteorite_o_3.sourceRec.y = (float)meteorite.height;

     meteorite_o_3.origin.x = 0;
     meteorite_o_3.origin.y = 0;

    GameObject rune_o_1;
    rune_o_1.destRec.width = rune_1.width;
    rune_o_1.destRec.height = rune_1.height;
    rune_o_1.destRec.x = 353;
    rune_o_1.destRec.y = 148;

    rune_o_1.sourceRec.height = 0;
    rune_o_1.sourceRec.width = 0;
    rune_o_1.sourceRec.x = rune_1.width;
    rune_o_1.sourceRec.y = rune_1.height;

    rune_o_1.origin.x = 0;
    rune_o_1.origin.y = 0;

    GameObject rune_o_2;
    rune_o_2.destRec.width = rune_2.width;
    rune_o_2.destRec.height = rune_2.height;
    rune_o_2.destRec.x = 480;
    rune_o_2.destRec.y = 216;

    rune_o_2.sourceRec.height = 0;
    rune_o_2.sourceRec.width = 0;
    rune_o_2.sourceRec.x = rune_2.width;
    rune_o_2.sourceRec.y = rune_2.height;

    rune_o_2.origin.x = 0;
    rune_o_2.origin.y = 0;

    GameObject rune_o_3;
    rune_o_3.destRec.width = rune_3.width;
    rune_o_3.destRec.height = rune_3.height;
    rune_o_3.destRec.x = 354;
    rune_o_3.destRec.y = 282;

    rune_o_3.sourceRec.height = 0;
    rune_o_3.sourceRec.width = 0;
    rune_o_3.sourceRec.x = rune_3.width;
    rune_o_3.sourceRec.y = rune_3.height;

    rune_o_3.origin.x = 0;
    rune_o_3.origin.y = 0;

    GameObject rune_o_4;
    rune_o_4.destRec.width = rune_4.width;
    rune_o_4.destRec.height = rune_4.height;
    rune_o_4.destRec.x = 546;
    rune_o_4.destRec.y = 605;

    rune_o_4.sourceRec.height = 0;
    rune_o_4.sourceRec.width = 0;
    rune_o_4.sourceRec.x = rune_4.width;
    rune_o_4.sourceRec.y = rune_4.height;

    rune_o_4.origin.x = 0;
    rune_o_4.origin.y = 0;

    GameObject rune_o_5;
    rune_o_5.destRec.width = rune_5.width;
    rune_o_5.destRec.height = rune_5.height;
    rune_o_5.destRec.x = 351;
    rune_o_5.destRec.y = 479;

    rune_o_5.sourceRec.height = 0;
    rune_o_5.sourceRec.width = 0;
    rune_o_5.sourceRec.x = rune_5.width;
    rune_o_5.sourceRec.y = rune_5.height;

    rune_o_5.origin.x = 0;
    rune_o_5.origin.y = 0;

    GameObject rune_o_6;
    rune_o_6.destRec.width = rune_6.width;
    rune_o_6.destRec.height = rune_6.height;
    rune_o_6.destRec.x = 144;
    rune_o_6.destRec.y = 476;

    rune_o_6.sourceRec.height = 0;
    rune_o_6.sourceRec.width = 0;
    rune_o_6.sourceRec.x = rune_6.width;
    rune_o_6.sourceRec.y = rune_6.height;

    rune_o_6.origin.x = 0;
    rune_o_6.origin.y = 0;

    GameObject portal;
    portal.destRec.width = screenWidth-45;
    portal.destRec.height = screenHeight-144;
    portal.destRec.x = (float)Portal.width;
    portal.destRec.y = (float)Portal.height;

    portal.sourceRec.width = 0.0f;
    portal.sourceRec.height = 0.0f;
    portal.sourceRec.x = (float)Portal.width;
    portal.sourceRec.y = (float)Portal.height;
    portal.origin.x = 0;
    portal.origin.y = 0;

    Rectangle meteorite_col_1 = {meteorite_o_1.destRec.x, meteorite_o_1.destRec.y,meteorite_o_1.destRec.width,meteorite_o_1.destRec.height};
    Rectangle meteorite_col_2 = {meteorite_o_2.destRec.x, meteorite_o_2.destRec.y,meteorite_o_2.destRec.width,meteorite_o_2.destRec.height};
    Rectangle meteorite_col_3 = {meteorite_o_3.destRec.x, meteorite_o_3.destRec.y,meteorite_o_3.destRec.width,meteorite_o_3.destRec.height};

    Rectangle rune_o_1_col = {rune_o_1.destRec.x,rune_o_1.destRec.y, rune_o_1.destRec.width, rune_o_1.destRec.height};
    Rectangle rune_o_2_col = {rune_o_2.destRec.x,rune_o_2.destRec.y, rune_o_2.destRec.width, rune_o_2.destRec.height};
    Rectangle rune_o_3_col = {rune_o_3.destRec.x,rune_o_3.destRec.y, rune_o_3.destRec.width, rune_o_3.destRec.height};
    Rectangle rune_o_4_col = {rune_o_4.destRec.x,rune_o_4.destRec.y, rune_o_4.destRec.width, rune_o_4.destRec.height};
    Rectangle rune_o_5_col = {rune_o_5.destRec.x,rune_o_5.destRec.y, rune_o_5.destRec.width, rune_o_5.destRec.height};
    Rectangle rune_o_6_col = {rune_o_6.destRec.x,rune_o_6.destRec.y, rune_o_6.destRec.width, rune_o_6.destRec.height};
    Rectangle array_rune[6] = {rune_o_1_col,rune_o_2_col,rune_o_3_col,rune_o_4_col,rune_o_5_col,rune_o_6_col,};
    Rectangle boxCollision = { 0 }; // Collision rectangle

    int screenUpperLimit = 40;      // Top menu limits

    bool collision = false;  
    bool collision_exit = false;       // Collision detection
    ////////////////////////////////////////////////////////

    Vector2 characterPosition = { screenWidth / 2, screenHeight / 2 };
    Vector2 mousePosition;
    Vector2 targetPosition = { -1, -1 };
    Vector2 position = { 350.0f, 280.0f };
    Vector2 mousePoint = { 0.0f, 0.0f };
    Vector2 main_char_pos = {main.x, main.y}; 

    float frameHeight = (float)button.height/NUM_FRAMES;

    Rectangle frameRec = { 0.0f, 0.0f, (float)rocket_anim.width/6, (float)rocket_anim.height };
    Rectangle frameRec_portal_blue = { 0.0f, 0.0f, 64, (float)portal_blue.height };
    Rectangle frameRec_character = {0.0f, 0.0f, 30, (float)portal_blue.height};
    Rectangle sourceRec = { 0, 0, (float)button.width, frameHeight };
    Rectangle sourceRec_r = { 0, 0, (float)button.width, frameHeight };
    Rectangle sourceRec_q = { 0, 0, (float)button.width, frameHeight };
    Rectangle sourceRec_s = { 0, 0, (float)button.width, frameHeight };

    Rectangle btnBounds = { screenWidth/2.0f - button.width/2.0f, screenHeight/2.0f - button.height/NUM_FRAMES/2.0f, (float)button.width, frameHeight };
    Rectangle btnBounds_main_menu = { screenWidth/2 - button_main_menu.width/2, screenHeight/2- button_main_menu.height/2 + 200, (float)button.width, frameHeight };
    Rectangle btnBounds_resume = {screenWidth/2 - button_resume.width/2, screenHeight/2 - button_resume.height/2, (float)button.width, frameHeight };
    Rectangle btnBounds_quit = {screenWidth/2 - button_resume.width/2, screenHeight/2 - button_resume.height/2 + 295, (float)button.width, frameHeight };
    Rectangle btnBounds_s = {screenWidth/2 - button_settings.width/2, screenHeight/2 - button_settings.height/2 + 195, (float)button.width, frameHeight};
    // Define button bounds on screen
    
    int btnState = 0;             // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated         // Number of spritesheet frames shown by second
    int btnState_r = 0;
    bool btnAction_r = false;
    int btnState_q = 0;
    bool btnAction_q = false; 
    int btnState_s = 0;
    bool btnAction_s = false; 
    
    SetTargetFPS(40);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!exitWindow)   // Detect window close button or X key
    {
        const float dt = GetFrameTime();

        col_black = CheckCollisionRecs(spaceship_col, black_hole_col);

        if(IsKeyDown(KEY_R) || restart == true){
            for (int i = 0;i < 6;i++){
                array_draw_rune [i] = false;
            }
            executed = false;
            Rectangle btnBounds_s = {screenWidth/2 - button_settings.width/2, screenHeight/2 - button_settings.height/2 + 195, (float)button.width, frameHeight};
            float Time = 45.0f;

            portal.destRec.width = screenWidth-45;
    portal.destRec.height = screenHeight-144;
    portal.destRec.x = (float)Portal.width;
    portal.destRec.y = (float)Portal.height;

    portal.sourceRec.width = 0.0f;
    portal.sourceRec.height = 0.0f;
    portal.sourceRec.x = (float)Portal.width;
    portal.sourceRec.y = (float)Portal.height;
    portal.origin.x = 0;
    portal.origin.y = 0;

    Rectangle meteorite_col_1 = {meteorite_o_1.destRec.x, meteorite_o_1.destRec.y,meteorite_o_1.destRec.width,meteorite_o_1.destRec.height};
    Rectangle meteorite_col_2 = {meteorite_o_2.destRec.x, meteorite_o_2.destRec.y,meteorite_o_2.destRec.width,meteorite_o_2.destRec.height};
    Rectangle meteorite_col_3 = {meteorite_o_3.destRec.x, meteorite_o_3.destRec.y,meteorite_o_3.destRec.width,meteorite_o_3.destRec.height};
    Rectangle main_char_col = { main_char.width, main_char.height, 66,144 };

    Rectangle boxCollision = { 0 }; // Collision rectangle

    screenUpperLimit = 40;      // Top menu limits

    collision = false;  
    collision_exit = false;       // Collision detection
    ////////////////////////////////////////////////////////

    Vector2 characterPosition = { screenWidth / 2, screenHeight / 2 };
    Vector2 mousePosition;
    Vector2 targetPosition = { -1, -1 };
    Vector2 position = { 350.0f, 280.0f };
    Vector2 mousePoint = { 0.0f, 0.0f };
    Vector2 main_char_pos = {main.x, main.y}; 


     meteorite_o_1.destRec.width = meteorite.width;
     meteorite_o_1.destRec.height = meteorite.height;
     meteorite_o_1.destRec.x = screenWidth - meteorite.width;
     meteorite_o_1.destRec.y = screenHeight - meteorite.height - 200;

     meteorite_o_1.sourceRec.height = 0.0f;
     meteorite_o_1.sourceRec.width = 0.0f;
     meteorite_o_1.sourceRec.x = (float)meteorite.width;
     meteorite_o_1.sourceRec.y = (float)meteorite.height;

     meteorite_o_1.origin.x = 0;
     meteorite_o_1.origin.y = 0;


     meteorite_o_2.destRec.width = meteorite.width;
     meteorite_o_2.destRec.height = meteorite.height;
     meteorite_o_2.destRec.x = screenWidth - meteorite.width - 150;
     meteorite_o_2.destRec.y = screenHeight - meteorite.height - 400;

     meteorite_o_2.sourceRec.height = 0.0f;
     meteorite_o_2.sourceRec.width = 0.0f;
     meteorite_o_2.sourceRec.x = (float)meteorite.width;
     meteorite_o_2.sourceRec.y = (float)meteorite.height;

     meteorite_o_2.origin.x = 0;
     meteorite_o_2.origin.y = 0;

     meteorite_o_3.destRec.width = meteorite.width;
     meteorite_o_3.destRec.height = meteorite.height;
     meteorite_o_3.destRec.x = screenWidth - meteorite.width - 100;
     meteorite_o_3.destRec.y = screenHeight - meteorite.height - 550;

     meteorite_o_3.sourceRec.height = 0.0f;
     meteorite_o_3.sourceRec.width = 0.0f;
     meteorite_o_3.sourceRec.x = (float)meteorite.width;
     meteorite_o_3.sourceRec.y = (float)meteorite.height;

     meteorite_o_3.origin.x = 0;
     meteorite_o_3.origin.y = 0;


    spaceship_c.x = 0;
    spaceship_c.y = screenHeight / 2;
    spaceship_c.size.x = spaceship.width;
    spaceship_c.size.y = spaceship.height;
    Rectangle spaceship_col = {spaceship_c.x, spaceship_c.y, spaceship.width,spaceship.height};
    main.x = screenWidth / 2;
    main.y = screenHeight / 2;
    main.size.x = 30;
    main.size.y = 54;

    int currentFrame = 0;
    framesCounter = 0;
    framesSpeed = 8;  
    pause = false;
    exitWindowRequested = false;   // Flag to request window to exit
    exitWindow = false;
    showRectangle = false;
    btnActive = false;
    boxASpeedX = 4;
    bool col_met[3] = {false, false, false};
        }

        if (WindowShouldClose() || IsKeyPressed(KEY_X)) {
            exitWindowRequested = true;
        }

        if (exitWindowRequested)
        {
            // A request for close window has been issued, we can save data before closing
            // or just show a message asking for confirmation
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)){
            pause = false;
            exitWindowRequested = false;
            }
        }

         if (IsKeyPressed(KEY_P)){ 
            pause = !pause;
         }

        //Update
        //----------------------------------------------------------------------------------
        framesCounter_g++;
        framesCounter_p++;
        frameCounter_c++;
        mousePoint = GetMousePosition();
        btnAction = false;

        if (framesCounter_g >= (60/framesSpeed))
        {
            framesCounter_g = 0;
            currentFrame++;

            if (currentFrame > 5) currentFrame = 0;

            frameRec.x = (float)currentFrame*(float)rocket_anim.width/6;
        }

         if (framesCounter_p >= (60/framesSpeed))
        {
            framesCounter_p = 0;
            currentFrame_p++;

            if (currentFrame_p > 8) currentFrame_p = 0;

            frameRec_portal_blue.x = (float)currentFrame_p*(float)Portal_blue.width/9;
        }

         if (frameCounter_c >= (60/framesSpeed))
        {
            frameCounter_c = 0;
            currentFrame_c++;

            if (currentFrame_c > 8) currentFrame_c = 0;

            frameRec_character.x = (float)currentFrame_c * 30;
        }

           switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 240)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                    PlayMusicStream(main_menu_track);
                    UpdateMusicStream(main_menu_track);
                    SetMusicVolume(main_menu_track, volume);
                    Rectangle btnBounds_s = {screenWidth/2 - button_settings.width/2, screenHeight/2 - button_settings.height/2 + 195, (float)button.width, frameHeight};
                if(!settings){
                 if (IsKeyPressed(KEY_ESCAPE)) {
                exitWindowRequested = !exitWindowRequested;
                pause =!pause;
                }
                }

                if(settings){
                    if (IsKeyPressed(KEY_ESCAPE)) {
                settings = !settings;
                }
                if(volume > 1){
                        volume = 1;
                    }
                if(volume <= 1){
                    
                 if (IsKeyDown(KEY_DOWN)) volume -= 0.1f;
                else if (IsKeyDown(KEY_UP)) volume += 0.1f;
                
                volume += GetMouseWheelMove()*scrollSpeed;
                }
                }
                

                if(pause == true){
                    pause = !pause;
                }

        if (CheckCollisionPointRec(mousePoint, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        if (btnAction)
        {
            restart = true;
        currentScreen = First_level;
            // TODO: Any desired action
        }

        if (CheckCollisionPointRec(mousePoint, btnBounds_s))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_s = 2;
            else btnState_s = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_s = true;
        }
        else btnState_s = 0;

        if (btnAction_s)
        {
            settings = !settings;
            btnAction_s = false;

        }

        // Calculate button frame rectangle to draw depending on button state
        sourceRec_s.y = btnState_s*frameHeight;

        sourceRec.y = btnState*frameHeight;

            } break;
            case First_level:
            {
                map = LoadTexture("resource/textures/Space_background1.png");
                spaceship = LoadTexture("resource/textures/Rocket_2.png");
                meteorite = LoadTexture("resource/textures/Meterorite.png");
                black_hole = LoadTexture("resource/textures/Black_Hole.png");
                SetMusicVolume(level1, volume);
                settings_load = false;
                btnBounds_s.y = screenHeight/2 - button_settings.height/2 + 105;

                 PlayMusicStream(level1);
                    UpdateMusicStream(level1);
                restart = false;
                StartTimer(&BlackHole, Time);
                if(!exitWindowRequested){
                     if(settings){
                    if (IsKeyPressed(KEY_ESCAPE)) {
                settings = !settings;
                }
                if(volume > 1){
                        volume = 1;
                    }
                if(volume <= 1){
                    
                 if (IsKeyDown(KEY_DOWN)) volume -= 0.1f;
                else if (IsKeyDown(KEY_UP)) volume += 0.1f;
                
                volume += GetMouseWheelMove()*scrollSpeed;
                }
                }
                
                if(!pause){
                    spaceship_col.x = spaceship_c.x;
                    spaceship_col.y = spaceship_c.y;

                    if(TimerDone(&BlackHole)){
                        PlayMusicStream(black_hole_sound);
                        UpdateMusicStream(black_hole_sound);
                        if(spaceship_c.x < screenWidth - black_hole.width - 20){
                        spaceship_c.x += 8;

                        }
                        if(spaceship_c.y < screenHeight / 2){
                            if(speed > 1){
                        speed -= 0.05;
                            }
                        spaceship_c.y += speed;
                        }
                        if(spaceship_c.y > screenHeight / 2){
                            if(speed > 1){
                        speed -= 0.05;
                            }
                        spaceship_c.y -= speed;
                        }

                        if(col_black == true){
                            spaceship_col.x = spaceship.width + 20;
                            spaceship_col.y = screenHeight/2 + spaceship.height * 2;
                            currentScreen = Cutscena_Lv2;
                            framesCounter = 0;
                            restart = true;
                        }
                        
                }
                meteorite_o_1.destRec.x -= 10;
                meteorite_col_1.x = meteorite_o_1.destRec.x + 10;
                meteorite_col_1.y = meteorite_o_1.destRec.y + 10;

                meteorite_col_1.width = meteorite_o_1.destRec.width - 10;
                meteorite_col_1.height = meteorite_o_1.destRec.height - 10;

                meteorite_o_2.destRec.x -= 13;
                meteorite_col_2.x = meteorite_o_2.destRec.x + 10;
                meteorite_col_2.y = meteorite_o_2.destRec.y + 10;

                meteorite_col_2.width = meteorite_o_2.destRec.width - 10;
                meteorite_col_2.height = meteorite_o_2.destRec.height - 10;

                meteorite_o_3.destRec.x -= 9;
                meteorite_col_3.x = meteorite_o_3.destRec.x + 10;
                meteorite_col_3.y = meteorite_o_3.destRec.y + 10;

                meteorite_col_3.width = meteorite_o_3.destRec.width - 10;
                meteorite_col_3.height = meteorite_o_3.destRec.height - 10;
                if(!TimerDone(&BlackHole)){
                if (Time > 0){
                Time -= GetFrameTime();
                    }

                if(meteorite_o_1.destRec.x < 0 - meteorite.width){
                    meteorite_o_1.destRec.x = screenWidth;
                    meteorite_o_1.destRec.y = GetRandomValue(meteorite.height, screenHeight - meteorite.height);
                }

                if(meteorite_o_2.destRec.x < 0 - meteorite.width){
                    meteorite_o_2.destRec.x = screenWidth;
                    meteorite_o_2.destRec.y = GetRandomValue(meteorite.height, screenHeight - meteorite.height);
                }

                if(meteorite_o_3.destRec.x < 0 - meteorite.width){
                    meteorite_o_3.destRec.x = screenWidth;
                    meteorite_o_3.destRec.y = GetRandomValue(meteorite.height, screenHeight - meteorite.height);
                }
                col_met[0] = CheckCollisionRecs(meteorite_col_1,spaceship_col);
                col_met[1] = CheckCollisionRecs(meteorite_col_2,spaceship_col);
                col_met[2] = CheckCollisionRecs(meteorite_col_3,spaceship_col);
                for(int i = 0; i < 3; i++) {
                    if(col_met[i]) {
                        pause =!pause;
                        break;
                    }
                }

                scrollingBack -= 1.0f;
                }
                if (scrollingBack <= -map.width) scrollingBack = 0;

                if(IsKeyDown(KEY_A)){
                    spaceship_c.x += -7;
                }
                if(IsKeyDown(KEY_D)){
                    spaceship_c.x += 7;
                }
                if(IsKeyDown(KEY_S)){
                    spaceship_c.y += 7;
                }
                if(IsKeyDown(KEY_W)){
                    spaceship_c.y -= 7;
                }
                }

        if(showRectangle){
            if (CheckCollisionPointRec(mousePoint, btnBounds_s))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_s = 2;
            else btnState_s = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_s = true;
        }
        else btnState_s = 0;

        if (btnAction_s)
        {
            settings = !settings;
            btnAction_s = false;

        }

        // Calculate button frame rectangle to draw depending on button state
        sourceRec_s.y = btnState_s*frameHeight;

        if (CheckCollisionPointRec(mousePoint, btnBounds_main_menu))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        if (btnAction)
        {
        settings_load = true;
        currentScreen = TITLE;
        showRectangle = !showRectangle;
            // TODO: Any desired action
        }
        
        if (CheckCollisionPointRec(mousePoint, btnBounds_resume))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_r = 2;
            else btnState_r = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_r = !btnAction_r;
        }
        else btnState_r = 0;
        for(int i = 0; i < 3;i++){
        if(col_met[i] == false){
            if (btnAction_r)
            {
            showRectangle = !showRectangle;
            btnAction_r = !btnAction_r;
            pause = !pause;
            }
        }
        }

         if (CheckCollisionPointRec(mousePoint, btnBounds_quit))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_q = 2;
            else btnState_q = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_q = !btnAction_q;
        }
        else btnState_q = 0;
        if (btnAction_q) {
            showRectangle = !showRectangle;
            btnAction_q = !btnAction_q;
            exitWindowRequested = true;
            pause = !pause;
        }
        }   

        }   
        

        // Calculate button frame rectangle to draw depending on button state

        sourceRec_q.y = btnState_q * frameHeight;

        sourceRec.y = btnState * frameHeight;

        sourceRec_r.y = btnState_r*frameHeight;

                 //Colision/////////////////////////
         // if (!pause){
               // platform .x += boxASpeedX;
               // destRec.x += boxASpeedX;
         // } 

        // Update player-controlled-box (box02)
        main_char_col.x = main.x;
        main_char_col.y = main.y;
        
        //collision_exit = CheckCollisionRecs(portal.destRec, main_char_col);
        //if (collision_exit){
           // currentScreen = Second_level;
        //}


        if (IsKeyPressed(KEY_ESCAPE)) {
        showRectangle = !showRectangle;
        if(col_met[0] == false){
                pause =!pause;
        }
        if(col_met[1] == false){
                pause =!pause;
        }
        if(col_met[2] == false){
                pause =!pause;
        }
        }
        //////////////////////////////////////////
                
            } break;
            case Cutscena_Lv2:{
                btnBounds_s.y = screenHeight/2 - button_settings.height/2 + 105;
                PlayMusicStream(level2);
                UpdateMusicStream(level2);
                SetMusicVolume(level2, volume);
                restart = false;

                if(!pause){
                StartTimer(&Cutscena, timer);
                StartTimer(&Cutscena_1, timer_1);
                if (timer > 0){
                timer -= GetFrameTime();
                    }
                    if (timer_1 > 0){
                        timer_1 -= GetFrameTime();
                    }
                if(!TimerDone(&Cutscena)){
                PlayMusicStream(black_hole_sound);
                UpdateMusicStream(black_hole_sound);
                spaceship_col.x += 5;
                spaceship_col.y += 3;
                }

                if(!executed && TimerDone(&Cutscena)){
                    main_char_col.x = spaceship_col.x;
                    main_char_col.y = spaceship_col.y;
                    executed = true;
                }

                if(!TimerDone(&Cutscena_1) && TimerDone(&Cutscena)){
                main_char_col.x += 4;
                main_char_col.y -= 1;
                }

                if(TimerDone(&Cutscena_1)){
                    currentScreen = Second_level;
                    executed = false;
                    restart = true;
                }
                }

        if(!settings){
        if (IsKeyPressed(KEY_ESCAPE)) {
            showRectangle = !showRectangle;
            pause =!pause;
        }
        }

        if(showRectangle){
        if (CheckCollisionPointRec(mousePoint, btnBounds_main_menu))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        if (btnAction)
        {
        settings_load = true;
        currentScreen = TITLE;
        showRectangle = !showRectangle;
            // TODO: Any desired action
        }
        
        if (CheckCollisionPointRec(mousePoint, btnBounds_resume))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_r = 2;
            else btnState_r = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_r = !btnAction_r;
        }
        else btnState_r = 0;
        if (btnAction_r){
        showRectangle = !showRectangle;
        btnAction_r = !btnAction_r;
        pause = !pause;
            // TODO: Any desired action
        }

         if (CheckCollisionPointRec(mousePoint, btnBounds_quit))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_q = 2;
            else btnState_q = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_q = !btnAction_q;
        }
        else btnState_q = 0;
        if (btnAction_q) {
            showRectangle = !showRectangle;
            btnAction_q = !btnAction_q;
            exitWindowRequested = true;
        }

        if (CheckCollisionPointRec(mousePoint, btnBounds_s))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){ 
                btnState_s = 2;
                btnAction_s = true;
            }
            else btnState_s = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_s = true;
        }
        else btnState_s = 0;

        if (btnAction_s)
        {
            settings = !settings;
            btnAction_s = false;

        }

        } 

        sourceRec_s.y = btnState_s*frameHeight;

        sourceRec_q.y = btnState_q * frameHeight;

        sourceRec.y = btnState * frameHeight;

        sourceRec_r.y = btnState_r*frameHeight;
        if(pause){
                if(settings){
                    showRectangle = false;;
                    if (IsKeyPressed(KEY_ESCAPE)) {
                settings = !settings;
                pause = !pause;
                }
                if(volume > 1){
                        volume = 1;
                    }
                if(volume <= 1){
                    
                 if (IsKeyDown(KEY_DOWN)) volume -= 0.1f;
                else if (IsKeyDown(KEY_UP)) volume += 0.1f;
                
                volume += GetMouseWheelMove()*scrollSpeed;
                }
                }
                }

            }break;
            case Second_level:
            {            
                UnloadTexture(map);
                UnloadTexture(spaceship);
                UnloadTexture(meteorite);
                UnloadTexture(black_hole);
                UpdateMusicStream(level2);
                btnBounds_s.y = screenHeight/2 - button_settings.height/2 + 105;
                if(!exitWindowRequested){
                if(!showRectangle){
                if(!settings){
                 if(pause == true){
                    pause = !pause;
                }
                }
                }
                }
                if(!pause){
                if (restart || IsKeyPressed(KEY_R)){
                    main_char_col.x = 741;
                    main_char_col.y = 526;
                    executed = true;
                }
                if(settings){
                    if (IsKeyPressed(KEY_ESCAPE)) {
                settings = !settings;
                }
                if(volume > 1){
                        volume = 1;
                    }
                if(volume <= 1){
                    
                 if (IsKeyDown(KEY_DOWN)) volume -= 0.1f;
                else if (IsKeyDown(KEY_UP)) volume += 0.1f;
                
                volume += GetMouseWheelMove()*scrollSpeed;
                }
                }
            if(array_draw_rune[0] == true && array_draw_rune[1] == true && array_draw_rune[2] == true && array_draw_rune[3] == true && array_draw_rune[4] == true && array_draw_rune[5] == true){
                if(CheckCollisionRecs(portal_red,main_char_col)){
                    restart = true;
                    settings_load = true;
                    currentScreen = TITLE;
                }

                if(CheckCollisionRecs(portal_blue,main_char_col)){
                    
                }
            }

                restart = false;
                framesCounter++;
                if(!executed ){
                    main_char_col.x = 741;
                    main_char_col.y = 526;
                    executed = true;

                }
                const int vx = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
                const int vy = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);

                main_char_pos.x = main.x;
                main_char_pos.y = main.y;

                main_char_col.x += vx * 100 * dt;
                main_char_col.y += vy * 100 * dt;

                //main_char_col.x = main.x;
                //main_char_col.y = main.y;

                main.x = main_char_col.x;
                main.y = main_char_col.y;

        

        colision_rune_check[0] = CheckCollisionRecs(rune_o_1_col,main_char_col);
        colision_rune_check[1] = CheckCollisionRecs(rune_o_2_col,main_char_col);
        colision_rune_check[2] = CheckCollisionRecs(rune_o_3_col,main_char_col);
        colision_rune_check[3] = CheckCollisionRecs(rune_o_4_col,main_char_col);
        colision_rune_check[4] = CheckCollisionRecs(rune_o_5_col,main_char_col);
        colision_rune_check[5] = CheckCollisionRecs(rune_o_6_col,main_char_col);

        for (int i = 0; i < 20;i++){
        if (CheckCollisionRecs(array_wall[i],main_char_col)){
            col_wall = array_wall[i];
            const Vector2 center1 = { main.x + main.size.x / 2, main.y + main.size.y / 2 };
            const Vector2 center2 = { col_wall.x + col_wall.width / 2, col_wall.y + col_wall.height / 2 };
 
            // Calculation of the distance vector between the centers of the rectangles
            const Vector2 delta = Vector2Subtract(center1, center2);
 
            // Calculation of half-widths and half-heights of rectangles
            const Vector2 hs1 = { main.size.x*.5f, main.size.y*.5f };
            const Vector2 hs2 = { col_wall.width*.5f, col_wall.height*.5f };
 
            // Calculation of the minimum distance at which the two rectangles can be separated
            const float minDistX = hs1.x + hs2.x - fabsf(delta.x);
            const float minDistY = hs1.y + hs2.y - fabsf(delta.y);
 
            // Adjusted object position based on minimum distance
            if (minDistX < minDistY) {
                main_char_col.x += copysignf(minDistX, delta.x);
            } else {
                main_char_col.y += copysignf(minDistY, delta.y);
            }
        }
        }
                }
        /*for (int i = 0; i < 20;i++){
            for(int j = 0; j < 6; j++){
                if (CheckCollisionRecs(array_wall[i],rune_o_1_col)){
                    //TODO: REWRITE//////////////////////////////////////////////////////
                    Rectangle Box_colision = GetCollisionRec(array_wall[i],rune_o_1_col);
                    const Vector2 hs1 = { array_wall[i].width*.5f, array_wall[i].height*.5f };
                    const Vector2 hs2 = { rune_o_1_col.width*.5f, rune_o_1_col.height*.5f };

                    if(main.x > hs1.x){
                    main_char_col.x += vx * 153 * dt;
                    rune_o_1_col.x += vx * 150 * dt;
                    }
                     if(main.x < hs1.x){
                    main_char_col.x -= vx * 253 * dt;
                    rune_o_1_col.x -= vx * 300 * dt;
                    }
                    if(main.y < hs1.y){
                    main_char_col.y += vy * 200 * dt;
                    rune_o_1_col.y += vy * 150 * dt;
                    }
                    if(main.y > hs1.y){
                    main_char_col.y -= vy * 200 * dt;
                    rune_o_1_col.y -= vy * 150 * dt;
                    }

                }
                if (CheckCollisionRecs(array_wall[i],rune_o_2_col)){
                    
                    DrawText("COLISION!!!!!!!!!",screenWidth/2,screenHeight/2,50,RED);

                }
                if (CheckCollisionRecs(array_wall[i],rune_o_3_col)){

                    DrawText("COLISION!!!!!!!!!",screenWidth/2,screenHeight/2,50,RED);

                }
                if (CheckCollisionRecs(array_wall[i],rune_o_4_col)){
                    
                    DrawText("COLISION!!!!!!!!!",screenWidth/2,screenHeight/2,50,RED);

                }
                if (CheckCollisionRecs(array_wall[i],rune_o_5_col)){

                    DrawText("COLISION!!!!!!!!!",screenWidth/2,screenHeight/2,50,RED);

                }
                if (CheckCollisionRecs(array_wall[i],rune_o_6_col)){

                    DrawText("COLISION!!!!!!!!!",screenWidth/2,screenHeight/2,50,RED);

                }
            }
        }
*/
        /*  for (int i = 0; i < 6;i++){
        if (colision_rune_check[i] == true){
              rune_col = array_rune[i];
            // Calculation of half-widths and half-heights of rectangles
            const Vector2 hs1 = { main.size.x*.5f, main.size.x*.5f };
            const Vector2 hs2 = { rune_col.width*.5f, rune_col.height*.5f };

            if(main.x > hs1.x){
                if(i == 0){
                rune_o_1_col.x += vx * 120 * dt;
            }
            if(i == 1){
                rune_o_2_col.x += vx * 120 * dt;
            }
            if(i == 2){
                rune_o_3_col.x += vx * 120 * dt;
            }
            if(i == 3){
                rune_o_4_col.x += vx * 120 * dt;
            }
            if(i == 4){
                rune_o_5_col.x += vx * 120 * dt;
            }
            if(i == 5){
                rune_o_6_col.x += vx * 120 * dt;
            }
            }
            if(main.x < hs1.x){
                if(i == 0){
                rune_o_1_col.x -= vx * 200 * dt;
            }
            if(i == 1){
                rune_o_2_col.x -= vx * 200 * dt;
            }
            if(i == 2){
                rune_o_3_col.x -= vx * 200 * dt;
            }
            if(i == 3){
                rune_o_4_col.x -= vx * 200 * dt;
            }
            if(i == 4){
                rune_o_5_col.x -= vx * 200 * dt;
            }
            if(i == 5){
                rune_o_6_col.x -= vx * 200 * dt;
            }
            }
            if(main.y < hs1.y){
                if(i == 0){
                rune_o_1_col.y -= vy * 100 * dt;
            }
            if(i == 1){
                rune_o_2_col.y -= vy * 100 * dt;
            }
            if(i == 2){
                rune_o_3_col.y -= vy * 100 * dt;
            }
            if(i == 3){
                rune_o_4_col.y -= vy * 100 * dt;
            }
            if(i == 4){
                rune_o_5_col.y -= vy * 100 * dt;
            }
            if(i == 5){
                rune_o_6_col.y -= vy * 100 * dt;
            }
            }
            if(main.y > hs1.y){
                if(i == 0){
                rune_o_1_col.y += vy * 120 * dt;
            }
            if(i == 1){
                rune_o_2_col.y += vy * 120 * dt;
            }
            if(i == 2){
                rune_o_3_col.y += vy * 120 * dt;
            }
            if(i == 3){
                rune_o_4_col.y += vy * 120 * dt;
            }
            if(i == 4){
                rune_o_5_col.y += vy * 120 * dt;
            }
            if(i == 5){
                rune_o_6_col.y += vy * 120 * dt;
            } 
        }
        }
        }
*/
        if (IsKeyPressed(KEY_ESCAPE)) {
                        showRectangle = !showRectangle;
                        pause =!pause;
                }
        if(showRectangle){
        if (CheckCollisionPointRec(mousePoint, btnBounds_main_menu))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        if (btnAction)
        {
        settings_load = true;
        restart = true;
        currentScreen = TITLE;
        showRectangle = !showRectangle;
            // TODO: Any desired action
        }
        
        if (CheckCollisionPointRec(mousePoint, btnBounds_resume))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_r = 2;
            else btnState_r = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_r = !btnAction_r;
        }
        else btnState_r = 0;
        
        if (btnAction_r)
        {
        showRectangle = !showRectangle;
        btnAction_r = !btnAction_r;
        pause = !pause;
            // TODO: Any desired action
        }
        
         if (CheckCollisionPointRec(mousePoint, btnBounds_quit))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState_q = 2;
            else btnState_q = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_q = !btnAction_q;
        }
        else btnState_q = 0;
        if (btnAction_q) {
            showRectangle = !showRectangle;
            btnAction_q = !btnAction_q;
            exitWindowRequested = true;
            pause = !pause;
        }
         if (CheckCollisionPointRec(mousePoint, btnBounds_s))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){ 
                btnState_s = 2;
                btnAction_s = true;
            }
            else btnState_s = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction_s = true;
        }
        else btnState_s = 0;

        if (btnAction_s)
        {
            settings = !settings;
            btnAction_s = false;

        }
        }   
         sourceRec_s.y = btnState_s * frameHeight;
         sourceRec_q.y = btnState_q * frameHeight;

        sourceRec.y = btnState * frameHeight;

        sourceRec_r.y = btnState_r*frameHeight;

        if(settings){
                    showRectangle = false;
                    if (IsKeyPressed(KEY_ESCAPE)) {
                settings = !settings;
                pause = !pause;
                }
                if(volume > 1){
                        volume = 1;
                    }
                if(volume <= 1){
                    
                 if (IsKeyDown(KEY_DOWN)) volume -= 0.1f;
                else if (IsKeyDown(KEY_UP)) volume += 0.1f;
                
                volume += GetMouseWheelMove()*scrollSpeed;
                }
                }

            if (exitWindowRequested)
        {
            // A request for close window has been issued, we can save data before closing
            // or just show a message asking for confirmation
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)){
             exitWindowRequested = false;
            pause = !pause;
            }
        }

           

            }break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
         
        BeginDrawing();
        switch(currentScreen)
            {
        case LOGO:
                {
                    DrawRectangle(0,0,screenWidth,screenHeight,BLACK);
                    if(framesCounter < 120){
                        DrawTexture(logo,screenWidth/2 - logo.width/2,screenHeight/2 - logo.height/2,WHITE);
                        //DrawText("Developed by Debug Dream Team",screenWidth/2 - 250,screenHeight/2 - 30,30, BLACK);
                    }
                    if(framesCounter > 120){
                        DrawText("Cosmic Chronicles",screenWidth/2 - 150,screenHeight/2 - 30,30, WHITE);
                    }       
                } break;

        case TITLE:
                {
                DrawTexture(title, 0, 0, WHITE);
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);
                if(!settings_load){
                DrawTextureRec(button_settings, sourceRec_s, (Vector2){ btnBounds_s.x, btnBounds_s.y }, WHITE);
                }
                if(settings_load){
                    DrawTextureRec(button_settings, sourceRec_s, (Vector2){ screenWidth/2 - button_settings.width/2, screenHeight/2 - button_settings.height/2 + 195 }, WHITE);
                     }
                if(!exitWindowRequested){

        if (pause) {
            for(int i = 0; i < 3; i++) {
                    if(!&col_met[i]) {
                if(!showRectangle){
            DrawRectangle(0, 100, screenWidth, 200, WHITE);
            DrawText("PAUSED", 570, 200, 30, GRAY);
                }
                }
            }
            }
        if(settings){
            DrawTexture(back_settings,1,1,WHITE);
            DrawText("MUSIC VOLUME", screenWidth/2 - 200, screenHeight/2 - 20, 20, LIGHTGRAY);

            DrawRectangle(screenWidth/2 - 200, screenHeight/2, 400, 12, LIGHTGRAY);
            DrawRectangle(screenWidth/2 - 200,screenHeight/2 , (int)(volume*400.0f), 12, MAROON);
            DrawRectangleLines(screenWidth/2- 200, screenHeight/2, 400, 12, GRAY);
        }
            
        if (showRectangle){
            DrawTexture(Menu_background, screenWidth/2 - Menu_background.width/2, screenHeight/2 - Menu_background.height/2, WHITE);
            DrawText("Menu", 605, 150, 30, GRAY);
            DrawTextureRec(button_main_menu, sourceRec, (Vector2){ btnBounds_main_menu.x, btnBounds_main_menu.y }, WHITE);
            DrawTextureRec(button_resume, sourceRec_r, (Vector2){ btnBounds_resume.x, btnBounds_resume.y }, WHITE);
            DrawTextureRec(button_quit, sourceRec_q, (Vector2){ btnBounds_quit.x, btnBounds_quit.y }, WHITE);
            }
        }
        if (exitWindowRequested)
        {
        DrawRectangle(0, 100, screenWidth, 200, BLACK);
        DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
        }
                } break;

        case First_level:
                {
            DrawTextureEx(map, (Vector2){ scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(map, (Vector2){ map.width*2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

            DrawTexturePro(Portal, portal.sourceRec, portal.destRec, portal.origin, 0, WHITE);
            DrawTexture(meteorite, meteorite_o_1.destRec.x, meteorite_o_1.destRec.y, WHITE);
            DrawTexture(meteorite, meteorite_o_2.destRec.x, meteorite_o_2.destRec.y, WHITE);
            DrawTexture(meteorite, meteorite_o_3.destRec.x, meteorite_o_3.destRec.y, WHITE);
            //DrawTexture(spaceship, spaceship_c.x, spaceship_c.y, WHITE);
            DrawTextureRec(rocket_anim,frameRec,(Vector2){spaceship_c.x, spaceship_c.y},WHITE);

            if(TimerDone(&BlackHole)){

                DrawTexture(black_hole,screenWidth - black_hole.width - 50,screenHeight / 2 - black_hole.height/2,WHITE);
            }
            
            for(int i = 0; i < 3; i++) {
                    if(col_met[i]) {
                    DrawText("GAME OVER", 570, 200, 30, WHITE);
                    DrawText("Press R to restart", 515, 250, 30, WHITE);
                    }
                }

        if(!exitWindowRequested){
        if (pause) {
            for(int i = 0; i < 3; i++) {
                    if(!&col_met[i]) {
                if(!showRectangle){
            DrawRectangle(0, 100, screenWidth, 200, WHITE);
            DrawText("PAUSED", 570, 200, 30, GRAY);
                }
                }
            }
            }
            
        if (showRectangle){
            DrawTexture(Menu_background, screenWidth/2 - Menu_background.width/2, screenHeight/2 - Menu_background.height/2, WHITE);
            DrawText("Menu", 605, 150, 30, GRAY);
            DrawTextureRec(button_main_menu, sourceRec, (Vector2){ btnBounds_main_menu.x, btnBounds_main_menu.y }, WHITE);
            DrawTextureRec(button_resume, sourceRec_r, (Vector2){ btnBounds_resume.x, btnBounds_resume.y + 10 }, WHITE);
            DrawTextureRec(button_quit, sourceRec_q, (Vector2){ btnBounds_quit.x, btnBounds_quit.y }, WHITE);
            DrawTextureRec(button_settings, sourceRec_s, (Vector2){ btnBounds_s.x, btnBounds_s.y }, WHITE);
            }
        if(settings){
            DrawTexture(back_settings,1,1,WHITE);
            DrawText("MUSIC VOLUME", screenWidth/2 - 200, screenHeight/2 - 20, 20, LIGHTGRAY);

            DrawRectangle(screenWidth/2 - 200, screenHeight/2, 400, 12, LIGHTGRAY);
            DrawRectangle(screenWidth/2 - 200,screenHeight/2 , (int)(volume*400.0f), 12, MAROON);
            DrawRectangleLines(screenWidth/2- 200, screenHeight/2, 400, 12, GRAY);
        }
        }
        
        if (exitWindowRequested)
        {
        DrawRectangle(0, 100, screenWidth, 200, BLACK);
        DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
        } 
            /////////////////////////////////////END FIRST LEVEL
        }break;

        case Cutscena_Lv2:{
        DrawTexture(dune_map_cutsc,0,0,WHITE);
        if(!TimerDone(&Cutscena)){
        DrawTexture(white_hole,0,screenHeight/2 - black_hole.height/2,WHITE);
        }
        DrawTexture(spaceship,spaceship_col.x,spaceship_col.y,WHITE);
        if(TimerDone(&Cutscena)){
            DrawTexture(main_char,main_char_col.x,main_char_col.y - 30,WHITE);
        }

 if(!exitWindowRequested){

        if(!settings){
        if(!showRectangle){        
        if (pause) {
            DrawRectangle(0, 100, screenWidth, 200, WHITE);
            DrawText("PAUSED", 570, 200, 30, GRAY);
            }
        }
        
        if (showRectangle){
            DrawTexture(Menu_background, screenWidth/2 - Menu_background.width/2, screenHeight/2 - Menu_background.height/2, WHITE);
            //DrawRectangle(screenWidth/2 - 110, screenHeight/2 - 250, 220, 500, WHITE);
            DrawText("Menu", 605, 150, 30, GRAY);
            DrawTextureRec(button_main_menu, sourceRec, (Vector2){ btnBounds_main_menu.x, btnBounds_main_menu.y }, WHITE);
            DrawTextureRec(button_resume, sourceRec_r, (Vector2){ btnBounds_resume.x, btnBounds_resume.y + 10 }, WHITE);
            DrawTextureRec(button_quit, sourceRec_q, (Vector2){ btnBounds_quit.x, btnBounds_quit.y }, WHITE);
            DrawTextureRec(button_settings, sourceRec_s, (Vector2){ btnBounds_s.x, btnBounds_s.y}, WHITE);
            
        }
        }
        if(settings){
            DrawTexture(back_settings,1,1,WHITE);
            DrawText("MUSIC VOLUME", screenWidth/2 - 200, screenHeight/2 - 20, 20, LIGHTGRAY);

            DrawRectangle(screenWidth/2 - 200, screenHeight/2, 400, 12, LIGHTGRAY);
            DrawRectangle(screenWidth/2 - 200,screenHeight/2 , (int)(volume*400.0f), 12, MAROON);
            DrawRectangleLines(screenWidth/2- 200, screenHeight/2, 400, 12, GRAY);
            
        }
        }
        if (exitWindowRequested)
        {
        DrawRectangle(0, 100, screenWidth, 200, BLACK);
        DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
        }


        }break;

        case Second_level:{
            DrawTexture(dune_map,0,0,WHITE);
            DrawTexture(rune_1,rune_o_1_col.x,rune_o_1_col.y,WHITE);
            DrawTexture(rune_2,rune_o_2_col.x,rune_o_2_col.y,WHITE);
           DrawTexture(rune_3,rune_o_3_col.x,rune_o_3_col.y,WHITE);
           DrawTexture(rune_4,rune_o_4_col.x,rune_o_4_col.y,WHITE);
           DrawTexture(rune_5,rune_o_5_col.x,rune_o_5_col.y,WHITE);
           DrawTexture(rune_6,rune_o_6_col.x,rune_o_6_col.y,WHITE);

        for (int i = 0; i < 6;i++){
            if (colision_rune_check[i] == true){
                    array_draw_rune[i] = true;
            }
        }

        if(time_music_len > 0){
            time_music_len -= 1;
        }

        if(array_draw_rune[0] == true){
            DrawTexture(rune_shine_1,rune_o_1_col.x,rune_o_1_col.y,WHITE);
            if(rune_1_b == false){
                PlaySound(shine);
                rune_1_b = true;
            }
        }
         if(array_draw_rune[1] == true){
            DrawTexture(rune_shine_2,rune_o_2_col.x,rune_o_2_col.y,WHITE);
           if(rune_2_b == false){
                PlaySound(shine);
                rune_2_b = true;
            }
        }
         if(array_draw_rune[2] == true){
            DrawTexture(rune_shine_3,rune_o_3_col.x,rune_o_3_col.y,WHITE);
           if(rune_3_b == false){
                PlaySound(shine);
                rune_3_b = true;
            }
        }
         if(array_draw_rune[3] == true){
            DrawTexture(rune_shine_4,rune_o_4_col.x,rune_o_4_col.y,WHITE);
            if(rune_4_b == false){
                PlaySound(shine);
                rune_4_b = true;
            }
        }
         if(array_draw_rune[4] == true){
            DrawTexture(rune_shine_5,rune_o_5_col.x,rune_o_5_col.y,WHITE);
            if(rune_5_b == false){
                PlaySound(shine);
                rune_5_b = true;
            }
        }
         if(array_draw_rune[5] == true){
            DrawTexture(rune_shine_6,rune_o_6_col.x,rune_o_6_col.y,WHITE);
            if(rune_6_b == false){
                PlaySound(shine);
                rune_6_b = true;
            }
        }
        if (IsKeyDown(KEY_W) && IsKeyDown(KEY_S)){
            DrawTexture(main_char, main_char_col.x, main_char_col.y, WHITE);
        }

        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D)){
            DrawTexture(main_char, main_char_col.x, main_char_col.y, WHITE);
        }else{
            if(!pause){
            if(IsKeyDown(KEY_W)){
                DrawTextureRec(Josef_walk_right, frameRec_character, main_char_pos, WHITE);
            }
            if(IsKeyDown(KEY_S)){
                DrawTextureRec(Josef_walk_left, frameRec_character, main_char_pos, WHITE);
            }
             if (IsKeyDown(KEY_A)) {
                //DrawTexture(main_char, main_char_col.x, main_char_col.y, WHITE);
                DrawTextureRec(Josef_walk_left, frameRec_character, main_char_pos, WHITE);
            }
            if (IsKeyDown(KEY_D)) {
                //DrawTexture(main_char, main_char_col.x, main_char_col.y, WHITE);
                DrawTextureRec(Josef_walk_right, frameRec_character, main_char_pos, WHITE);  // Draw part of the texture
            }
            }
        }
            if(!IsKeyDown(KEY_D) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)){
                DrawTexture(main_char, main_char_col.x, main_char_col.y, WHITE);
            }

            if(settings){
            DrawTexture(back_settings,1,1,WHITE);
            DrawText("MUSIC VOLUME", screenWidth/2 - 200, screenHeight/2 - 20, 20, LIGHTGRAY);

            DrawRectangle(screenWidth/2 - 200, screenHeight/2, 400, 12, LIGHTGRAY);
            DrawRectangle(screenWidth/2 - 200,screenHeight/2 , (int)(volume*400.0f), 12, MAROON);
            DrawRectangleLines(screenWidth/2- 200, screenHeight/2, 400, 12, GRAY);
        }
           

          
            if(!exitWindowRequested){
                if(!showRectangle){
                    if(!settings){
        if (pause == true) {
            DrawRectangle(0, 100, screenWidth, 200, WHITE);
            DrawText("PAUSED", 570, 200, 30, GRAY);
            DrawTexture(main_char, main.x, main.y, WHITE);
            }
            }
            }
        
        if (showRectangle){
            DrawTexture(main_char, main.x, main.y, WHITE);
            DrawTexture(Menu_background, screenWidth/2 - Menu_background.width/2, screenHeight/2 - Menu_background.height/2, WHITE);
            //DrawRectangle(screenWidth/2 - 110, screenHeight/2 - 250, 220, 500, WHITE);
            DrawText("Menu", 605, 150, 30, GRAY);
           DrawTextureRec(button_main_menu, sourceRec, (Vector2){ btnBounds_main_menu.x, btnBounds_main_menu.y }, WHITE);
            DrawTextureRec(button_resume, sourceRec_r, (Vector2){ btnBounds_resume.x, btnBounds_resume.y + 10 }, WHITE);
            DrawTextureRec(button_quit, sourceRec_q, (Vector2){ btnBounds_quit.x, btnBounds_quit.y }, WHITE);
            DrawTextureRec(button_settings, sourceRec_s, (Vector2){ btnBounds_s.x, btnBounds_s.y}, WHITE);
            }
        }
         if(array_draw_rune[0] == true && array_draw_rune[1] == true && array_draw_rune[2] == true && array_draw_rune[3] == true && array_draw_rune[4] == true && array_draw_rune[5] == true){
            DrawTextureRec(Portal_red,frameRec_portal_blue,(Vector2){1152,407},WHITE);
            DrawTextureRec(Portal_blue,frameRec_portal_blue,(Vector2){1152,523},WHITE);
            if(portal_b == false){
                PlaySound(portal_sound);
                portal_b = true;
            }
            
             if(CheckCollisionRecs(portal_blue,main_char_col)){
                ClearBackground(BLACK);
                DrawRectangle (0,0,screenWidth,screenHeight,BLACK);
                DrawText("To be continued...",screenWidth/2 - 115,screenHeight/2,20,WHITE);
                    
                }
        }
        if (exitWindowRequested)
        {
        DrawTexture(main_char, main.x, main.y, WHITE);
        DrawRectangle(0, 100, screenWidth, 200, BLACK);
        DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
        }

          
 
        }break;

         default: break;
    }
        
        EndDrawing();
        //----------------------------------------------------------------------------------
        }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();
    CloseWindow(); 
    
    UnloadTexture(Josef_walk_right);  
    UnloadTexture(main_char);
    UnloadTexture(Josef_walk_left);
    UnloadTexture(button);
    UnloadTexture(title);
    UnloadTexture(Portal);
    UnloadTexture(Menu_background);
    UnloadTexture(button_main_menu);
    UnloadTexture(button_resume);
    UnloadTexture(button_quit);
    UnloadTexture(rune_1);
    UnloadTexture(rune_2);
    UnloadTexture(rune_3);
    UnloadTexture(rune_4);
    UnloadTexture(rune_5);
    UnloadTexture(rune_6);
    UnloadTexture(button_settings);
    UnloadTexture(rune_shine_1);
    UnloadTexture(rune_shine_2);
    UnloadTexture(rune_shine_3);
    UnloadTexture(rune_shine_4);
    UnloadTexture(rune_shine_5);
    UnloadTexture(logo);
    UnloadMusicStream(main_menu_track);             // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


