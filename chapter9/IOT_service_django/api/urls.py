from django.urls import path 
from api.views import greet

urlpatterns = [
    path('greet/', greet)
]