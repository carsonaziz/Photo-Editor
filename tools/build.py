import subprocess

# macOS ARM Build
subprocess.call("make config=debug", shell=True)