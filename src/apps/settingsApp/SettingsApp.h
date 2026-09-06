#pragma once

#include "core/App.h"
#include "elements/Menu.h"
#include "elements/MenuOnOff.h"
#include "elements/ThemePreview.h"
#include "WifiPage.h"
#include "AiChatPage.h"

enum SettingsPage {
    SETTINGS_MAIN, SETTINGS_DISPLAY, SETTINGS_THEME, SETTINGS_FEATURES, SETTINGS_WIFI, SETTINGS_MISTRAL
};


class SettingsApp : public App {

    void init() override;
    void update() override;
    void render() override;

    private:
        ThemePreview themePreviewScreen = ThemePreview();
        Menu mainSettingsMenuScreen = Menu();
        MenuOnOff featureMenu = MenuOnOff();
        WifiPage wifiPage = WifiPage();
        AiChatPage mistralSettings = AiChatPage();

        int themePreviewIndex = 0;
        
        SettingsPage currentPage = SettingsPage::SETTINGS_MAIN;
};
