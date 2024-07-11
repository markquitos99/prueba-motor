from Proyecto import views
from django.urls import path # type: ignore

urlpatterns = [
    path('', views.probandoTemplate)
]