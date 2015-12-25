import os

def make_file():
    os.system("make clean")
    os.system("make")

def find_input_output():
    files=[]
    input_output=[]
    for file in os.listdir(os.getcwd()):
        if file.endswith(".dat"):
            files.append(file)
    intputFiles=filter(lambda file: "input" in file, files)
    outputFiles=filter(lambda file: "Output" in file, files)
    for inputFile in intputFiles:
        index=inputFile.index("Part")
        key=inputFile[index:]
        outputFile=filter(lambda file: key in file, outputFiles)[0]
        input_output.append((inputFile,outputFile))
    return input_output

def run_bash_commands(input_output):
    for item in input_output:
        inputFile= item[0]
        outputFile= item[1]
        which_part= inputFile[inputFile.lower().index("part"):inputFile.lower().index("part")+5]
        yourOutput= inputFile+ "_your_solution"
        bashCommand= "./"+which_part.lower()+" <"+ inputFile+ " >"+ yourOutput
        os.system(bashCommand)
        print("Beginning to do Test " + inputFile)
        print
        print
        bashCommand= "./grading " + yourOutput+ " " + outputFile
        os.system(bashCommand)
        print
        print

def clean_solution():
    os.system("rm -r -f *_solution")

if __name__ == "__main__":
    make_file()
    input_output=find_input_output()
    run_bash_commands(input_output)
    clean_solution()
