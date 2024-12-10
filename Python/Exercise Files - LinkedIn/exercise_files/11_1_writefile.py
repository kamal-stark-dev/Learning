from argparse import ArgumentParser

parser = ArgumentParser()

parser.add_argument('--output', '-o', required=True, help='Write destination file for the output file.')
parser.add_argument('--text', '-t', required=True, help='Write your text after this tag, use double quotes " " if multiple words.')


args = parser.parse_args()

# print(args)

with open(args.output, 'w') as f:
    f.write(args.text + '\n')

print(f'Successfully wrote "{args.text}" to the file "{args.output}."')