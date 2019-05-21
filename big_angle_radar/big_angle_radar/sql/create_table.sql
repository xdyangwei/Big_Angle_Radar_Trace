CREATE TABLE IF NOT EXISTS radar_data (
    id integer PRIMARY KEY AUTOINCREMENT, 
    targetid float,
    x float,
    y float,
    speed float,
    acc float,
    UNIQUE(id)
);