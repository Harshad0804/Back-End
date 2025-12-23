from django.shortcuts import render, redirect, get_object_or_404
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.models import User
from .models import Post, Comment, Like, Follow, Category
from django.contrib.auth.decorators import login_required

def post_list(request):
    posts = Post.objects.all()
    categories = Category.objects.all()

    category_filter = request.GET.get("category")
    if category_filter:
        posts = posts.filter(category_id=category_filter)

    return render(request, "post_list.html", {"posts": posts, "categories": categories})


def post_detail(request, id):
    post = get_object_or_404(Post, id=id)
    comments = post.comments.all()

    if request.method == "POST":
        Comment.objects.create(
            post=post,
            user=request.user,
            text=request.POST["comment"]
        )
        return redirect("post_detail", id=id)

    return render(request, "post_detail.html", {"post": post, "comments": comments})


@login_required
def create_post(request):
    categories = Category.objects.all()

    if request.method == "POST":
        data = {
            "author": request.user,
            "title": request.POST.get("title", ""),
            "content": request.POST.get("content", ""),
            "category_id": request.POST.get("category") or None,
        }
        if request.FILES.get("cover_image"):
            data["cover_image"] = request.FILES.get("cover_image")
        Post.objects.create(**data)
        return redirect("post_list")

    return render(request, "create_post.html", {"categories": categories})


@login_required
def edit_post(request, id):
    post = get_object_or_404(Post, id=id)

    if request.method == "POST":
        post.title = request.POST["title"]
        post.content = request.POST["content"]
        post.save()
        return redirect("post_detail", id=id)

    return render(request, "edit_post.html", {"post": post})


@login_required
def delete_post(request, id):
    post = get_object_or_404(Post, id=id)
    post.delete()
    return redirect("post_list")


@login_required
def like_post(request, id):
    post = get_object_or_404(Post, id=id)

    like, created = Like.objects.get_or_create(post=post, user=request.user)
    if not created:
        like.delete()

    return redirect("post_detail", id=id)


@login_required
def follow_author(request, id):
    author = User.objects.get(id=id)

    follow, created = Follow.objects.get_or_create(
        follower=request.user,
        followee=author
    )

    if not created:
        follow.delete()

    return redirect("post_list")


def register(request):
    if request.method == "POST":
        User.objects.create_user(
            username=request.POST["username"],
            password=request.POST["password"]
        )
        return redirect("login_user")

    return render(request, "register.html")


def login_user(request):
    if request.method == "POST":
        user = authenticate(
            request,
            username=request.POST["username"],
            password=request.POST["password"]
        )
        if user:
            login(request, user)
            return redirect("post_list")

    return render(request, "login.html")


def logout_user(request):
    logout(request)
    return redirect("login_user")
