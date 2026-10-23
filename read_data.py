########
# LFNS2 2026: Group 4
# Python code for converting a .csv file in a .dat, via DataFrame
########

import pandas as pd

def csv_to_df(input_csv):
	"""Read a .csv with a header and numeric data into a DataFrame."""
	return pd.read_csv(input_csv).apply(pd.to_numeric)


def write_dat(dataframe, output_dat): #uses the DF method to write the df in a csv file, but using tab as a separator (+ no header option)
	"""Write the DataFrame in a .dat file.""" 
	dataframe.to_csv(output_dat, sep="\t", header=False, index=False) 

def main():
	infile = "../MAPS_LIMADOU/bkg_55_2/data.csv"
	outfile = "../MAPS_LIMADOU/bkg_55_2/data.dat"
	df = csv_to_df(infile)
	write_dat(df, outfile)

if __name__ == "__main__":
	main()
