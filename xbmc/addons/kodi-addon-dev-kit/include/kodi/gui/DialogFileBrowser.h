#pragma once
/*
 *      Copyright (C) 2005-2017 Team KODI
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with KODI; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "definitions.h"
#include "../AddonBase.h"

namespace kodi
{
namespace gui
{

  //============================================================================
  ///
  /// \defgroup cpp_kodi_gui_DialogFileBrowser Dialog File Browser
  /// \ingroup cpp_kodi_gui
  /// @brief \cpp_namespace{ kodi::gui::DialogFileBrowser }
  /// **File browser dialog**
  ///
  /// The functions listed below of the class "DialogFileBrowser" offer
  /// the possibility to select to a file by the user of the add-on.
  ///
  /// It allows all the options that are possible in Kodi itself and offers all
  /// support file types.
  ///
  /// It has the header \ref DialogFileBrowser.h "#include <kodi/gui/DialogFileBrowser.h>"
  /// be included to enjoy it.
  ///
  namespace DialogFileBrowser
  {
    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogFileBrowser
    /// @brief Directory selection dialog
    ///
    /// @param[in] shares       With Shares becomes the available start folders
    ///                         be set.
    /// @param[in] heading      Dialog header name
    /// @param[in,out] path     As in the path to start and return value about
    ///                         selected directory
    /// @param[in] writeOnly    If set only writeable folders are shown.
    /// @return                 False if selection becomes canceled.
    ///
    /// **Example:**
    /// ~~~~~~~~~~~~~{.cpp}
    /// #include <kodi/gui/DialogFileBrowser.h>
    ///
    /// /*
    ///  * Example show directory selection dialog with on 'share' (first value)
    ///  * defined directory types.
    ///  *
    ///  * If this becomes leaved empty and 'directory' is empty goes it to the
    ///  * base path of the hard disk.
    ///  *
    ///  * Also can be with path written to 'directory' before the dialog forced
    ///  * to a start place.
    ///  */
    /// std::string directory;
    /// bool ret = kodi::gui::DialogFileBrowser::ShowAndGetDirectory("local|network|removable",
    ///                                                    "Test directory selection",
    ///                                                    directory,
    ///                                                    false);
    /// fprintf(stderr, "Selected directory is : %s and was %s\n", directory.c_str(), ret ? "OK" : "Canceled");
    /// ~~~~~~~~~~~~~
    ///
    inline bool ShowAndGetDirectory(const std::string& shares, const std::string& heading, std::string& path, bool writeOnly = false)
    {
      using namespace ::kodi::addon;
      char* retString = nullptr;
      bool ret = CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->show_and_get_directory(CAddonBase::m_interface->toKodi->kodiBase,
                                                                                                      shares.c_str(), heading.c_str(), path.c_str(), &retString, writeOnly);
      if (retString != nullptr)
      {
        if (std::strlen(retString))
          path = retString;
        CAddonBase::m_interface->toKodi->free_string(CAddonBase::m_interface->toKodi->kodiBase, retString);
      }
      return ret;
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogFileBrowser
    /// @brief File selection dialog
    ///
    /// @param[in] shares               With Shares becomes the available  start
    ///                                 folders be set.
    /// @param[in] mask                 The mask to filter visible  files,  e.g.
    ///                                 ".m3u|.pls|.b4s|.wpl".
    /// @param[in] heading              Dialog header name
    /// @param[in,out] path             As in the path to start and Return value
    ///                                 about selected file
    /// @param[in] useThumbs            If set show thumbs if possible on dialog.
    /// @param[in] useFileDirectories   If set also  packages  (e.g. *.zip)  are
    ///                                 handled as directories.
    /// @return                         False if selection becomes canceled.
    ///
    inline bool ShowAndGetFile(const std::string& shares, const std::string& mask, const std::string& heading,
                               std::string& path, bool useThumbs = false, bool useFileDirectories = false)
    {
      using namespace ::kodi::addon;
      char* retString = nullptr;
      bool ret = CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->show_and_get_file(CAddonBase::m_interface->toKodi->kodiBase,
                                                                                                 shares.c_str(), mask.c_str(), heading.c_str(), path.c_str(), &retString,
                                                                                                 useThumbs, useFileDirectories);
      if (retString != nullptr)
      {
        if (std::strlen(retString))
          path = retString;
        CAddonBase::m_interface->toKodi->free_string(CAddonBase::m_interface->toKodi->kodiBase, retString);
      }
      return ret;
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogFileBrowser
    /// @brief File selection from a directory
    ///
    /// @param[in] directory            The  directory  name  where  the  dialog
    ///                                 start, possible  are  normal  names  and
    ///                                 kodi's special names.
    /// @param[in] mask                 The mask to filter visible  files,  e.g.
    ///                                 ".m3u|.pls|.b4s|.wpl".
    /// @param[in] heading              Dialog header name
    /// @param[in,out] path             As in the path to start and Return value
    ///                                 about selected file
    /// @param[in] useThumbs            If set show thumbs if possible on dialog.
    /// @param[in] useFileDirectories   If set also  packages  (e.g. *.zip)  are
    ///                                 handled as directories.
    /// @param[in] singleList
    /// @return                         False if selection becomes canceled.
    ///
    inline bool ShowAndGetFileFromDir(const std::string& directory, const std::string& mask, const std::string& heading, std::string& path,
                                      bool useThumbs = false, bool useFileDirectories = false, bool singleList = false)
    {
      using namespace ::kodi::addon;
      char* retString = nullptr;
      bool ret = CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->show_and_get_file_from_dir(CAddonBase::m_interface->toKodi->kodiBase,
                                                                                                          directory.c_str(), mask.c_str(), heading.c_str(),
                                                                                                          path.c_str(), &retString, useThumbs, 
                                                                                                          useFileDirectories, singleList);
      if (retString != nullptr)
      {
        if (std::strlen(retString))
          path = retString;
        CAddonBase::m_interface->toKodi->free_string(CAddonBase::m_interface->toKodi->kodiBase, retString);
      }
      return ret;
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogFileBrowser
    /// @brief File selection dialog to get several in to a list
    ///
    /// @param[in] shares             With Shares becomes  the  available  start
    ///                               folders be set.
    /// @param[in] mask               The mask to  filter  visible  files,  e.g.
    ///                               ".m3u|.pls|.b4s|.wpl".
    /// @param[in] heading            Dialog header name
    /// @param[out] fileList          Return value about selected files
    /// @param[in] useThumbs          If set show thumbs if possible on dialog.
    /// @param[in] useFileDirectories If  set  also  packages  (e.g. *.zip)  are
    ///                               handled as directories.
    /// @return False if selection becomes canceled.
    ///
    inline bool ShowAndGetFileList(const std::string& shares, const std::string& mask, const std::string& heading,
                                   std::vector<std::string>& fileList, bool useThumbs = false, bool useFileDirectories = false)
    {
      using namespace ::kodi::addon;
      char** list = nullptr;
      unsigned int listSize = 0;
      bool ret = CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->show_and_get_file_list(CAddonBase::m_interface->toKodi->kodiBase,
                                                                                                      shares.c_str(), mask.c_str(), heading.c_str(), &list, &listSize,
                                                                                                      useThumbs, useFileDirectories);
      if (ret)
      {
        for (unsigned int i = 0; i < listSize; ++i)
          fileList.push_back(list[i]);
        CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->clear_file_list(CAddonBase::m_interface->toKodi->kodiBase, &list, listSize);
      }
      return ret;
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogFileBrowser
    /// @brief Source selection dialog
    ///
    /// @param[in,out] path           As in the path to start and Return value
    ///                               about selected source
    /// @param[in] allowNetworkShares Allow also access to network
    /// @param[in] additionalShare    With additionalShare becomes the available
    ///                               start folders be set (optional).
    /// @param[in] type
    /// @return                       False if selection becomes canceled.
    ///
    inline bool ShowAndGetSource(std::string& path, bool allowNetworkShares, const std::string& additionalShare = "", const std::string& type = "")
    {
      using namespace ::kodi::addon;
      char* retString = nullptr;
      bool ret = CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->show_and_get_source(CAddonBase::m_interface->toKodi->kodiBase, path.c_str(), &retString, 
                                                                                                   allowNetworkShares, additionalShare.c_str(), type.c_str());
      if (retString != nullptr)
      {
        if (std::strlen(retString))
          path = retString;
        CAddonBase::m_interface->toKodi->free_string(CAddonBase::m_interface->toKodi->kodiBase, retString);
      }
      return ret;
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogFileBrowser
    /// @brief Image selection dialog
    ///
    /// @param[in] shares     With Shares becomes the available start folders be
    ///                       set.
    /// @param[in] heading    Dialog header name
    /// @param[out] path      Return value about selected image
    /// @return               False if selection becomes canceled.
    ///
    inline bool ShowAndGetImage(const std::string& shares, const std::string& heading, std::string& path)
    {
      using namespace ::kodi::addon;
      char* retString = nullptr;
      bool ret = CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->show_and_get_image(CAddonBase::m_interface->toKodi->kodiBase,
                                                                                                  shares.c_str(), heading.c_str(), path.c_str(), &retString);
      if (retString != nullptr)
      {
        if (std::strlen(retString))
          path = retString;
        CAddonBase::m_interface->toKodi->free_string(CAddonBase::m_interface->toKodi->kodiBase, retString);
      }
      return ret;
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogFileBrowser
    /// @brief Image selection dialog to get several in to a list
    ///
    /// @param[in] shares       With Shares becomes the available  start folders
    ///                         be set.
    /// @param[in] heading      Dialog header name
    /// @param[out] file_list   Return value about selected images
    /// @return                 False if selection becomes canceled.
    ///
    inline bool ShowAndGetImageList(const std::string& shares, const std::string& heading, std::vector<std::string>& file_list)
    {
      using namespace ::kodi::addon;
      char** list = nullptr;
      unsigned int listSize = 0;
      bool ret = CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->show_and_get_image_list(CAddonBase::m_interface->toKodi->kodiBase,
                                                                                                       shares.c_str(), heading.c_str(), &list, &listSize);
      if (ret)
      {
        for (unsigned int i = 0; i < listSize; ++i)
          file_list.push_back(list[i]);
        CAddonBase::m_interface->toKodi->kodi_gui->dialogFileBrowser->clear_file_list(CAddonBase::m_interface->toKodi->kodiBase, &list, listSize);
      }
      return ret;
    }
    //--------------------------------------------------------------------------
  };

} /* namespace gui */
} /* namespace kodi */
