 
#include "elements/Element.h"
#include "elements/Keyboard.h"

class AiChatPage : public Element {
public:
    void update() override {
        if (keboardActive) {
            keyboard.update();
            if (keyboard.isDirty()) setDirty();
            if (Input::justPressed(KEY_X)) {
                keboardActive = false;
                setDirty();
            }
        }
        else {
            if (Input::justPressed(KEY_A)) {
                keboardActive = true;
                setDirty();
            }
            if (Input::justPressed(KEY_Y)) {
                
                strncpy(Storage::data.mistralApiKey, apikey.c_str(), sizeof(Storage::data.mistralApiKey) - 1);
                Storage::data.mistralApiKey[sizeof(Storage::data.mistralApiKey) - 1] = '\0'; // sicherstellen, dass Nullterminator gesetzt ist

                Storage::save();
                
                setDirty();
            }
        }
    };

    void keyboardCallback() {
        apikey = keyboard.string;
        setDirty();
    };


    void render() override {

        setDirty(false);

        Display::clear(CURRENT_THEME->surface[2]);

        Display::drawString(0, 5, "API-KEY: " + apikey, Display::alpha, CURRENT_THEME->surface[9], false, &Font6x8, 1);

        if (keboardActive) {
            
            Display::drawString(0, 90, "Press X to exit edit", CURRENT_THEME->surface[8], Display::alpha, false, &Font6x8, 1);

            keyboard.render();
        } else {

            Display::drawString(0, 50, "Press A to edit", CURRENT_THEME->surface[8], Display::alpha, false, &Font6x8, 1);
            Display::drawString(0, 60, "Press Y to save", CURRENT_THEME->surface[8], Display::alpha, false, &Font6x8, 1);
            Display::drawString(0, 70, "Press X to discard", CURRENT_THEME->surface[8], Display::alpha, false, &Font6x8, 1);

       }
    };

    std::string apikey = "";
    bool keboardActive = false;
    Keyboard keyboard =  Keyboard([this](){keyboardCallback();});
};







