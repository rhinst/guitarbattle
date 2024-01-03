-- MySQL dump 8.22
--
-- Host: hinst.net    Database: guitarbattle
---------------------------------------------------------
-- Server version	3.23.52

--
-- Table structure for table 'battle_categories'
--

CREATE TABLE battle_categories (
  id int(11) NOT NULL auto_increment,
  name varchar(255) NOT NULL default '',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'battle_messages'
--

CREATE TABLE battle_messages (
  id int(11) NOT NULL auto_increment,
  battle_id int(11) NOT NULL default '0',
  post_user varchar(255) default NULL,
  message text,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'battle_mp3s'
--

CREATE TABLE battle_mp3s (
  id int(11) NOT NULL auto_increment,
  file_name varchar(255) NOT NULL default '',
  file_type varchar(255) default NULL,
  file_contents longblob,
  file_tab text,
  view_count int(11) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'battle_votes'
--

CREATE TABLE battle_votes (
  id int(11) NOT NULL auto_increment,
  battle_id int(11) NOT NULL default '0',
  voter_id int(11) NOT NULL default '0',
  competitor_id int(11) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'battles'
--

CREATE TABLE battles (
  id int(11) NOT NULL auto_increment,
  timestamp datetime NOT NULL default '0000-00-00 00:00:00',
  parent_category int(11) NOT NULL default '0',
  title_battle tinyint(1) NOT NULL default '0',
  user1 varchar(255) NOT NULL default '',
  user2 varchar(255) default NULL,
  file1 int(11) NOT NULL default '0',
  votes1 int(11) NOT NULL default '0',
  file2 int(11) NOT NULL default '0',
  votes2 int(11) NOT NULL default '0',
  winner varchar(255) default NULL,
  hide tinyint(1) NOT NULL default '0',
  active tinyint(1) NOT NULL default '0',
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
-- Table structure for table 'contacts'
--

CREATE TABLE contacts (
  id int(11) NOT NULL auto_increment,
  company varchar(255) default NULL,
  category varchar(255) default NULL,
  website varchar(255) default NULL,
  contact_name varchar(255) default NULL,
  contact_position varchar(255) default NULL,
  contact_email varchar(255) default NULL,
  contact_phone varchar(255) default NULL,
  notes text,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'counter'
--

CREATE TABLE counter (
  ip_address varchar(255) default NULL,
  hostname varchar(255) default NULL,
  timestamp varchar(255) default NULL,
  hits int(11) NOT NULL default '0'
) TYPE=MyISAM;

--
-- Table structure for table 'links'
--

CREATE TABLE links (
  id int(11) default NULL,
  url varchar(255) default NULL
) TYPE=MyISAM;

--
-- Table structure for table 'logins'
--

CREATE TABLE logins (
  username varchar(255) NOT NULL default '',
  ip_addr varchar(255) default NULL
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
-- Table structure for table 'news'
--

CREATE TABLE news (
  id int(11) NOT NULL auto_increment,
  ts datetime NOT NULL default '0000-00-00 00:00:00',
  news text,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'user_icons'
--

CREATE TABLE user_icons (
  id int(11) NOT NULL auto_increment,
  user_id int(11) NOT NULL default '0',
  file_name varchar(255) default NULL,
  file_type varchar(255) default NULL,
  file_contents longblob,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'user_profiles'
--

CREATE TABLE user_profiles (
  id int(11) NOT NULL auto_increment,
  user_id int(11) NOT NULL default '0',
  image_id int(11) NOT NULL default '0',
  name varchar(255) default NULL,
  nickname varchar(255) default NULL,
  location varchar(255) default NULL,
  influences text,
  occupation varchar(255) default NULL,
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'users'
--

CREATE TABLE users (
  id int(11) NOT NULL auto_increment,
  username varchar(255) NOT NULL default '',
  password varchar(255) NOT NULL default '',
  firstname varchar(255) default NULL,
  lastname varchar(255) default NULL,
  email_address varchar(255) NOT NULL default '',
  privacy tinyint(1) NOT NULL default '0',
  join_date datetime NOT NULL default '0000-00-00 00:00:00',
  last_login varchar(255) default NULL,
  win_percent float(5,2) NOT NULL default '-1.00',
  points int(11) NOT NULL default '0',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

--
-- Table structure for table 'users_temp'
--

CREATE TABLE users_temp (
  id int(11) NOT NULL auto_increment,
  confirm_id varchar(255) default NULL,
  username varchar(255) NOT NULL default '',
  password varchar(255) NOT NULL default '',
  firstname varchar(255) default NULL,
  lastname varchar(255) default NULL,
  email_address varchar(255) NOT NULL default '',
  privacy tinyint(1) NOT NULL default '0',
  join_date datetime NOT NULL default '0000-00-00 00:00:00',
  PRIMARY KEY  (id)
) TYPE=MyISAM;

