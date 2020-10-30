"""
A widget that shows the latest posts from Daring Fireball (https://daringfireball.net).
"""

import widgets as wd # For the UI
import json # For parsing the feed
from urllib.request import urlopen # For requesting the feed
from dateutil.parser import parse # For parsing dates
from webbrowser import open # For opening posts
from time import sleep

FOREGROUND_COLOR = wd.COLOR_WHITE
BACKGROUND_GRADIENT = [
    wd.Color.rgb(74/255, 82/255, 90/255),
    wd.Color.rgb(54/255, 62/255, 70/255)
]

FEED_URL = "https://daringfireball.net/feeds/json"

class Article:
    
    def __init__(self, url, title, content, date):
        self.url = url
        self.title = title
        self.content = content.replace("\n", "")
        self.date = date

def get_posts():
    request = urlopen(FEED_URL)
    data = request.read().decode()
    feed = json.loads(data)
    items = feed["items"]
    
    articles = []
    
    for item in items:
        url = item["url"]
        title = item["title"]
        content = item["content_html"]
        date = parse(item["date_published"])
        article = Article(url, title, content, date)
        articles.append(article)
    
    return articles

def add_post(post, layout, link=False):
        
    # If 'line' is 'True', the UI elements will be tappable
    
    if link:
        url = post.url
    else:
        url = None
            
    # Add the title of the post
    layout.add_row([
        wd.Text(
            post.title,
            color=FOREGROUND_COLOR,
            font=wd.Font.bold_system_font_of_size(17),
            padding=wd.Padding(5, 0, 10, 10)
        )
    ], link=url)
    layout.add_vertical_spacer()
    
    # Add the content of the post
    # post.content can contain HTML code
    # HTML code is automatically converted into plain text (no markup)
    layout.add_row([
        wd.Text(post.content,
            color=FOREGROUND_COLOR,
            link=url,
            padding=wd.PADDING_HORIZONTAL
        ),
    ])
    layout.add_vertical_spacer()
    
    # Add the publication date
    layout.add_row([
        wd.Spacer(),
        wd.DynamicDate(
            post.date,
            color=FOREGROUND_COLOR,
            padding=wd.Padding(0, 10, 10, 10)
        )
    ], link=url)
    
    # Set the background color of the widget
    layout.set_background_gradient(BACKGROUND_GRADIENT)

if wd.link is None:

    wd.wait_for_internet_connection()

    posts = get_posts()
    widget = wd.Widget()

    # # # # #
    # Small #
    # # # # #
    
    # Add the post's title
    widget.small_layout.add_row([
        wd.Text(
            posts[0].title,
            color=FOREGROUND_COLOR,
            font=wd.Font.bold_system_font_of_size(17),
            padding=wd.Padding(10, 0, 10, 10)
        )
    ])
    
    # Add the publication date at the bottom
    widget.small_layout.add_vertical_spacer()
    widget.small_layout.add_row([
        wd.DynamicDate(
            posts[0].date,
            color=FOREGROUND_COLOR,
            padding=wd.Padding(0, 5, 0, 0)
        )
    ])
    
    # If the widget is pressed, the post's URL will be passed to the script
    widget.small_layout.set_link(posts[0].url)
    
    # Set the background color of the widget
    widget.small_layout.set_background_gradient(BACKGROUND_GRADIENT)
    
    # # # # # #
    # Medium  #
    # # # # # #
        
    add_post(posts[0], widget.medium_layout)
    
    # If the widget is pressed, the post's URL will be passed to the script
    widget.medium_layout.set_link(posts[0].url)
    
    # # # # #
    # Large #
    # # # # #
    
    for i in range(3):
        # Setting the third parameter to 'True' will make individual elements tappable
        add_post(posts[i], widget.large_layout, True)
        if i < 2:
            widget.large_layout.add_vertical_divider()
    
    # # # # #
    # Show  #
    # # # # #
    
    # Don't reload before five hours
    wd.schedule_next_reload(60*60*5)
    wd.show_widget(widget)

else:
    # Open the article with the default web browser
    
    open(wd.link)
