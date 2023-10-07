# Check if the correct number of arguments are provided
if ($args.Count -ne 2) {
  Write-Host "Usage: test.ps1 <executable> <inputDirectory>"
  exit 1
}

# Get the executable filename and input directory from command-line arguments
$executable = $args[0]
$inputDirectory = $args[1]

# Check if the executable file exists
if (-Not (Test-Path $executable -PathType Leaf)) {
  Write-Host "Error: Executable file '$executable' not found."
  exit 1
}

# Check if the input directory exists
if (-Not (Test-Path $inputDirectory -PathType Container)) {
  Write-Host "Error: Input directory '$inputDirectory' not found."
  exit 1
}

# Get a list of input files in the input directory
$inputFiles = Get-ChildItem -Path $inputDirectory -Filter "i*.txt" | Sort-Object

# Check if any input files were found
if ($inputFiles.Count -eq 0) {
  Write-Host "Error: No input files (i*.txt) found in '$inputDirectory'."
  exit 1
}

# Iterate through the input files and execute the C program with each input
foreach ($inputFile in $inputFiles) {
  $inputFilePath = $inputFile.FullName
  $inputFileName = $inputFile.Name
  Write-Host "Testing with input file: $inputFileName"

  # Read input from the file and pipe it to the C program
  $output = Get-Content $inputFilePath | & $executable

  # Display the output (you can customize this part as needed)
  Write-Host "Output:"
  Write-Host $output
}

# End of script
