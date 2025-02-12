#! /bin/bash
#SBATCH --job-name=myjob
#SBATCH --partition=Centaurus
#SBATCH --time=01:00:00
$HOME/itsc4145a2/nbody 0 5000000 200 solar.tsv solaroutput.tsv
$HOME/itsc4145a2/nbody 100 10000 1 solar.tsv randoutput.tsv
