import pandas
import os
import csv
import json
folder_path = '/Users/karthikragunath/Downloads/batman/'
file_names = list(map(lambda x: folder_path + x, list(filter(lambda x: '.csv' in x, os.listdir(folder_path)))))
file_names_compressed = list(filter(lambda x: '.csv' in x, os.listdir(folder_path)))
with open('/Users/karthikragunath/Downloads/tata_s3_data_new.json', 'r') as fp:
    compressed_json = json.load(fp)
for file_name, file_name_compressed in zip(file_names, file_names_compressed):
    with open(file_name, 'r') as fp, open('/Users/karthikragunath/Downloads/batman_new/' + file_name_compressed, 'w') as fp_w:
        reader = csv.DictReader(fp)
        writer = csv.DictWriter(fp_w, fieldnames=reader.fieldnames)
        writer.writeheader()
        for row in reader:
            extras = json.loads(row['extras'])
            if extras.get('style_id', None):
                mad_id = '50_tata_' + extras['style_id']
                if row['ontology']:
                    if row['ontology'] in compressed_json and mad_id in compressed_json[row['ontology']]:
                        extras.update(compressed_json[row['ontology']][mad_id])
            row['extras'] = json.dumps(extras)
            writer.writerow(row)