CREATE TABLE IF NOT EXISTS radar_data (
    id integer PRIMARY KEY AUTOINCREMENT, 
    type_id integer,
    frame_id integer,
    frame_index integer,
    x float,
    y float,
    recv_time integer,
    UNIQUE(frame_id, frame_index)
);