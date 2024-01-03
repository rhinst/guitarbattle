-- MySQL dump 8.22
--
-- Host: hinst.net    Database: gb_new
---------------------------------------------------------
-- Server version	3.23.52

--
-- Table structure for table 'backings'
--

CREATE TABLE backings (
  id int(11) NOT NULL auto_increment,
  mp3_id int(11) NOT NULL default '0',
  name varchar(255) NOT NULL default '',
  description text,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'battles'
--

CREATE TABLE battles (
  id int(11) NOT NULL auto_increment,
  user1 varchar(32) NOT NULL default '',
  collab1 varchar(32) NOT NULL default '',
  collab1_confirmed tinyint(1) NOT NULL default '0',
  user2 varchar(32) NOT NULL default '',
  collab2 varchar(32) NOT NULL default '',
  collab2_confirmed tinyint(1) NOT NULL default '0',
  challenger varchar(32) NOT NULL default '',
  backing int(11) NOT NULL default '0',
  timestamp datetime NOT NULL default '0000-00-00 00:00:00',
  genre int(11) NOT NULL default '0',
  file1 int(11) NOT NULL default '0',
  score1 float(5,3) NOT NULL default '0.000',
  file2 int(11) NOT NULL default '0',
  score2 float(5,3) NOT NULL default '0.000',
  winner varchar(32) NOT NULL default '',
  active tinyint(4) NOT NULL default '0',
  hide tinyint(4) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'battles_temp'
--

CREATE TABLE battles_temp (
  id int(11) NOT NULL auto_increment,
  user1 varchar(32) NOT NULL default '',
  collab1 varchar(32) NOT NULL default '',
  collab1_confirmed tinyint(1) NOT NULL default '0',
  user2 varchar(32) NOT NULL default '',
  collab2 varchar(32) NOT NULL default '',
  collab2_confirmed tinyint(1) NOT NULL default '0',
  challenger varchar(32) NOT NULL default '',
  backing int(11) NOT NULL default '0',
  timestamp datetime NOT NULL default '0000-00-00 00:00:00',
  genre int(11) NOT NULL default '0',
  file1 int(11) NOT NULL default '0',
  score1 float(5,3) NOT NULL default '0.000',
  file2 int(11) NOT NULL default '0',
  score2 float(5,3) NOT NULL default '0.000',
  winner varchar(32) NOT NULL default '',
  active tinyint(4) NOT NULL default '0',
  hide tinyint(4) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'boards'
--

CREATE TABLE boards (
  id int(11) NOT NULL auto_increment,
  board_table varchar(255) NOT NULL default '',
  board_name varchar(255) NOT NULL default '',
  board_description text,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'comments'
--

CREATE TABLE comments (
  id int(11) NOT NULL auto_increment,
  battle_id int(11) NOT NULL default '0',
  username varchar(255) NOT NULL default '',
  comment text NOT NULL,
  timestamp timestamp(14) NOT NULL,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'compilations'
--

CREATE TABLE compilations (
  id int(11) NOT NULL auto_increment,
  fn varchar(255) NOT NULL default '',
  ln varchar(255) NOT NULL default '',
  address varchar(255) NOT NULL default '',
  city varchar(255) NOT NULL default '',
  state varchar(255) NOT NULL default '',
  province varchar(255) NOT NULL default '',
  zip varchar(255) NOT NULL default '',
  country varchar(255) NOT NULL default '',
  phone varchar(255) NOT NULL default '',
  email varchar(255) NOT NULL default '',
  status varchar(255) NOT NULL default '',
  order_date datetime NOT NULL default '0000-00-00 00:00:00',
  payment_date datetime NOT NULL default '0000-00-00 00:00:00',
  creation_date datetime NOT NULL default '0000-00-00 00:00:00',
  ship_date datetime NOT NULL default '0000-00-00 00:00:00',
  payment_confirmed_by varchar(255) NOT NULL default '',
  created_by varchar(255) NOT NULL default '',
  shipped_by varchar(255) NOT NULL default '',
  notes text NOT NULL,
  amount_paid float(8,2) NOT NULL default '0.00',
  quantity int(11) NOT NULL default '0',
  transaction_id varchar(255) NOT NULL default '',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'decisions'
--

CREATE TABLE decisions (
  id int(11) NOT NULL auto_increment,
  battle_id int(11) NOT NULL default '0',
  judge varchar(255) NOT NULL default '',
  competitor varchar(255) NOT NULL default '',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'genres'
--

CREATE TABLE genres (
  id int(11) NOT NULL auto_increment,
  name varchar(255) NOT NULL default '',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'images'
--

CREATE TABLE images (
  id int(11) NOT NULL auto_increment,
  file_type varchar(255) NOT NULL default '',
  file_contents longblob,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'links'
--

CREATE TABLE links (
  id int(11) NOT NULL auto_increment,
  link varchar(255) NOT NULL default '',
  name varchar(255) NOT NULL default '',
  description text,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'logins'
--

CREATE TABLE logins (
  username varchar(32) NOT NULL default '',
  ip_addr varchar(255) NOT NULL default '',
  login_ts datetime NOT NULL default '0000-00-00 00:00:00',
  last_active datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (username)
) TYPE=MyISAM;

--
-- Table structure for table 'mboard_comments'
--

CREATE TABLE mboard_comments (
  id int(11) NOT NULL auto_increment,
  parent int(11) NOT NULL default '0',
  user varchar(255) NOT NULL default '',
  user_id int(11) NOT NULL default '0',
  subject varchar(255) NOT NULL default '',
  body text,
  views int(11) NOT NULL default '0',
  timestamp datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'mboard_gear'
--

CREATE TABLE mboard_gear (
  id int(11) NOT NULL auto_increment,
  parent int(11) NOT NULL default '0',
  user varchar(255) NOT NULL default '',
  user_id int(11) NOT NULL default '0',
  subject varchar(255) NOT NULL default '',
  body text,
  views int(11) NOT NULL default '0',
  timestamp datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'mboard_general'
--

CREATE TABLE mboard_general (
  id int(11) NOT NULL auto_increment,
  parent int(11) NOT NULL default '0',
  user varchar(255) NOT NULL default '',
  user_id int(11) NOT NULL default '0',
  subject varchar(255) NOT NULL default '',
  body text,
  views int(11) NOT NULL default '0',
  timestamp datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'messages'
--

CREATE TABLE messages (
  id int(11) NOT NULL auto_increment,
  timestamp timestamp(14) NOT NULL,
  from_user varchar(32) NOT NULL default '',
  to_user varchar(32) NOT NULL default '',
  subject varchar(255) default NULL,
  body text,
  new tinyint(1) NOT NULL default '1',
  unread tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'mp3s'
--

CREATE TABLE mp3s (
  id int(11) NOT NULL auto_increment,
  id_battle int(11) NOT NULL default '0',
  username varchar(255) NOT NULL default '',
  collab varchar(255) NOT NULL default '',
  file_name varchar(255) NOT NULL default '',
  file_type varchar(255) NOT NULL default '',
  file_size int(11) NOT NULL default '0',
  file_contents longblob NOT NULL,
  song_name varchar(255) NOT NULL default '',
  notes text NOT NULL,
  views int(11) NOT NULL default '0',
  mpeg_version char(3) default NULL,
  mpeg_layer char(1) default NULL,
  bitrate int(4) NOT NULL default '0',
  sample_rate int(6) NOT NULL default '0',
  channel_mode varchar(32) NOT NULL default '',
  genre int(11) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'news'
--

CREATE TABLE news (
  id int(11) NOT NULL auto_increment,
  title varchar(255) NOT NULL default '',
  timestamp timestamp(14) NOT NULL,
  posted_by varchar(255) NOT NULL default '',
  contents text NOT NULL,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'poll_answers'
--

CREATE TABLE poll_answers (
  id int(11) NOT NULL auto_increment,
  poll_id int(11) NOT NULL default '0',
  username varchar(255) NOT NULL default '',
  choice int(2) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'poll_questions'
--

CREATE TABLE poll_questions (
  id int(11) NOT NULL auto_increment,
  date datetime NOT NULL default '0000-00-00 00:00:00',
  question text NOT NULL,
  answer_0 varchar(255) default NULL,
  answer_1 varchar(255) default NULL,
  answer_2 varchar(255) default NULL,
  answer_3 varchar(255) default NULL,
  active tinyint(1) NOT NULL default '0',
  votes_0 int(11) NOT NULL default '0',
  votes_1 int(11) NOT NULL default '0',
  votes_2 int(11) NOT NULL default '0',
  votes_3 int(11) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'preferences'
--

CREATE TABLE preferences (
  username varchar(32) NOT NULL default '',
  popup_player tinyint(1) NOT NULL default '0',
  embed_chat tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (username)
) TYPE=MyISAM;

--
-- Table structure for table 'profiles'
--

CREATE TABLE profiles (
  username varchar(32) NOT NULL default '',
  icon int(11) NOT NULL default '0',
  name varchar(255) default NULL,
  age varchar(255) default NULL,
  gender enum('Male','Female','Not Specified') default 'Not Specified',
  influences text,
  gear varchar(255) default NULL,
  location varchar(255) default NULL,
  occupation varchar(255) default NULL,
  eml varchar(255) default NULL,
  website varchar(255) default NULL,
  how_long varchar(255) default NULL,
  PRIMARY KEY  (username)
) TYPE=MyISAM;

--
-- Table structure for table 'ranks'
--

CREATE TABLE ranks (
  id int(11) NOT NULL auto_increment,
  name varchar(255) NOT NULL default '',
  num_battles int(11) NOT NULL default '0',
  score float(5,3) NOT NULL default '0.000',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'todo'
--

CREATE TABLE todo (
  id int(11) NOT NULL auto_increment,
  item text NOT NULL,
  open tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'track_lists'
--

CREATE TABLE track_lists (
  compilation_id int(11) NOT NULL default '0',
  mp3_id int(11) NOT NULL default '0',
  track_length int(11) NOT NULL default '0',
  song_name varchar(255) NOT NULL default '',
  username varchar(32) NOT NULL default '',
  collab varchar(32) NOT NULL default '',
  genre int(11) NOT NULL default '0',
  track_number int(11) NOT NULL default '0',
  PRIMARY KEY  (compilation_id,mp3_id)
) TYPE=MyISAM;

--
-- Table structure for table 'users'
--

CREATE TABLE users (
  username varchar(32) NOT NULL default '',
  password varchar(255) NOT NULL default '',
  eml_addr varchar(255) NOT NULL default '',
  grp int(11) NOT NULL default '0',
  mod tinyint(4) NOT NULL default '0',
  fn varchar(255) NOT NULL default '',
  ln varchar(255) NOT NULL default '',
  address varchar(255) NOT NULL default '',
  city varchar(255) NOT NULL default '',
  state varchar(255) NOT NULL default '',
  province varchar(255) NOT NULL default '',
  zip varchar(255) NOT NULL default '',
  country varchar(255) NOT NULL default '',
  telephone varchar(255) NOT NULL default '',
  rank varchar(255) NOT NULL default '',
  public tinyint(4) NOT NULL default '0',
  join_date datetime NOT NULL default '0000-00-00 00:00:00',
  ip_addr varchar(255) NOT NULL default '',
  score_sum float(5,2) NOT NULL default '0.00',
  num_battles int(11) NOT NULL default '0',
  num_wins int(11) NOT NULL default '0',
  vote_bank int(11) NOT NULL default '0',
  judge tinyint(1) NOT NULL default '0',
  alt_judge tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (username)
) TYPE=MyISAM;

--
-- Table structure for table 'users_temp'
--

CREATE TABLE users_temp (
  username varchar(32) NOT NULL default '',
  password varchar(255) NOT NULL default '',
  eml_addr varchar(255) NOT NULL default '',
  grp int(11) NOT NULL default '0',
  mod tinyint(4) NOT NULL default '0',
  fn varchar(255) NOT NULL default '',
  ln varchar(255) NOT NULL default '',
  address varchar(255) NOT NULL default '',
  city varchar(255) NOT NULL default '',
  state varchar(255) NOT NULL default '',
  zip varchar(255) NOT NULL default '',
  country varchar(255) NOT NULL default '',
  telephone varchar(255) NOT NULL default '',
  public tinyint(4) NOT NULL default '0',
  join_date datetime NOT NULL default '0000-00-00 00:00:00',
  ip_addr varchar(255) NOT NULL default '',
  confirm_id varchar(255) NOT NULL default '',
  PRIMARY KEY  (username)
) TYPE=MyISAM;

--
-- Table structure for table 'votes'
--

CREATE TABLE votes (
  battle_id int(11) NOT NULL default '0',
  voter varchar(32) NOT NULL default '',
  competitor varchar(32) NOT NULL default '',
  cat_1 int(11) NOT NULL default '0',
  cat_9 int(11) NOT NULL default '0',
  cat_8 int(11) NOT NULL default '0',
  cat_10 int(11) NOT NULL default '0',
  cat_11 int(11) NOT NULL default '0',
  cat_12 int(11) NOT NULL default '0',
  PRIMARY KEY  (battle_id,voter,competitor)
) TYPE=MyISAM;

--
-- Table structure for table 'voting_categories'
--

CREATE TABLE voting_categories (
  id int(11) NOT NULL auto_increment,
  name varchar(255) NOT NULL default '',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

