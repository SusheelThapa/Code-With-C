'''
    Since, Open code in notepad copy it and paste it.

    I AM DONE WITH THAT

    Being Computer engineering student its shameless for me to do that

    So, I have created this program to do that task it just copy the code one by one present in the files

    Note:
        This python file and c programs files should be in same folder
        To run this file,

            ~You need to have python installed in your computer
            ~And install pyperclip by executing command:
                pip install pyperclip

            Execute the command:
                python Copy_Code.py

            Donot forgot to see that result after copying code it will display some result
    
'''


import os
import pyperclip

cwd_files_folders = os.listdir()

for item in cwd_files_folders:
    if item.endswith(".c"):
        with open(item, "r") as f:
            code = f.read()
            pyperclip.copy(code)
            print(
                f"Code copied from {item}\nPress any key to copy code from next file..")
            a = input()

print("All code has been copied.\n\nGood to go...")
