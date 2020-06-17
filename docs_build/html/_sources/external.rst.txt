Accessing external files
========================

The iOS / iPadOS file system is very different than the file system on other operating systems. Files are placed inside containers. These containers are owned by different apps. They are all visible from the Files app but other apps don't have access to files owned by other ones. Instead, the system gives access to individual files or folders selected by the user to be edited with the desired app.

Current Directory
-----------------

Scripts stored in the Pyto container can access scripts in the same directory. If acess isn't granted, a lock icon is displayed at the bottom of the code editor. Pressing this button shows a folder picker. You can change the current directory, or just select the folder containing the script. This will not work for third party cloud providers such as Google Drive or Dropbox because they don't have a real file system.

Bookmarks
---------

Another good option to open external files is to use the `bookmarks <bookmarks.html>`__ module. This can be used to access files from different places without having to change the current directory.
