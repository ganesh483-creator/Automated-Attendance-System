import pandas as pd

student_mac_dict = {
    "Student1": "84:80:2D:2A:C7:A1",
    "Student2": "06:7B:E9:20:18:F2"
}

df = pd.read_excel("Attendance.xlsx")

df['Date'] = pd.to_datetime(df['Date'])
df['Time'] = pd.to_datetime(df['Time']).dt.time

start_time = pd.to_datetime('13:00').time()
end_time = pd.to_datetime('14:00').time()

df_filtered = df[(df['Time'] >= start_time) & (df['Time'] <= end_time)]
df_filtered = df_filtered[df_filtered['MAC'].isin(student_mac_dict.values())]

mac_to_student = {v: k for k, v in student_mac_dict.items()}
df_filtered['Student Name'] = df_filtered['MAC'].map(mac_to_student)

hourly_frequency = df_filtered.groupby('Student Name').size().reset_index(name='Frequency')

attendance = pd.DataFrame(list(student_mac_dict.keys()), columns=['Student Name'])
attendance = pd.merge(attendance, hourly_frequency, on='Student Name', how='left')

attendance['Frequency'] = attendance['Frequency'].fillna(0)
attendance['Status'] = attendance['Frequency'].apply(lambda x: 'Present' if x > 50 else 'Absent')

attendance.to_excel("final_attendance.xlsx", index=False)

print("Attendance data for all students has been saved to 'final_attendance.xlsx'")
