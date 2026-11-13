using System.Security.Claims;
using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using lab_9.Models;

namespace lab_9.Controllers;

public class AccountController : Controller
{
    [AllowAnonymous]
    public IActionResult Login(string? returnUrl = null)
    {
        ViewData["ReturnUrl"] = returnUrl;
        return View();
    }

    [HttpPost]
    [AllowAnonymous]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Login(LoginViewModel model, string? returnUrl = null)
    {
        if (!ModelState.IsValid)
        {
            ViewData["ReturnUrl"] = returnUrl;
            return View(model);
        }

        if (!model.Username.Equals("user", StringComparison.OrdinalIgnoreCase) ||
            model.Password != "user123")
        {
            ModelState.AddModelError(string.Empty, "Invalid username or password.");
            ViewData["ReturnUrl"] = returnUrl;
            return View(model);
        }

        var claims = new[]
        {
            new Claim(ClaimTypes.Name, model.Username)
        };
        var identity = new ClaimsIdentity(
            claims,
            CookieAuthenticationDefaults.AuthenticationScheme);
        var properties = new AuthenticationProperties
        {
            IsPersistent = true,
            ExpiresUtc = DateTimeOffset.UtcNow.AddDays(5),
            AllowRefresh = false
        };

        await HttpContext.SignInAsync(
            CookieAuthenticationDefaults.AuthenticationScheme,
            new ClaimsPrincipal(identity),
            properties);

        if (Url.IsLocalUrl(returnUrl))
        {
            return Redirect(returnUrl);
        }

        return RedirectToAction(nameof(HomeController.Dashboard), "Home");
    }

    [HttpPost]
    [Authorize]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Logout()
    {
        await HttpContext.SignOutAsync(CookieAuthenticationDefaults.AuthenticationScheme);
        return RedirectToAction(nameof(HomeController.Index), "Home");
    }

    [AllowAnonymous]
    public IActionResult AccessDenied()
    {
        return View();
    }
}
