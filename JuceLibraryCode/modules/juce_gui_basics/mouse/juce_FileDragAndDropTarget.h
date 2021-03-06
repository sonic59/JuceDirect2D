/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-11 by Raw Material Software Ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the GNU General
   Public License (Version 2), as published by the Free Software Foundation.
   A copy of the license is included in the JUCE distribution, or can be found
   online at www.gnu.org/licenses.

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.rawmaterialsoftware.com/juce for more information.

  ==============================================================================
*/

#ifndef __JUCE_FILEDRAGANDDROPTARGET_JUCEHEADER__
#define __JUCE_FILEDRAGANDDROPTARGET_JUCEHEADER__

#include "../components/juce_Component.h"


//==============================================================================
/**
    Components derived from this class can have files dropped onto them by an external application.

    @see DragAndDropContainer
*/
class JUCE_API  FileDragAndDropTarget
{
public:
    /** Destructor. */
    virtual ~FileDragAndDropTarget()  {}

    /** Callback to check whether this target is interested in the set of files being offered.

        Note that this will be called repeatedly when the user is dragging the mouse around over your
        component, so don't do anything time-consuming in here, like opening the files to have a look
        inside them!

        @param files        the set of (absolute) pathnames of the files that the user is dragging
        @returns            true if this component wants to receive the other callbacks regarging this
                            type of object; if it returns false, no other callbacks will be made.
    */
    virtual bool isInterestedInFileDrag (const StringArray& files) = 0;

    /** Callback to indicate that some files are being dragged over this component.

        This gets called when the user moves the mouse into this component while dragging.

        Use this callback as a trigger to make your component repaint itself to give the
        user feedback about whether the files can be dropped here or not.

        @param files        the set of (absolute) pathnames of the files that the user is dragging
        @param x            the mouse x position, relative to this component
        @param y            the mouse y position, relative to this component
    */
    virtual void fileDragEnter (const StringArray& files, int x, int y);

    /** Callback to indicate that the user is dragging some files over this component.

        This gets called when the user moves the mouse over this component while dragging.
        Normally overriding itemDragEnter() and itemDragExit() are enough, but
        this lets you know what happens in-between.

        @param files        the set of (absolute) pathnames of the files that the user is dragging
        @param x            the mouse x position, relative to this component
        @param y            the mouse y position, relative to this component
    */
    virtual void fileDragMove (const StringArray& files, int x, int y);

    /** Callback to indicate that the mouse has moved away from this component.

        This gets called when the user moves the mouse out of this component while dragging
        the files.

        If you've used fileDragEnter() to repaint your component and give feedback, use this
        as a signal to repaint it in its normal state.

        @param files        the set of (absolute) pathnames of the files that the user is dragging
    */
    virtual void fileDragExit (const StringArray& files);

    /** Callback to indicate that the user has dropped the files onto this component.

        When the user drops the files, this get called, and you can use the files in whatever
        way is appropriate.

        Note that after this is called, the fileDragExit method may not be called, so you should
        clean up in here if there's anything you need to do when the drag finishes.

        @param files        the set of (absolute) pathnames of the files that the user is dragging
        @param x            the mouse x position, relative to this component
        @param y            the mouse y position, relative to this component
    */
    virtual void filesDropped (const StringArray& files, int x, int y) = 0;
};


#endif   // __JUCE_FILEDRAGANDDROPTARGET_JUCEHEADER__
