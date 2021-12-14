/**
  ******************************************************************************
  * This file is part of the TouchGFX 4.10.0 distribution.
  *
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
  

#ifndef AUDIO_PLAYER_FOLDERWIDGET_HPP
#define AUDIO_PLAYER_FOLDERWIDGET_HPP

#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/ListLayout.hpp>
#include <touchgfx/containers/ScrollableContainer.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

#include <gui/common/Playlist.hpp>
#include <gui/common/CommonDefinitions.hpp>
#include <gui/video_player_screen/FileInput.hpp>

using namespace touchgfx;

class AudioPlaylistManager
{
public:
    virtual bool addFile(uint32_t index) = 0;
    virtual void removeFile(uint32_t index) = 0;
    virtual void folderSelected(uint32_t index) = 0;
    virtual void upPressed() = 0;
    virtual void donePressed() = 0;
    virtual ~AudioPlaylistManager() {};
};

class AudioFolderListElement : public Container
{
public:
    AudioFolderListElement();
    void configure(bool isDirectory);
    void setSelected(bool selected);
    virtual void handleClickEvent(const ClickEvent &event);

    TextAreaWithOneWildcard name;
    Unicode::UnicodeChar nameBuf[FILENAME_LENGTH];
    Image background; // visible when selected
    Image icon;
    Image button;
    uint32_t index;
    bool isDirectory;
    bool isIncluded;
    bool isSelected;
    bool clickCancelled;

    AudioPlaylistManager *playlistManager;
    static GenericCallback< const uint32_t > *itemPressedAction;
};

class AudioFolderWidget : public Container
{
public:
    AudioFolderWidget(AudioPlaylistManager &);
    void setPlaylist(PlaylistElement *playlist, uint32_t length);
    void setupDirlist(const char *const foldername, fileinput::DirEntry *dirlist, uint32_t length);
private:
    Image background;
    Image shadow;
    Image titlebar;
    TextAreaWithOneWildcard titleText;
    Unicode::UnicodeChar folderNameBuf[FOLDERNAME_LENGTH];

    ScrollableContainer scrollCnt;
    ListLayout list;
    AudioFolderListElement listElements[DIRLIST_LENGTH];

    Image bottombar;
    Button backButton;
    Button okButton;
    uint32_t selected;

    AudioPlaylistManager &playlistManager;

    PlaylistElement *playlist;
    uint32_t playlistLength;
    bool isOnPlaylist(const char *const foldername, fileinput::DirEntry &direntry);

    Callback<AudioFolderWidget, const AbstractButton &> buttonCallback;
    void onButtonPressed(const AbstractButton &button);
    Callback<AudioFolderWidget, const uint32_t> itemCallback;
    void onItemPressed(const uint32_t index);
};

#endif

